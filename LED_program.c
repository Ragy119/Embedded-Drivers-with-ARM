/*********************************/
/* Author : Ragy                 */
/* Version: V01                  */
/* Date   : 14 August 2020       */
/*********************************/


#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"

#include "LED_interface.h"
#include "LED_private.h"
#include "LED_config.h"



void LED_voidLedOn (u8 copy_u8Port, u8 copy_u8Pin)
{
	//MGPIO_voidSetPinDirection(copy_u8Port, copy_u8Pin , OUTPUT_SPEED_10MHZ_PP);

	MGPIO_voidSetPinValue( copy_u8Port,  copy_u8Pin , HIGH);
}

void LED_voidLedOff (u8 copy_u8Port, u8 copy_u8Pin)
{
	//MGPIO_voidSetPinDirection(copy_u8Port, copy_u8Pin , OUTPUT_SPEED_10MHZ_PP);

	MGPIO_voidSetPinValue( copy_u8Port,  copy_u8Pin , LOW);
}

void LED_voidLedToggle (u8 copy_u8Port, u8 copy_u8Pin)
{
	u16 w=500;
	//MGPIO_voidSetPinDirection(copy_u8Port, copy_u8Pin , OUTPUT_SPEED_10MHZ_PP);

	MGPIO_voidSetPinValue( copy_u8Port,  copy_u8Pin , HIGH);
	
	for(u16 i=0;i<w;i++)
	{
		for(u16 j=0;j<w;j++)
		{
			asm("NOP");
		}
	}
	
	MGPIO_voidSetPinValue( copy_u8Port,  copy_u8Pin , LOW);
	
	for(u16 i=0;i<w;i++)
	{
		for(u16 j=0;j<w;j++)
		{
			asm("NOP");
		}
	}
	
	
	
	
	
}