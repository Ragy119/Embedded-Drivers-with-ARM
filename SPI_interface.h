#ifndef SPI_INTERFACE_H
#define SPI_INTERFACE_H

void MSPI1_voidInit(void);
void MSPI1_voidSendReceiveSynch(u8 Copy_u8DataToTrasmit, u8 *Copy_DataToReceive);
void MSPI1_voidSendReceiveAsynch(u8 Copy_u8DataToTrasmit, void (*Callback)(u8));



#endif