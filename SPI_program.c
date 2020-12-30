#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "STK_interface.h"

#include "SPI_interface.h"
#include "SPI_private.h"
#include "SPI_config.h"

void MSPI1_voidSendReceiveSynch(u8 Copy_u8DataToTrasmit, u8 *Copy_DataToReceive)
{
	// Clear for slave select pin
	MGPIO_voidSetPinValue(MSPI1_SLAVE_PIN,LOW);
	
	//Send Data
	MSPI1->DR = Copy_u8DataToTrasmit;
	
	//Wait busy flag to finish
	while(GET_BIT(MSPI1->SR, 7)==1);
	
	//Return to the receive data
	*Copy_DataToReceive = MSPI1->DR;

	// Set for slave select pin
	MGPIO_voidSetPinValue(MSPI1_SLAVE_PIN,HIGH);	
	
}






