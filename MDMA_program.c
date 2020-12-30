#include "STD_TYPES.h"
#include "BIT_MATH.h"


#include "MDMA_interface.h"
#include "MDMA_private.h"
#include "MDMA_config.h"

void MDMA_voidChannelInit(void)
{
	/*  1- memory to memory 
		2- pri : very high 
		3- source size , destination size = 32 bit 
		4- MINC  PINC  activated 
		5- no circular 
		6- direction : 
		7- interrupt transfer enable
		
	*/
	#if CHANNEL_ID == 1 
		DMA -> Channel[0].CCR = 

	
}




void MDMA_voidChannelStart(u32 * Copy_Pu32SourceAddress, u32 * Copy_Pu32DestinationAddress, u16 Copy_u16BlockLength)
{
	// Make sure channel is disabled
	CLR_BIT(DMA->Channel[0].CCR ,0);
	
	//write address
	DMA->Channel[0].CPAR = Copy_Pu32SourceAddress;
	DMA->Channel[0].CMAR = Copy_Pu32DestinationAddress;
	
	// block length 
	DMA->Channel[0].CNDTR = Copy_u16BlockLength;
	
	// Enable Channel 
	SET_BIT(DMA->Channel[0].CCR ,0);
	
}




