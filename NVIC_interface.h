/********************************/
/* Author    : Ragy             */
/* Date      : 25 AUGUST 2020   */
/* Version   : V01              */
/********************************/

#ifndef NVIC_INTERFACE_H
#define NVIC_INTERFACE_H

void MNVIC_voidEnableInterrupt	(u8	copy_u8IntNumber);
void MNVIC_voidDisableInterrupt	(u8	Copy_u8IntNumber);
void MNVIC_voidSetPendingFlag	(u8	Copy_u8IntNumber);
void MNVIC_voidClearPendingFlag	(u8	Copy_u8IntNumber);
u8 	 MNVIC_voidGetActiveFlag	(u8	Copy_u8IntNumber);
void MNVIC_voidSetPriority(s8 Copy_s8IntID , u8 Copy_u8GroupPriority , u8 Copy_u8SubPriority , u32 Copy_u32Group);

// void MNVIC_voidInit(void);
// void MNVIC_voidSetPriority(u8 Copy_PeriperalIdx , u8 Copy_u8Priority);

#define		GROUP3		0x05FA0300		// 4 bits for group 
#define		GROUP4		0x05FA0400		// 3 bits for group and 1 bit for subgroup
#define		GROUP5		0x05FA0500		// 2 bits for group and 2 bit for subgroup
#define		GROUP6		0x05FA0600		// 1 bits for group and 3 bit for subgroup
#define		GROUP7		0x05FA0700		// 0 bits for group and 4 bit for subgroup




#endif
