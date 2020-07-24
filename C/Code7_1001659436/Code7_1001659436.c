//Kartikey Sharma
//1001659436
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<errno.h>
#include "ListLib.h"
#include "BSTLib.h"
#include "QueueLib.h"
#include "StackLib.h"
#define def 150

void printseat(int m, int n, char seatmap[][20]){
	int i = 0,j;
	int c = 0;
	printf("\n\n");
	for (c = 1; c <= n; c++){
		printf("\tSeat%d",c);
	}
	printf("\n");
	for(i = 0; i<m;i++){
		printf("Row %c\t",65+i);
		for(j=0;j<n;j++){
			printf("%4c\t",seatmap[i][j]);
		}
		printf("\n");
	}
}
void get_command_line_parameter(char *argv[], char ParamName[], char ParamValue[]){
    int i = 0;
    while (argv[++i] != NULL){
        if (!strncmp(argv[i], ParamName, strlen(ParamName))){
            strcpy(ParamValue, strchr(argv[i], '=') + 1);
        }
    }
    return;
}
void selltickets(LNODE *TicketListHead,char taken[],int row, int col, char seatmap[][20], FILE *fpointer3){
    int m;
    int n;
    int i;
    int j;
	char pseat;
	int pseat1;
	
	printf("\nPick a seat (Row Seat) ");
	scanf(" %c%d",&pseat,&pseat1);
    pseat=toupper(pseat);
	m = (int)(toupper(pseat))-65;
	n = pseat1;
	
	sprintf(taken,"%c%d",pseat,pseat1);
	
	while(m >row || n>col || m <0 || n <0){
		printf("Invalid Seat Choice\n");
			
		printseat(row,col,seatmap);
		
		printf("\nPick a seat (Row Seat) ");
		scanf(" %c%d",&pseat,&pseat1);
        pseat=toupper(pseat);
		m = (int)(toupper(pseat))-65;
		n = pseat1;
			
	}
	if(seatmap[m][n-1] == 'X'){
		printf("\nSeat %c-%d is not available.\n",pseat,pseat1);
		selltickets(TicketListHead,taken,row,col,seatmap,fpointer3);
	}
	else{
		seatmap[m][n-1] = 'X';
		for(i = 0; i<row; i++){
			for(j = 0; j<col; j++){
				fputc(seatmap[i][j],fpointer3);
			}
		}
		fclose(fpointer3);
	}
}
int main(int argc, char *argv[]){
	QNODE *QueueHead = NULL;
	QNODE *QueueTail = NULL;
	BNODE *CurrentNode = NULL;
	BNODE *current_node = NULL;
	LNODE *TempPtr = NULL;
	SNODE *StackTop = NULL;
    FILE *fpointer1;
    FILE *fpointer2;
    FILE *fpointer3;
	char argvalue[def];
    char name1[def];
    char name2[def];
	char seatmap[26][20];
	char ReceiptNumber[3];
	char file1[30];
	char file2[500];
	char file3[100];
	char buffer[520];
	char *Token;
	char row[520];
	char col[520];
	char Taken[3];
	char Delimeter[3] = "|";
	int m,n;
	int i,j;
	int TicketNum;
	int ReceiptNum = 0;
	int choice;
	char MovieTheaterName[40];
    char ZipCode[6];
    char FileName[100];
    char Dimensions[6];
    current_node = malloc(sizeof(BNODE));
	get_command_line_parameter(argv,"QUEUE=",argvalue);
	strcpy(name1,argvalue);
	get_command_line_parameter(argv,"ZIPFILE=",argvalue);
	strcpy(name2,argvalue);
	get_command_line_parameter(argv,"RECEIPTNUMBER=",argvalue);
	strcpy(ReceiptNumber,argvalue);
	fpointer1 = fopen(name1,"r");
	fpointer2 = fopen(name2,"r");
	
	if(fpointer1 == NULL){
		printf("Error opening the File!\n\n");
		exit(0);
	}
	
	if(fpointer2 == NULL){
		printf("Error opening the File!\n\n");
		exit(0);
	}
	
	while(fgets(file1,29,fpointer1)!=NULL){
		if(ferror(fpointer1))
			perror("File opening Failed");
		else
			enQueue(file1, &QueueHead, &QueueTail);
	}
	
	while(fgets(file2,499,fpointer2)){
        if(ferror(fpointer2)){
			perror("File opening Failed");
        }
		Token = strtok(file2,Delimeter);
		strcpy(MovieTheaterName,Token);
		
		Token = strtok(NULL,Delimeter);
		strcpy(ZipCode,Token);
		
		Token = strtok(NULL,Delimeter);
		strcpy(FileName,Token);
		
		Token = strtok(NULL,Delimeter);
		strcpy(Dimensions,Token);
		
		AddBSTNode(&CurrentNode,MovieTheaterName,ZipCode,FileName,Dimensions);
		
	}
	
	ReceiptNum = atoi(ReceiptNumber);
	
	while(QueueHead != NULL){
		LNODE *TicketListHead = NULL;
        int menu = 0;
        printf("\n\n1. Sell tickets to next customer\n"
               "2. See who's in line\n"
               "3. See the seat map for a given theater\n"
               "4. Print today's receipts\n");
        do{
            printf("Choose an option: ");
            scanf("%d",&menu);
            if(menu >4 || menu<1){
                printf("Invalid option please reenter\n");
            }
        }while(menu>4 || menu<1);
		if(menu == 1){
			printf("\n\nHello %s",QueueHead->Name);
			deQueue(&QueueHead);
            printf("\n\nPick a theatre by entering a ZipCode\n");
			InOrder(CurrentNode);
			printf("\n\nEnter zip ");
			scanf("%s",&ZipCode);
			current_node = SearchForBNODE(CurrentNode,ZipCode);
			strcpy(file3,current_node->FileName);
			strcpy(buffer,current_node->Dimensions);
			fpointer3 = fopen(file3,"r");
			Token = strtok(buffer,"x");
			strcpy(row,Token);
			Token = strtok(NULL,Token);
			strcpy(col,Token);
			m = atoi(row);
			n = atoi(col);
			for(i = 0;i<m;i++){
				for(j = 0;j<n;j++){
					seatmap[i][j] = fgetc(fpointer3);
				}
			}
			printf("\nSeat Map\n\n");
			printseat(m,n,seatmap);
			fclose(fpointer3);
			printf("\nHow many tickets do you want to buy ");
			scanf("%d",&TicketNum);
			for(i = 0; i<TicketNum;i++){
				fpointer3 = fopen(file3,"w");
				selltickets(TicketListHead,Taken,m,n,seatmap,fpointer3);
				InsertNode(&TicketListHead,Taken);
				printseat(m,n,seatmap);
			}
			push(&StackTop,TicketListHead,ReceiptNum,current_node->MovieTheaterName);
			ReceiptNum++;
		}
		if(menu == 2){
			printf("\nCustomer Queue\n\n\n");
			DisplayQueue(QueueHead);
		}
		if(menu == 3){
            printf("\n\nPick a theatre by entering a ZipCode\n");
			InOrder(CurrentNode);
            printf("\n\nEnter zip ");
			scanf("%s",&ZipCode);
			current_node = SearchForBNODE(CurrentNode,ZipCode);
			strcpy(file3,current_node->FileName);
			strcpy(buffer,current_node->Dimensions);
			fpointer3 = fopen(file3,"r");
			Token = strtok(buffer,"x");
			strcpy(row,Token);
			Token = strtok(NULL,Token);
			strcpy(col,Token);
			m = atoi(row);
			n = atoi(col);
			for(i = 0;i<m;i++){
				for(j = 0;j<n;j++){
					seatmap[i][j] = fgetc(fpointer3);
				}
			}
            printf("\nSeat Map\n\n");
			printseat(m,n,seatmap);
			fclose(fpointer3);
		}
		if(menu == 4){
			printf("\nToday's receipts are: \n");
			if(StackTop == NULL){
				printf("No Receipts are available\n");
			}
			else{
                char temp[121];
				while(StackTop != NULL){
					
					printf("\nReceipts #%d",StackTop->ReceiptNumber);
					printf("\n\n\t%s\n\n",StackTop->MovieTheaterName);
				
					while(StackTop->TicketList != NULL){
						ReturnAndFreeLinkedListNode(&StackTop->TicketList,temp);
						printf("\t%s",temp);
						strcpy(temp, "");
					}
					printf("\n");
					pop(&StackTop);
				}
			}
		}
	}
    if(QueueHead ==NULL){
              printf("\nGood job - you sold tickets to all of the customers in line.\n");
        printf("\nToday's receipts are: \n");
        if(StackTop == NULL){
            printf("No Receipts are available\n");
        }
        else{
            char temp[121];
            while(StackTop != NULL){
                
                printf("\nReceipts #%d",StackTop->ReceiptNumber);
                printf("\n\n\t%s\n\n",StackTop->MovieTheaterName);
                
                while(StackTop->TicketList != NULL){
                    ReturnAndFreeLinkedListNode(&StackTop->TicketList,temp);
                    printf("\t%s",temp);
                    strcpy(temp, "");
                }
                printf("\n");
                pop(&StackTop);
            }
        }
    }
	return 0;
}
