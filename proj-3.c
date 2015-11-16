// Nash Kleppan and Vishal Mehta
// CSE 430

#include "sem.h"

//Globals

#define SEMAPHORE_SIZE 2

int totalProd=0;
Semaphore_t* semaphore;

void thread1();
void thread2();
void thread3();
//void thread4();
//void thread5();

int main()
{
	printf("Creating global RunQ and Semaphore\n");
	
	//Global RunQ
	TCB_t *RunQ=0;
	semaphore = NewSem();
	
	InitQueue(&RunQ); //Initialize an empty queue
	
	InitQueue(&(semaphore->RunSemQ));	// TODO: Change name?
	InitSem(semaphore, SEMAPHORE_SIZE);
	
	printf("Initializing threads.  This represents building factories...\n");
	start_thread(thread1);//Factory1 
	start_thread(thread2);//Factory2 
	start_thread(thread3);//Factory3 
//	start_thread(thread4);//Factory4 
//	start_thread(thread5);//Factory5
	printf("Threads initialized.  Running now.\n");
	
	run();//Let the magic happen
	return 0;
}

void thread1(void)//Calculates factory 1's production
{
	int local=1;
	int pass=0;
	printf("Thread 1 started.  Represents the opening of a new factory.\n");
	while(1)
	{
		P(semaphore);
		
		pass++;
		local=local*2;//produce units
		totalProd+=local;
		printf("Thread1, run %d: TotalProduction= %d  Factory1 Production= %d\n",pass,totalProd,local);
		
		V(semaphore);
//		yield();
		sleep(1);
	}
	
	return;
}

void thread2(void)//Calculates factory 2's production
{
	int local=1;
	int pass=0;
	printf("Thread 2 started.  Represents the opening of a new factory.\n");
	while(1)
	{
		P(semaphore);
		
		pass++;
		local=local*3;//produce units
		totalProd+=local;
		printf("Thread2, run %d: TotalProduction= %d  Factory1 Production= %d\n",pass,totalProd,local);
		
		V(semaphore);
//		yield();
//		sleep(1);
	}
	
	return;
}

void thread3(void)//Calculates factory 3's production
{
	int local=1;
	int pass=0;
	printf("Thread 3 started.  Represents the opening of a new factory.\n");
	while(1)
	{
		P(semaphore);
		
		pass++;
		local=local*4;//produce units
		totalProd+=local;
		printf("Thread3, run %d: TotalProduction= %d  Factory1 Production= %d\n",pass,totalProd,local);
		
		V(semaphore);
//		yield();
//		sleep(1);
	}
	return;
}


