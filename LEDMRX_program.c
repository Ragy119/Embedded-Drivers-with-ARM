/*****************************************/
/* Author  :  Ragy                       */
/* Version :  V01                        */
/* Date    :  31 August 2020             */
/*****************************************/


#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "GPIO_interface.h"
#include "STK_interface.h"

#include "LEDMRX_interface.h"
#include "LEDMRX_private.h"
#include "LEDMRX_config.h"


void HLEDMRX_voidInit(void)
{
	MGPIO_voidSetPinDirection(LEDMRX_ROW0_PIN,OUTPUT_SPEED_2MHZ_PP);
	MGPIO_voidSetPinDirection(LEDMRX_ROW1_PIN,OUTPUT_SPEED_2MHZ_PP);
	MGPIO_voidSetPinDirection(LEDMRX_ROW2_PIN,OUTPUT_SPEED_2MHZ_PP);
	MGPIO_voidSetPinDirection(LEDMRX_ROW3_PIN,OUTPUT_SPEED_2MHZ_PP);
	MGPIO_voidSetPinDirection(LEDMRX_ROW4_PIN,OUTPUT_SPEED_2MHZ_PP);
	MGPIO_voidSetPinDirection(LEDMRX_ROW5_PIN,OUTPUT_SPEED_2MHZ_PP);
	MGPIO_voidSetPinDirection(LEDMRX_ROW6_PIN,OUTPUT_SPEED_2MHZ_PP);
	MGPIO_voidSetPinDirection(LEDMRX_ROW7_PIN,OUTPUT_SPEED_2MHZ_PP);


	MGPIO_voidSetPinDirection(LEDMRX_COL0_PIN,OUTPUT_SPEED_2MHZ_PP);
	MGPIO_voidSetPinDirection(LEDMRX_COL1_PIN,OUTPUT_SPEED_2MHZ_PP);
	MGPIO_voidSetPinDirection(LEDMRX_COL2_PIN,OUTPUT_SPEED_2MHZ_PP);
	MGPIO_voidSetPinDirection(LEDMRX_COL3_PIN,OUTPUT_SPEED_2MHZ_PP);
	MGPIO_voidSetPinDirection(LEDMRX_COL4_PIN,OUTPUT_SPEED_2MHZ_PP);
	MGPIO_voidSetPinDirection(LEDMRX_COL5_PIN,OUTPUT_SPEED_2MHZ_PP);
	MGPIO_voidSetPinDirection(LEDMRX_COL6_PIN,OUTPUT_SPEED_2MHZ_PP);
	MGPIO_voidSetPinDirection(LEDMRX_COL7_PIN,OUTPUT_SPEED_2MHZ_PP);
}


void HLEDMRX_voidDisplay(u8 *Copy_u8Data)
{
	while(1)
	{
		// Column 0
		DisableAllCols();
		SetRowValues(Copy_u8Data[0]);
		MGPIO_voidSetPinValue(LEDMRX_COL0_PIN,LOW);	// Enable Column 0
		MSTK_voidSetBusyWait(2500);					//2.5 MSec
		
		// Column 1
		DisableAllCols();
		SetRowValues(Copy_u8Data[1]);
		MGPIO_voidSetPinValue(LEDMRX_COL1_PIN,LOW);	// Enable Column 1
		MSTK_voidSetBusyWait(2500);					//2.5 MSec
		
		// Column 2
		DisableAllCols();
		SetRowValues(Copy_u8Data[2]);
		MGPIO_voidSetPinValue(LEDMRX_COL2_PIN,LOW);	// Enable Column 2
		MSTK_voidSetBusyWait(2500);					//2.5 MSec
		
		// Column 3
		DisableAllCols();
		SetRowValues(Copy_u8Data[3]);
		MGPIO_voidSetPinValue(LEDMRX_COL3_PIN,LOW);	// Enable Column 3
		MSTK_voidSetBusyWait(2500);					//2.5 MSec
		
		// Column 4
		DisableAllCols();
		SetRowValues(Copy_u8Data[4]);
		MGPIO_voidSetPinValue(LEDMRX_COL4_PIN,LOW);	// Enable Column 4
		MSTK_voidSetBusyWait(2500);					//2.5 MSec
		
		// Column 5
		DisableAllCols();
		SetRowValues(Copy_u8Data[5]);
		MGPIO_voidSetPinValue(LEDMRX_COL5_PIN,LOW);	// Enable Column 5
		MSTK_voidSetBusyWait(2500);					//2.5 MSec
		
		// Column 6
		DisableAllCols();
		SetRowValues(Copy_u8Data[6]);
		MGPIO_voidSetPinValue(LEDMRX_COL6_PIN,LOW);	// Enable Column 6
		MSTK_voidSetBusyWait(2500);					//2.5 MSec
		
		// Column 7
		DisableAllCols();
		SetRowValues(Copy_u8Data[7]);
		MGPIO_voidSetPinValue(LEDMRX_COL7_PIN,LOW);	// Enable Column 7
		MSTK_voidSetBusyWait(2500);					//2.5 MSec
	}
}


