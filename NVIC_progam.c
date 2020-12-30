/********************************/
/* Author    : Ragy             */
/* Date      : 25 AUGUST 2020   */
/* Version   : V01              */
/********************************/

#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "NVIC_interface.h"
#include "NVIC_private.h"
#include "NVIC_config.h"



void MNVIC_voidEnableInterrupt	(u8	Copy_u8IntNumber)
{
	if(Copy_u8IntNumber <= 31)
	{
		NVIC_ISER0 = 1 << Copy_u8IntNumber;
		/* 	ana hena mst5dmtsh set bit 3shan ba5od 3 instruction w al fo2 dh btst5dm 2 bs 
			bs azay ana kda mmken abwz al interrupt al tanya al 3mltlha ====> dh msh hy7sl 
			3shan lma b7ot 0 3ala al Register dh has no effect */
	}
	else if(Copy_u8IntNumber <= 59)
	{
		Copy_u8IntNumber -= 32;
		NVIC_ISER0 = 1 << Copy_u8IntNumber;
	}
	else
	{
		// Return error
	}
	
}


void MNVIC_voidDisableInterrupt	(u8	Copy_u8IntNumber)
{
	if(Copy_u8IntNumber <= 31)
	{
		NVIC_ICER0 = 1 << Copy_u8IntNumber;
	}
	else if(Copy_u8IntNumber <= 59)
	{
		Copy_u8IntNumber -= 32;
		NVIC_ICER1 = 1 << Copy_u8IntNumber;
	}
	else
	{
		// Return error
	}
	
}


void MNVIC_voidSetPendingFlag	(u8	Copy_u8IntNumber)
{
	if(Copy_u8IntNumber <= 31)
	{
		NVIC_ISPR0 = 1 << Copy_u8IntNumber;
	}
	else if(Copy_u8IntNumber <= 59)
	{
		Copy_u8IntNumber -= 32;
		NVIC_ISPR1 = 1 << Copy_u8IntNumber;
	}
	else
	{
		// Return error
	}
	
}


void MNVIC_voidClearPendingFlag	(u8	Copy_u8IntNumber)
{
	if(Copy_u8IntNumber <= 31)
	{
		NVIC_ICPR0 = 1 << Copy_u8IntNumber;
	}
	else if(Copy_u8IntNumber <= 59)
	{
		Copy_u8IntNumber -= 32;
		NVIC_ICPR1 = 1 << Copy_u8IntNumber;
	}
	else
	{
		// Return error
	}
	
}



u8 MNVIC_voidGetActiveFlag	(u8	Copy_u8IntNumber)
{
	u8 Local_u8Result = 0;
	if(Copy_u8IntNumber <= 31)
	{
		Local_u8Result = GET_BIT(NVIC_IABR0,Copy_u8IntNumber);
	}
	else if(Copy_u8IntNumber <= 59)
	{
		Copy_u8IntNumber -= 32;
		Local_u8Result = GET_BIT(NVIC_IABR1,Copy_u8IntNumber);
	}
	else
	{
		// Return error
	}
	
	return Local_u8Result;
}


/*	al func dh ana b7ot beha al priority bta3t interrupt mo3yn al group prioity w al subgroup priority
	bdy al func rkm al interrupt w al group prioity w subgroup priority w 22olha sha3'ala b 
	anhy group system (al hwa f kam group w kam subgroup f al system)  */
void MNVIC_voidSetPriority(s8 Copy_s8IntID , u8 Copy_u8GroupPriority , u8 Copy_u8SubPriority , u32 Copy_u32Group)
{
	u8 Local_u8Priority = Copy_u8SubPriority|(Copy_u8GroupPriority<<((Copy_u32Group - 0x05FA0300)/256));
	/* Core Peripheral*/
	
	
	/* external peripheral*/
	if(Copy_s8IntID >= 0)
	{
		NVIC_IPR[Copy_s8IntID] = Local_u8Priority << 4;
	}
	
	SCB_AIRCR = Copy_u32Group;

}

/*void MNVIC_voidInit(void)
{
	SCB_AIRCR = MNVIC_GROUP_SUB_DISTRIBUTION;
}



void MNVIC_voidSetPriority(u8 Copy_PeriperalIdx , u8 Copy_u8Priority)
{
	if (Copy_PeriperalIdx < 60)
	{
		NVIC_IPR[Copy_PeriperalIdx] = Copy_u8Priority;
	}	
	else
	{
		// report error
	}
	
}*/

