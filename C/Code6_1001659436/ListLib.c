//Kartikey Sharma
//1001659436
#include "ListLib.h"
#include<string.h>
#include<stdlib.h>
#include<stdio.h>

void AddNode(char letterstore,char drawstore[], node **LinkedListHead)
{
    node *TempPtr, *NewNode;
    NewNode = malloc(sizeof(node));
    NewNode->letter = letterstore;
    strcpy(NewNode->draw, drawstore);
    NewNode->next_ptr = NULL;
    /* Linked list is empty so point head at new node */
    if (*LinkedListHead == NULL)
    {
        *LinkedListHead = NewNode;
    }
    else
    {
        TempPtr = *LinkedListHead;
        /* Traverse the linked list to find the end node */
        while (TempPtr->next_ptr != NULL)
            TempPtr = TempPtr->next_ptr;
        /* Change end node to point to new node */
        TempPtr->next_ptr = NewNode;
    }
}
void search(char charnewnode, char array[],node **flag)
{
    node *TempPtr;
    TempPtr = *flag;
    while(TempPtr != NULL)
    {
        if(TempPtr->letter==charnewnode)
        {
            strcpy(array,TempPtr->draw);
            *flag = TempPtr->next_ptr;
            return;
        }
        TempPtr = TempPtr->next_ptr;
    }
    *flag = TempPtr;
}
