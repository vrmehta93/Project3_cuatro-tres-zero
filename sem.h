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
	InitQueue(&sem->RunSemQ);
}

//void P(int* semaphore)
void P(Semaphore_t* sem)
{
	TCB_t* blocked;
	sem->semaphore--;
	if(sem->semaphore < 0)
	{
		// Block the process in the queue associated with the semaphore
		blocked=RunQ;//save the current process away
		DelQueue(&RunQ);//remove from queue
		AddQueue(&sem->RunSemQ,blocked);//Add thread to end of queue
		swapcontext(&(blocked->context),&(RunQ->context));
	}

	
}

//void V(int* semaphore)
void V(Semaphore_t* sem)
{
	sem->semaphore++;	// Increment semaphore 

	if(sem->semaphore <= 0)
	{
		// Take PCB out of the semaphore queue and put it in run queue. "yield" to next runnable process
		AddQueue(&RunQ,DelQueue(&sem->RunSemQ));
	}
	yield();
}	


#endif 
