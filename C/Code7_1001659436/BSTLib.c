//Kartikey Sharma 1001659436
#include "BSTLib.h"
#include<string.h>
#include<stdlib.h>
#include<stdio.h>

void AddBSTNode(BNODE **CurrentNode,char MTName[],char zip[], char filename[], char dimension[]){
	if(*CurrentNode == NULL){
		*CurrentNode = (BNODE *) malloc(sizeof(BNODE));
		(*CurrentNode)->left = (*CurrentNode)->right = NULL;
		strcpy((*CurrentNode)->ZipCode,zip);
		strcpy((*CurrentNode)->MovieTheaterName,MTName);
		strcpy((*CurrentNode)->FileName,filename);
		strcpy((*CurrentNode)->Dimensions,dimension);
	}
	else{
		if(strcmp(zip,(*CurrentNode)-> ZipCode)<0){
			AddBSTNode(&(*CurrentNode)->left,MTName,zip,filename,dimension);
		}
		else if(strcmp(zip,(*CurrentNode)-> ZipCode)>0){
			AddBSTNode(&(*CurrentNode)->right,MTName,zip,filename,dimension);
		}
		else
			printf("\nDuplicate Item Found!\n");
	}
}
void InOrder(BNODE *CurrentNode){
	if(CurrentNode != NULL){
		InOrder(CurrentNode->left);
		printf("%-40s %-s\n",CurrentNode->MovieTheaterName,CurrentNode->ZipCode);
		InOrder(CurrentNode->right);
	}
	
}
BNODE *SearchForBNODE(BNODE *CurrentNode, char zip[]){
	if(CurrentNode!=NULL && strcmp(CurrentNode->ZipCode,zip)==0){
		return CurrentNode;
	}
	else{
		if(atoi(zip) < atoi((CurrentNode)->ZipCode)){
			SearchForBNODE(CurrentNode->left,zip);
	
		}
		else{
			SearchForBNODE(CurrentNode->right,zip);
		}
		
	}

}


