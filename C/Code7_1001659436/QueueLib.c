//Kartikey Sharma 1001659436
#include "QueueLib.h"
#include<string.h>
#include<stdlib.h>
#include<stdio.h>

void enQueue(char customer[], QNODE **QueueHead, QNODE **QueueTail){
	QNODE *NewNode = malloc(sizeof(QNODE));
	strcpy(NewNode->Name,customer);
	NewNode->next_ptr = NULL;
	
	if(*QueueHead == NULL){
		*QueueHead = *QueueTail = NewNode;
	}
	else{
		(*QueueTail)->next_ptr = NewNode;
		*QueueTail = NewNode;
	}
}

void deQueue(QNODE **QueueHead){
	QNODE *TempPtr = (*QueueHead)->next_ptr;
	
	if (*QueueHead == NULL){
		printf("Queue is emtpy\n\n");
	}
	else{
		TempPtr = (*QueueHead)->next_ptr;
		free(*QueueHead);
		*QueueHead = TempPtr;
	}
}

void DisplayQueue(QNODE *QueueHead){
	QNODE *TempPtr = QueueHead;
	if(TempPtr == NULL)
		printf("The customer queue is empty");
	
	else{
		while(TempPtr != NULL){
			printf("%s",TempPtr->Name);
			TempPtr = TempPtr->next_ptr;
		}
	}
}

