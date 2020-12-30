/********************************/
/* Author    : Ragy             */
/* Date      : 27 AUGUST 2020   */
/* Version   : V01              */
/********************************/

#ifndef STK_INTERFACE_H
#define STK_INTERFACE_H


void MSTK_voidInit(void);

void MSTK_voidSetBusyWait(u32 Copy_u32Ticks);

void MSTK_voidSetIntervalSingle(u32 Copy_u32Ticks , void (*Copy_ptr)(void) );

void MSTK_voidSetIntervalPeriodic(u32 Copy_u32Ticks , void (*Copy_ptr)(void) );

void MSTK_voidStopInterval(void);

u32 MSTK_u32GetElapsedTime(void);

u32 MSTK_u32GetRemainingTime(void);


#endif