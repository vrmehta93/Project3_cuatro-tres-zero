#ifndef sem_h
#define sem_h

#include "threads.h"

int semaphore;
TCB_t* RunSemQ = 0;

//void InitSem(int* semaphore, int* value)
void InitSem(int* value)
{
	semaphore = *value;
}

//void P(int* semaphore)
void P()
{
	if(semaphore == 0)
	{
		// Block the process in the queue associated with the semaphore
	}
	else
	{
		semaphore--;
	}
	
}

//void V(int* semaphore)
void V()
{
	if(semaphore <= 0)
	{
		// Take PCB out of the semaphore queue and put it in run queue. "yield" to next runnable process
	}
	
	semaphore++;	// Increment semaphore 
}	


#endif 
