//Created by Vishal Mehta & Nash Kleppan
//CSE 430, Project 2
//Group 44
//Arizona State University, Fall 2015

#ifndef q_h
#define q_h

#include "tcb.h"

// return a pointer to a new q_element without adding it to the queue
TCB_t* NewItem()
{
	TCB_t* newItem=malloc(sizeof(struct TCB_t));
	newItem->next=NULL;
	newItem->prev=NULL;
	return newItem;
}

// creates an empty queue, pointer to by the variable head
// use NULL to make the queue empty
void InitQueue(TCB_t** head)
{
	*head = NULL;
}

// adds a queue item, pointer to by "item", to the queue pointer to by head
void AddQueue(TCB_t** head, TCB_t* item)
{
	if(*head == NULL)//indicates empty queue.  Make item head element
	{
		*head = item;
		item->next=item;
		item->prev=item;
		return;
	}

	else if(((*head)->next) ==(*head))//Exactly 1 element in queue
	{
		(*head)->next=item;
		item->prev=*head;
		item->next=*head;
		(*head)->prev=item;
	}

	else//More than 1 item in queue, traverse
	{
		TCB_t* temp = *head;

		while(temp->next != (*head))
		{
			temp = temp->next;
		}

		//Add element, and keep the queue a circular doubly linked list
		temp->next = item;
		item->prev=temp;

		//Link the first and last elements together
		item->next=*head;
		(*head)->prev=item;
	}
}

// deletes an item from head and returns a pointer to the deleted item
TCB_t* DelQueue(TCB_t** head)
{
	//If queue is empty, notify user and return null ptr
	if(*head == NULL)
	{
		printf("ERROR: DelQueue is called when head is NULL\n");
		return *head;
	}
	else if((*head)->next==(*head))//If there is only one item on the queue, delete the item and return it
	{
		TCB_t* temp=*head;
		*head=NULL;
		return temp;//return deleted element
	}
	else//More than 1 element on the queue.  Pop from the head, and fix the queue
	{
		//Save head and tail
		TCB_t* temp1 = *head;	
		TCB_t* temp2 = (*head)->prev;//tail

		//Fix the queue.  Make new head, and fix ptr's for tail and new head.
		*head=temp1->next;
		(*head)->prev=temp2;
		temp2->next=*head;
		return temp1;
	}
}

// Moves the head pointer to the next element in the queue, and adds the current head element to the end of the queue. 
void RotateQ(TCB_t** head)
{
	TCB_t* temp=DelQueue(head);
	AddQueue(head, temp);
	//*head=(*head)->next;
}

//This print function doesn't really make any sense after the change to using TCB_t directly instead of q_element
//void print(q_element* head)
//{
//	q_element* temp = head;

//	while(temp != NULL)
//	{
//		printf("%d ", temp->payload);
//		temp = temp->next;
//	}

//printf("\n");
//}
#endif
