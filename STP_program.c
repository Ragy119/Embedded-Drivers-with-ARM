#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "STK_interface.h"

#include "STP_interface.h"
#include "STP_private.h"
#include "STP_config.h"


void HSTP_voidSendSynchronus(u8 Copy_u8DataToSend)
{
	s8 Local_u8Counter;
	u8 Local_u8Bit;
	// Send bit by bit starting from MSB 
	for(Local_u8Counter = 7; Local_u8Counter >= 0; Local_u8Counter--)
	{
		Local_u8Bit = GET_BIT(Copy_u8DataToSend,Local_u8Counter);
		MGPIO_voidSetPinValue(HSTP_SERIAL_DATA,Local_u8Bit);
		
		// send pulse to shift clock
		MGPIO_voidSetPinValue(HSTP_SHIFT_CLOCK,HIGH);
		MSTK_voidSetBusyWait(1);
		MGPIO_voidSetPinValue(HSTP_SHIFT_CLOCK,LOW);
		MSTK_voidSetBusyWait(1);		
		
	}
	
	// send pulse to store clock
	MGPIO_voidSetPinValue(HSTP_STORE_CLOCK,HIGH);
	MSTK_voidSetBusyWait(1);
	MGPIO_voidSetPinValue(HSTP_STORE_CLOCK,LOW);
	MSTK_voidSetBusyWait(1);
	
}


