/********************************/
/* Author    : Ragy             */
/* Date      : 27 AUGUST 2020   */
/* Version   : V01              */
/********************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "STK_interface.h"
#include "STK_config.h"
#include "STK_private.h"


void (*Systick_Callback)(void);

/* 	Apply clock choice from config file 
	Disable Systick interrupt
	Disable Systick */
void MSTK_voidInit(void)
{
	STK->CTRL = STK_CLOCK_CONFIG;
}


void MSTK_voidSetBusyWait(u32 Copy_u32Ticks)
{
	//// SYNC FUNC
	
	STK->LOAD = Copy_u32Ticks;
	// Enable systick
	SET_BIT(STK->CTRL,STK_ENABLE_BIT);
	// loop on the flag to get out the func
	while(GET_BIT(STK->CTRL,STK_FLAG_BIT) == 0);
		/* Stop Timer */
	CLR_BIT(MSTK->CTRL, STK_ENABLE_BIT);
	MSTK -> LOAD = 0;
	MSTK -> VAL  = 0;
}

void MSTK_voidSetIntervalSingle(u32 Copy_u32Ticks , void (*Copy_ptr)(void) )
{
	//// ASYNC FUNC
	
	STK->LOAD = Copy_u32Ticks;
	
	// Enable Interrupt and systick
	SET_BIT(STK->CTRL,STK_ENABLE_BIT);
	SET_BIT(STK->CTRL,STK_INT_BIT);
	
	Systick_Callback = Copy_ptr;

	/* how to stop after one interval load = value = 0 */
	MSTK_voidStopInterval();
}


void MSTK_voidSetIntervalPeriodic(u32 Copy_u32Ticks , void (*Copy_ptr)(void) )
{
	//// ASYNC FUNC
	
	STK->LOAD = Copy_u32Ticks;
	
	// Enable Interrupt and systick
	SET_BIT(STK->CTRL,STK_ENABLE_BIT);
	SET_BIT(STK->CTRL,STK_INT_BIT);
	
	Systick_Callback = Copy_ptr;
}


void MSTK_voidStopInterval(void)
{
	STK->LOAD = 0;
	STK->VAL  = 0;
	
	// disable Interrupt
	CLR_BIT(STK->CTRL,STK_INT_BIT);
}


u32 MSTK_u32GetElapsedTime(void)
{
	u32 Local_u32Time = 0;
	
	Local_u32Time = STK->LOAD - STK->VAL;
	
	return Local_u32Time;
}


u32 MSTK_u32GetRemainingTime(void)
{
	u32 Local_u32Time = 0;
	
	Local_u32Time = STK->VAL;
	
	return Local_u32Time;	
}



// Systick ISR
void SysTick_Handler(void)
{
	Systick_Callback();
}





