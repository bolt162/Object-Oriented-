//Kartikey Sharma 1001659436
#include "StackLib.h"
#include<string.h>
#include<stdlib.h>
#include<stdio.h>
void push(SNODE **StackTop, LNODE *Tickets, int receiptnum, char MVTName[]){
	SNODE *NewNode = malloc(sizeof(SNODE));
	NewNode->TicketList = Tickets;
	NewNode->ReceiptNumber = receiptnum;
	strcpy(NewNode->MovieTheaterName,MVTName);
	NewNode->next_ptr = NULL;
	
	if(*StackTop == NULL){
		*StackTop = NewNode;
	}
	else{
		NewNode->next_ptr = *StackTop;
		*StackTop = NewNode;
	}
}


void pop(SNODE **StackTop){
	SNODE *TempPtr = *StackTop;
	
	if(*StackTop == NULL){
		printf("Pop not executed - stack");
	}
	else{
		free(*StackTop);
		*StackTop = TempPtr->next_ptr;
	}
	
}
