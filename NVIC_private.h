/********************************/
/* Author    : Ragy             */
/* Date      : 25 AUGUST 2020   */
/* Version   : V01              */
/********************************/

#ifndef NVIC_PRIVATE_H
#define NVIC_PRIVATE_H


// Base Address 0xE000E100
#define NVIC_ISER0	*((u32*)0xE000E100)		// Enable  External interrupt from 0  to 31
#define NVIC_ISER1	*((u32*)0xE000E104)		// Enable  External interrupt from 32 to 63

#define NVIC_ICER0	*((u32*)0xE000E180)		// Disable External interrupt from 0  to 31
#define NVIC_ICER1	*((u32*)0xE000E184)		// Disable External interrupt from 32 to 63

#define NVIC_ISPR0	*((u32*)0xE000E200)		// Set Pending Flag from 0  to 31
#define NVIC_ISPR1	*((u32*)0xE000E204)		// Set Pending Flag from 32 to 63

#define NVIC_ICPR0	*((u32*)0xE000E280)		// Clear Pending Flag from 0  to 31
#define NVIC_ICPR1	*((u32*)0xE000E284)		// Clear Pending Flag from 32 to 63

#define NVIC_IABR0	*((volatile u32*)0xE000E300)
#define NVIC_IABR1	*((volatile u32*)0xE000E304)


#define		MNVIC_GROUP_4_SUB_0		0x05FA0300		// 4 bits for group 
#define		MNVIC_GROUP_3_SUB_1		0x05FA0400		// 3 bits for group and 1 bit for subgroup
#define		MNVIC_GROUP_2_SUB_2		0x05FA0500		// 2 bits for group and 2 bit for subgroup
#define		MNVIC_GROUP_1_SUB_3		0x05FA0600		// 1 bits for group and 3 bit for subgroup
#define		MNVIC_GROUP_0_SUB_4		0x05FA0700		// 0 bits for group and 4 bit for subgroup


#define NVIC_IPR	((volatile u8*)  (0xE000E100 + 0x300))

// SCB preiperal		
#define SCB_AIRCR	*((volatile u32*)(0xE000ED00 + 0x0C))


#endif
