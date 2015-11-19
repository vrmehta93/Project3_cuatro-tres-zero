#Project 3 for CSE cuatro-tres-zero
Nash Kleppan
Vishal Mehta
CSE 430, ASU, Fall 2015

FILES:
  This projects consists of:
    q.h:  Reused from previous project.
    tcb.h:  Reused from previous project.
    threads.h:  Reused from previous project.
    sem.h:  Defines semaphore structure and functions for initialization, P() and V() operations.
    proj-3.c:  Test driver that coordinates three threads using the semaphore.  Each thread is of the following structure:
      while(1){
      P(semaphore);
      //Operations of thread
      V(semaphore);
      sleep(1);//So that we can actually see it running
      }

COMPILATION:
  Execute the following in the directory containing this README as well as the source code:
    # gcc proj-3.c
    # ./a.out

