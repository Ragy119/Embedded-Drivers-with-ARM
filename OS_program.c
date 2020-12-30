#include "STD_TYPES.h"
#include "BIT_MATH.h"

#include "MSTK_interface.h"

#include "OS_interface.h"
#include "OS_private.h"
#include "OS_config.h"

#define		NULL	(void *)0
// array of tasks  (array of struchture)
static Task OS_Tasks[NUMBER_OF_TASKS]	=	{NULL} 

void SOS_voidCreateTask(u8 Copy_u8ID , u16 Copy_u8Priodicity, void(*ptr)(void))
{
	OS_Tasks[Copy_u8ID].priodicity = Copy_u8Priodicity;
	OS_Tasks[Copy_u8ID].Fptr = ptr;
}



void SOS_voidStart(void)
{
	// init 
	MSTK_voidInit();
	// Tick => 1 msec  
	// HSR 8MHZ /8  ==> 1000 Micro Sec ===> 1 msec
	MSTK_voidSetIntervalPeriodic(1000, Scheduler);
	
}

volatile u16 TickCounts =0;

/*void Scheduler(void)
{
	for(u8 i=0; i<NUMBER_OF_TASKS ; i++)
	{
		if((TickCounts % OS_Tasks[i].priodicity) == 0)
		{
			OS_Tasks[i].Fptr();
		}
	}
	
	TickCounts++;
}*/

void Scheduler(void)
{
	for(u8 i=0; i<NUMBER_OF_TASKS ; i++)
	{
		if((OS_Tasks[i].Fptr != NULL) && OS_Tasks[i].state == TASK_READY )
		{
			if(OS_Tasks[i].firstDelay == 0)
			{
				OS_Tasks[i].firstDelay = OS_Tasks[i].priodicity-1;
				OS_Tasks[i].Fptr();
			}
			else
			{
				OS_Tasks[i].firstDelay--;
			}
		}
	}
	
	TickCounts++;
}


