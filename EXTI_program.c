/********************************/
/* Author    : Ragy             */
/* Date      : 26 AUGUST 2020   */
/* Version   : V01              */
/********************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "EXTI_interface.h"
#include "EXTI_config.h"
#include "EXTI_private.h"


void MEXTI_voidInit()
{
	#if EXTI_MODE == RISING
		SET_BIT(EXTI->RTSR  , EXTI_LINE);
	#elif EXTI_MODE == FALLING
		SET_BIT(EXTI->FTSR  , EXTI_LINE);
	#elif EXTI_MODE == ONCHANGE
		SET_BIT(EXTI->RTSR  , EXTI_LINE);
		SET_BIT(EXTI->FTSR  , EXTI_LINE);
	#else 
		#error "Wrong Mode and Line Choice"
	#endif
	
	/* Disable Interrupt */
	CLR_BIT(EXTI->IMR , Copy_u8Line);

/*	#if EXTI_LINE == LINE0
		SET_BIT(EXTI->IMR , LiNE0);
	#elif EXTI_LINE == LINE1
		SET_BIT(EXTI->IMR , LINE1);
	#elif EXTI_LINE == LINE2
		SET_BIT(EXTI->IMR , LINE2);
	#else 
		#error "Wrong Line Choice"
	#endif */

	
}

void MEXTI_voidEnableEXTI(u8 Copy_u8Line)
{
	SET_BIT(EXTI->IMR , Copy_u8Line);
}



void MEXTI_voidDisableEXTI(u8 Copy_u8Line)
{
	CLR_BIT(EXTI->IMR , Copy_u8Line);
}




void MEXTI_voidSwTrigger(u8 Copy_u8Line)
{
	SET_BIT(EXTI->SWIER , Copy_u8Line);
}


/* Set Mode for certain External Interrupt */
void MEXTI_voidSetSignalLatch(u8 Copy_u8Line , u8 Copy_u8Mode)
{
	switch(Copy_u8Mode)
	{
		case RISING:
			SET_BIT(EXTI->RTSR  , EXTI_LINE);
			break;
		case FALLING:
			SET_BIT(EXTI->FTSR  , EXTI_LINE);
			break;
		case ONCHANGE:
			SET_BIT(EXTI->RTSR  , EXTI_LINE);
			SET_BIT(EXTI->FTSR  , EXTI_LINE);
			break; 
	}
	// Enable Ext INT 
	SET_BIT(EXTI->IMR,Copy_u8Line);
}

static void (* EXTI0_CallBack)(void) = NULL;

void MEXTI_voidSetcallBack(void (*ptr)(void))
{
	EXTI0_CallBack = ptr;
}


void EXTI0_IRQHandler(void)
{
	EXTI0_CallBack();
}

