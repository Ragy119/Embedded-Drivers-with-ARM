#include "STD_types.h"
#include "BIT_MATH.h"

#include "UART_interface.h"


void ESP_voidInit(void)
{
	u8 Local_u8Result =0;
	
	while(Local_u8Result == 0)
	{
		//stop ECHO
		MUSART1_voidTransmit("ATE0\r\n");
		Local_u8Result = voidEspValidateCmd();
	}

	Local_u8Result = 0;
	while(Local_u8Result == 0)
	{
		// Set station mode
		MUSART1_voidTransmit("AT+CWMODE=1\r\n");
			
	}
	
}



u8 voidEspValidateCmd(void)
{
	u8 Local_u8Response[100] = {0};
	u8 i=0;
	u8 Dummy = 0;
	u8 Result = 0;
	
	
	while(Dummy != 255)
	{
		Dummy = MUSART1_u8Receive();
		Local_u8Response[i] = Dummy;
		i++;
	}
	
	// Check if OK
	while(Local_u8Response[0] == 'O' && Local_u8Response[1] == 'K' )
	{
		Result = 1;
	}
	
	return Result;
}




u8	 MUSART1_u8Receive(void)
{
	u16 timeout = 0;
	u8 Loc_u8ReceiveData = 0;
	while((GET_BIT((MUSART1->SR) ,5 )) == 0)
	{
		timeout++;
		
		if(timeout == 10000)
		{
			break;
		}
	}
	Loc_u8ReceiveData = MUSART1->DR;
	return (Loc_u8ReceiveData);
}