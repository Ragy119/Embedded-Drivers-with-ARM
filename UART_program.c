#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "STK_interface.h"

#include "UART_interface.h"
#include "UART_private.h"
#include "UART_config.h"

void MUSART1_voidInit(void)
{
	// 9600 BRR=0x341
	MUSART1->BRR = 0x341;
	// 115200 BRR=0x 
	
	/*
	Enable Rx
	Enable Tx
	Enable USART
	*/
	SET_BIT(MUSART1->CR1, 2);
	SET_BIT(MUSART1->CR1, 3);
	SET_BIT(MUSART1->CR1, 13);
	// Clear Status Reg
	MUSART1->SR = 0;
}


void MUSART1_voidTransmit(u8 arr[])
{
	u8 i = 0;
	while(arr[i] != '\0')
	{
		MUSART1->DR = arr[i];
		//wait till transmit is complete
		//while((GET_BIT(MUSART1->SR, 6) == 0));
		while(((MUSART1->SR) & 0x40) == 0);
		i++;
		
	}
	
}



u8	 MUSART1_u8Receive(void)
{
	while(((MUSART1->SR) & 1 << 5 ) == 0);
	// FF for casting 16 bit only 
	return (0xFF & (MUSART1->DR));
}