#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "SPI_interface.h"
#include "STK_interface.h"

#include "TFT_interface.h"
#include "TFT_private.h"
#include "TFT_config.h"



void HTFT_voidInit(void)
{
	// Reset Pulse
	MGPIO_voidSetPinValue(TFT_RST_PIN,HIGH);
	MSTK_voidSetBusyWait(100);
	MGPIO_voidSetPinValue(TFT_RST_PIN,LOW);
	MSTK_voidSetBusyWait(1);
	MGPIO_voidSetPinValue(TFT_RST_PIN,HIGH);
	MSTK_voidSetBusyWait(100);
	MGPIO_voidSetPinValue(TFT_RST_PIN,LOW);
	MSTK_voidSetBusyWait(100);
	MGPIO_voidSetPinValue(TFT_RST_PIN,HIGH);
	MSTK_voidSetBusyWait(120000);
	
	// Sleep out Command
	voidWriteCommand(0x11);
	
	// wait 150 ms
	MSTK_voidSetBusyWait(150000);
	
	// color mode command
	voidWriteCommand(0x3A);
	voidWriteData(0x05);
	
	// Display on command
	voidWriteCommand(0x29);
}


void HTFT_voidDisplayImage(const u16* Copy_Image)
{
	u16 counter;
	u8 Data;
	
	// Set X Address
	voidWriteCommand(0x2A);
	voidWriteData(0);		// x start from 0
	voidWriteData(0);
	voidWriteData(0);		// x end to 127 
	voidWriteData(127);	
	
	// Set Y address 
	voidWriteCommand(0x2B);
	voidWriteData(0);		// y start from 0
	voidWriteData(0);
	voidWriteData(0);		// y end to 159 
	voidWriteData(159);
	
	// RAM write 
	voidWriteCommand(0x2C);
	
	
	//voidWriteData(0xffff);
	
	for (counter=0; counter<20480; counter++)
	{
		Data = Copy_Image[counter] >> 8;

		/* Write the high byte */
		voidWriteData(Data);
		/* Write the low byte */
		Data = Copy_Image[counter] & 0x00ff;
		voidWriteData(Data); 
	}
	
}


void HTFT_voidFillColor(u16 Copy_u16Color)
{
	u16 counter;
	u8 Data;
	
	// Set X Address
	voidWriteCommand(0x2A);
	voidWriteData(0);		// x start from 0
	voidWriteData(0);
	voidWriteData(0);		// x end to 127 
	voidWriteData(127);	
	
	// Set Y address 
	voidWriteCommand(0x2B);
	voidWriteData(0);		// y start from 0
	voidWriteData(0);
	voidWriteData(0);		// y end to 159 
	voidWriteData(159);
	
	// RAM write 
	voidWriteCommand(0x2C);
	
	
	//voidWriteData(0xffff);
	
	for (counter=0; counter<20480; counter++)
	{
		Data = Copy_u16Color >> 8;

		/* Write the high byte */
		voidWriteData(Data);
		/* Write the low byte */
		Data = Copy_u16Color & 0x00ff;
		voidWriteData(Data); 
	}
	
}

void HTFT_voidDrawRecht(u8 x1, u8 x2, u8 y1, u8 y2, u16 Copy_u16Color)
{
	u16 counter;
	u8 Data;
	
	u16 size = (x2-x1) * (y2-y1);
	// Set X Address
	voidWriteCommand(0x2A);
	voidWriteData(0);		// x start from 0
	voidWriteData(x1);
	voidWriteData(0);		// x end to 127 
	voidWriteData(x2);	
	
	// Set Y address 
	voidWriteCommand(0x2B);
	voidWriteData(0);		// y start from 0
	voidWriteData(y1);
	voidWriteData(0);		// y end to 159 
	voidWriteData(y2);
	
	// RAM write 
	voidWriteCommand(0x2C);
	
	
	//voidWriteData(0xffff);
	
	for (counter=0; counter<size; counter++)
	{
		Data = Copy_u16Color >> 8;

		/* Write the high byte */
		voidWriteData(Data);
		/* Write the low byte */
		Data = Copy_u16Color & 0x00ff;
		voidWriteData(Data); 
	}
	
}


static void voidWriteCommand(u8 Copy_u8Command)
{
	u8 Local_u8Temp;
	// Set A0 Pin to low
	MGPIO_voidSetPinValue(TFT_A0_PIN,LOW);
	// send data over SPI
	MSPI1_voidSendReceiveSynch(Copy_u8Command, &Local_u8Temp);
	
}

static void voidWriteData(u8 Copy_u8Data)
{
	u8 Local_u8Temp;
	// Set A0 Pin to high
	MGPIO_voidSetPinValue(TFT_A0_PIN,HIGH);
	// send data over SPI
	MSPI1_voidSendReceiveSynch(Copy_u8Data, &Local_u8Temp);
	
}