static void DisableAllCols(void)
{
	// Disable all Columns (set 1 is disabling in columns)	
	MGPIO_voidSetPinValue(LEDMRX_COL0_PIN,HIGH);
	MGPIO_voidSetPinValue(LEDMRX_COL1_PIN,HIGH);
	MGPIO_voidSetPinValue(LEDMRX_COL2_PIN,HIGH);
	MGPIO_voidSetPinValue(LEDMRX_COL3_PIN,HIGH);
	MGPIO_voidSetPinValue(LEDMRX_COL4_PIN,HIGH);
	MGPIO_voidSetPinValue(LEDMRX_COL5_PIN,HIGH);
	MGPIO_voidSetPinValue(LEDMRX_COL6_PIN,HIGH);
	MGPIO_voidSetPinValue(LEDMRX_COL7_PIN,HIGH);
}





static void SetRowValues(u8 Copy_u8Value)
{
	u8 Local_u8Bit = 0;
	
	Local_u8Bit = GET_BIT(Copy_u8Value,0);
	MGPIO_voidSetPinValue(LEDMRX_ROW0_PIN,Local_u8Bit);
	
	Local_u8Bit = GET_BIT(Copy_u8Value,1);
	MGPIO_voidSetPinValue(LEDMRX_ROW1_PIN,Local_u8Bit);
	
	Local_u8Bit = GET_BIT(Copy_u8Value,2);
	MGPIO_voidSetPinValue(LEDMRX_ROW2_PIN,Local_u8Bit);
	
	Local_u8Bit = GET_BIT(Copy_u8Value,3);
	MGPIO_voidSetPinValue(LEDMRX_ROW3_PIN,Local_u8Bit);
	
	Local_u8Bit = GET_BIT(Copy_u8Value,4);
	MGPIO_voidSetPinValue(LEDMRX_ROW4_PIN,Local_u8Bit);
	
	Local_u8Bit = GET_BIT(Copy_u8Value,5);
	MGPIO_voidSetPinValue(LEDMRX_ROW5_PIN,Local_u8Bit);
	
	Local_u8Bit = GET_BIT(Copy_u8Value,6);
	MGPIO_voidSetPinValue(LEDMRX_ROW6_PIN,Local_u8Bit);
	
	Local_u8Bit = GET_BIT(Copy_u8Value,7);
	MGPIO_voidSetPinValue(LEDMRX_ROW7_PIN,Local_u8Bit);
	
}


void DisplayShift (u8 * Copy_u8Data, u8 Copy_u8Arraylength)
{
	// Repeat the first 8 elements at the end

	u8 Local_u8SelArray[8] = {};

	for(u8 no=0; no<Copy_u8Arraylength-8 ;no++)
	{
		// create 8 element array of the selected window
		for (u8 i = no; i < (8+no); i++)
		{
			Local_u8SelArray[i-no] = Copy_u8Data[i];
		}

		//display column by column for 1 sec for each window
		// 2.5m*8=20 // 1000m/20=50
		for(u8 loop =0;loop<50;loop++)
		{
			// Column 0
			DisableAllCols();
			SetRowValues(Local_u8SelArray[0]);
			MGPIO_voidSetPinValue(LEDMRX_COL0_PIN,LOW);	// Enable Column 0
			MSTK_voidSetBusyWait(2500);					//2.5 MSec

			// Column 1
			DisableAllCols();
			SetRowValues(Local_u8SelArray[1]);
			MGPIO_voidSetPinValue(LEDMRX_COL1_PIN,LOW);	// Enable Column 1
			MSTK_voidSetBusyWait(2500);					//2.5 MSec

			// Column 2
			DisableAllCols();
			SetRowValues(Local_u8SelArray[2]);
			MGPIO_voidSetPinValue(LEDMRX_COL2_PIN,LOW);	// Enable Column 2
			MSTK_voidSetBusyWait(2500);					//2.5 MSec

			// Column 3
			DisableAllCols();
			SetRowValues(Local_u8SelArray[3]);
			MGPIO_voidSetPinValue(LEDMRX_COL3_PIN,LOW);	// Enable Column 3
			MSTK_voidSetBusyWait(2500);					//2.5 MSec

			// Column 4
			DisableAllCols();
			SetRowValues(Local_u8SelArray[4]);
			MGPIO_voidSetPinValue(LEDMRX_COL4_PIN,LOW);	// Enable Column 4
			MSTK_voidSetBusyWait(2500);					//2.5 MSec

			// Column 5
			DisableAllCols();
			SetRowValues(Local_u8SelArray[5]);
			MGPIO_voidSetPinValue(LEDMRX_COL5_PIN,LOW);	// Enable Column 5
			MSTK_voidSetBusyWait(2500);					//2.5 MSec

			// Column 6
			DisableAllCols();
			SetRowValues(Local_u8SelArray[6]);
			MGPIO_voidSetPinValue(LEDMRX_COL6_PIN,LOW);	// Enable Column 6
			MSTK_voidSetBusyWait(2500);					//2.5 MSec

			// Column 7
			DisableAllCols();
			SetRowValues(Local_u8SelArray[7]);
			MGPIO_voidSetPinValue(LEDMRX_COL7_PIN,LOW);	// Enable Column 7
			MSTK_voidSetBusyWait(2500);					//2.5 MSec
		}
	}
}









