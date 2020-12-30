/********************************/
/* Author    : Ragy             */
/* Date      : 26 AUGUST 2020   */
/* Version   : V01              */
/********************************/


#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "AFIO_interface.h"
#include "AFIO_config.h"
#include "AFIO_private.h"


void MAFIO_voidSetEXTIConfig(u8 Copy_u8Line , u8 Copy_u8PortMap)
{
	u8 Local_u8RegIndex = 0;
	
	if(Copy_u8Line <= 3)
	{
		Local_u8RegIndex =0;
	}
	else if(Copy_u8Line <= 7)
	{
		Local_u8RegIndex = 1;
		Copy_u8Line -= 4;
	}
	else if(Copy_u8Line <= 11)
	{
		Local_u8RegIndex = 2;
		Copy_u8Line -= 8;
	}
	else if(Copy_u8Line <= 15)
	{
		Local_u8RegIndex = 3;
		Copy_u8Line -= 12; 
	}

	// Local_u8RegIndex Copy_u8Line/4;
	// Copy_u8Line = Copy_u8Line%4;
	
		
	// to reset the pins before writing the value
	AFIO->EXTICR[Local_u8RegIndex] &= ~((0b1111) << (Copy_u8Line * 4));
	// to set the value 
	AFIO->EXTICR[Local_u8RegIndex] |= ((Copy_u8PortMap) << (Copy_u8Line * 4));
}

