//Kartikey Sharma 1001659436
#include "ListLib.h"
#include<string.h>
#include<stdlib.h>

void InsertNode(LNODE **LinkedListHead,char tickets[]){
	LNODE *TempPtr,*NewNode;
	NewNode = malloc(sizeof(LNODE));
	NewNode->next_ptr = NULL;
	strcpy(NewNode->Ticket,tickets);
	if(*LinkedListHead == NULL || (*LinkedListHead)->Ticket >= NewNode->Ticket){
		NewNode->next_ptr = *LinkedListHead;
		*LinkedListHead = NewNode;
	}
	else{
		TempPtr = *LinkedListHead;
		
		while(TempPtr->next_ptr != NULL && (TempPtr->next_ptr)->Ticket < NewNode->Ticket){
			TempPtr = TempPtr->next_ptr;
		}
		NewNode->next_ptr = TempPtr->next_ptr;
		TempPtr->next_ptr = NewNode;
	}
}
void ReturnAndFreeLinkedListNode(LNODE **LinkedListHead,char ticket[]){
	LNODE *TempPtr, *PreviousNode;
	TempPtr = *LinkedListHead;
	if (TempPtr != NULL){
	
	strcpy(ticket,TempPtr->Ticket);
	*LinkedListHead = TempPtr->next_ptr;
	free(TempPtr);
	}
}

