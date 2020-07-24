//Kartikey Sharma 1001659436
#ifndef _LISTLIB_H
#define _LISTLIB_H

#define max 20

typedef struct node
{
    char letter;
    char draw[max];
    struct node *next_ptr;
}node;

void AddNode(char letterstore,char drawstore[], node **LinkedListHead);
void search(char charnewnode, char array[],node **flag);
#endif
