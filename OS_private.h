#ifndef OS_private_h
#define OS_private_h

typedef struct
{
	u16	priodicity;
	void (*Fptr) (void);
	u8 firstDelay;
	u8 State;
}Task;



#endif