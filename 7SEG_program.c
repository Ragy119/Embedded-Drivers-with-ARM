/*********************************/
/* Author : Ragy                 */
/* Version: V01                  */
/* Date   : 14 August 2020       */
/*********************************/


#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"

#include "7SEG_interface.h"
#include "7SEG_private.h"
#include "7SEG_config.h"



void SEG_voidDisplay(u8 copy_u8Commen, u8 copy_u8Number)
{	
	// Set Pins directions
	MGPIO_voidSetPinDirection(7SEG_PORT, 7SEG_PIN0, OUTPUT_SPEED_10MHZ_PP);
	MGPIO_voidSetPinDirection(7SEG_PORT, 7SEG_PIN1, OUTPUT_SPEED_10MHZ_PP);
	MGPIO_voidSetPinDirection(7SEG_PORT, 7SEG_PIN2, OUTPUT_SPEED_10MHZ_PP);
	MGPIO_voidSetPinDirection(7SEG_PORT, 7SEG_PIN3, OUTPUT_SPEED_10MHZ_PP);
	MGPIO_voidSetPinDirection(7SEG_PORT, 7SEG_PIN4, OUTPUT_SPEED_10MHZ_PP);
	MGPIO_voidSetPinDirection(7SEG_PORT, 7SEG_PIN5, OUTPUT_SPEED_10MHZ_PP);
	MGPIO_voidSetPinDirection(7SEG_PORT, 7SEG_PIN6, OUTPUT_SPEED_10MHZ_PP);
	MGPIO_voidSetPinDirection(7SEG_PORT, 7SEG_PIN7, OUTPUT_SPEED_10MHZ_PP);
	MGPIO_voidSetPinDirection(7SEG_PORT, 7SEG_PIN8, OUTPUT_SPEED_10MHZ_PP);
	
	u8 SEG_NUMBER[10]={0xBF,0x86,0xdb,0xcf,0xe6,0xed,0xfd,0x87,0xff,0xef};
	
	switch(copy_u8Commen)
	{
		case CATHOD:
					copy_u8Number =   SEG_NUMBER[copy_u8Number];
					break;
		case ANODE:
					copy_u8Number = ~ SEG_NUMBER[copy_u8Number];
					break;
		default:	break;
	}
	
	// Set or Clr these Pins 
	MGPIO_voidSetPinValue(7SEG_PORT , 7SEG_PIN0 , GET_BIT(copy_u8Number,0));
	MGPIO_voidSetPinValue(7SEG_PORT , 7SEG_PIN1 , GET_BIT(copy_u8Number,1));
	MGPIO_voidSetPinValue(7SEG_PORT , 7SEG_PIN2 , GET_BIT(copy_u8Number,2));
	MGPIO_voidSetPinValue(7SEG_PORT , 7SEG_PIN3 , GET_BIT(copy_u8Number,3));
	MGPIO_voidSetPinValue(7SEG_PORT , 7SEG_PIN4 , GET_BIT(copy_u8Number,4));
	MGPIO_voidSetPinValue(7SEG_PORT , 7SEG_PIN5 , GET_BIT(copy_u8Number,5));
	MGPIO_voidSetPinValue(7SEG_PORT , 7SEG_PIN6 , GET_BIT(copy_u8Number,6));
	MGPIO_voidSetPinValue(7SEG_PORT , 7SEG_PIN7 , GET_BIT(copy_u8Number,7));
	MGPIO_voidSetPinValue(7SEG_PORT , 7SEG_PIN8 , GET_BIT(copy_u8Number,8));
	
}
