#ifndef sem_h
#define sem_h

#include "threads.h"

typedef struct Semaphore_t
{
	int semaphore;
	TCB_t* RunSemQ;
} Semaphore_t;


Semaphore_t* NewSem()
{
	Semaphore_t* newSem = (Semaphore_t*) malloc(sizeof(Semaphore_t));
	newSem->semaphore = 0;
	newSem->RunSemQ = 0;
	
	return newSem;
}

//void InitSem(int* semaphore, int* value)
void InitSem(Semaphore_t* sem, int value)
{
	sem->semaphore = value;
}

//void P(int* semaphore)
void P(Semaphore_t* sem)
{
	if(sem->semaphore == 0)
	{
		// Block the process in the queue associated with the semaphore
	}
	else
	{
		sem->semaphore--;
	}
	
}

//void V(int* semaphore)
void V(Semaphore_t* sem)
{
	if(sem->semaphore <= 0)
	{
		// Take PCB out of the semaphore queue and put it in run queue. "yield" to next runnable process
	}
	
	sem->semaphore++;	// Increment semaphore 
}	


#endif 
