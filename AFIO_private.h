/********************************/
/* Author    : Ragy             */
/* Date      : 26 AUGUST 2020   */
/* Version   : V01              */
/********************************/

#ifndef AFIO_PRIVATE_H
#define AFIO_PRIVATE_H

typedef struct{
	volatile u32	AVCR;
	volatile u32	MAPR;
	volatile u32	EXTICR[4];
	volatile u32	MAPR2;
		
}AFIO_t;

#define	AFIO	((volatile AFIO_t *) 0x40010000)



#endif