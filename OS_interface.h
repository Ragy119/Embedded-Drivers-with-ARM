#ifndef OS_interface_h
#define OS_interface_h


void SOS_voidCreateTask(u8 Copy_u8ID , u16 Copy_u8Priodicity, void(*ptr)(void), u8 Copy_u8FirstDelay);
void SOS_voidStart(void);


#endif