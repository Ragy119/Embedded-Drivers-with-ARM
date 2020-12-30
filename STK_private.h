/********************************/
/* Author    : Ragy             */
/* Date      : 27 AUGUST 2020   */
/* Version   : V01              */
/********************************/

#ifndef STK_PRIVATE_H
#define STK_PRIVATE_H

typedef struct{
	volatile	u32	CTRL;
	volatile	u32	LOAD;
	volatile	u32 VAL;
	volatile	u32	CALIB;
}STK_struct;

#define STK	((volatile STK_struct *)(0xE000E010))

#define	STK_CLOCK_AHB_8	0x00000000	//clock AHB/8 & disable systick and interrupt
#define	STK_CLOCK_AHB	0x00000004	//clock AHB   & disable systick and interrupt


#define	STK_ENABLE_BIT		0
#define	STK_INT_BIT			1
#define	STK_CLK_SOURCE		2
#define	STK_FLAG_BIT		16


#endif
