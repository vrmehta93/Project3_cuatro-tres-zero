//Created by Vishal Mehta & Nash Kleppan
//CSE 430, Project 2
//Group 44
//Arizona State University, Fall 2015

#ifndef threads_h
#define threads_h

#include "q.h"

//8KB stack size
#define STACK_SIZE 8192

struct TCB_t *RunQ;

void start_thread(void (*function)(void))
{
	void* stackPtr = malloc(8192);
	TCB_t* tcbPtr = (struct TCB_t*) malloc(sizeof(struct TCB_t));//Make the TCB element.  Casting to make warnings shut up
	init_TCB(tcbPtr, function, stackPtr, 8192);//Initialize the TCB with a stack and a function

	AddQueue(&RunQ, tcbPtr);
}

void run()
{
	// real code, now with fixed indentation!
	ucontext_t parent;     // get a place to store the main context, for faking
	getcontext(&parent);   // magic sauce
	swapcontext(&parent, &(RunQ->context));  // start the first thread
}

void yield()
{
//	rotate the run Q;
//	swap the context, from previous thread to the thread pointed to by RunQ
	TCB_t *temp=RunQ;//Save away the current execution into a tempvar
	RotateQ(&RunQ);//Execute rotation
	swapcontext(&(temp->context),&(RunQ->context));//Swap out the old context for the new context
}
#endif
