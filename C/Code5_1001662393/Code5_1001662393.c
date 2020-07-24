//Sahil Bajaj 1001662393
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include "SortLib.h"

void get_command_line_parameter(char *argv[], char ParamName[], char ParamValue[])
{
    int i = 0;
    while (argv[++i] != NULL)
    {
        if (!strncmp(argv[i], ParamName, strlen(ParamName)))
        {
            strcpy(ParamValue, strchr(argv[i], '=') + 1);
        }
    }
    return;
}

int ReadLunchOrders (combos LunchOrders[], FILE *fp)
{
    int c = 0;
    
    char Delim[2] = "|";
    char *Token;
    
    char datafile[100]; //the file to be read.
    while(fgets(datafile,99,fp))
    {
        if(ferror(fp))
        {
            perror("ERROR, THE FILE DOES NOT OPEN!!");
            c = -1;
            
        }
        if(datafile[strlen(datafile)-1] == '\n')
        {
            datafile[strlen(datafile)-1] = '\0';
        }
        
        Token = strtok(datafile, Delim);
        strcpy(LunchOrders[c].name,Token);
        Token = strtok(NULL, Delim);
        strcpy(LunchOrders[c].sandwich,Token);
        Token = strtok(NULL, Delim);
        strcpy(&LunchOrders[c].fry_size,Token);
        Token = strtok(NULL, Delim);
        strcpy(&LunchOrders[c].drink_size,Token);
        Token = strtok(NULL, Delim);
        strcpy(LunchOrders[c].drink_type,Token);
        c++;
    }
    return c;
}
void PrintLunchOrders(combos LunchOrders[], int orders_count)
{
    int i;
    printf("\n");
    printf("\n\nNO.\tNAME\tSANDWICH\tFRY SIZE\tDRINK SIZE\tDRINK TYPE\n");
    
    for(i=0;i<orders_count;i++)
    {
        printf("%d \t%-s \t%-s \t%-c \t\t%-c \t\t%-s\n",i+1,LunchOrders[i].name,LunchOrders[i].sandwich,LunchOrders[i].fry_size,LunchOrders[i].drink_size,LunchOrders[i].drink_type);
        
    }
    
    
}
void SuperSizeIt(combos *p)
{
    p->fry_size='L';
    p->drink_size='L';
}
void WriteLunchOrders(combos LunchOrders[], int orders_count, FILE *ptr)
{
    int i;
    for(i=0;i<orders_count;i++)
    {
        fprintf(ptr,"%s|%s|%c|%c|%s\n",LunchOrders[i].name,LunchOrders[i].sandwich,LunchOrders[i].fry_size,LunchOrders[i].drink_size,LunchOrders[i].drink_type);
    }
}




int main(int argc, char *argv[])
{
    combos LunchOrders[1000];
    int (*func[])(const void *a,const void *b)={name_sort,sandwich_sort,fry_size_sort,drink_size_sort,drink_type_sort};
    char f1[20];
    char f2[20];
    char arg[50];
    get_command_line_parameter(argv, "INITIALORDER=", arg);
    strcpy(f1,arg);
    get_command_line_parameter(argv, "FINALORDER=", arg);
    strcpy(f2,arg);
    FILE *fp;
    fp = fopen(f1, "r");
    FILE *ptr;
    ptr = fopen(f2,"w");
    if(fp==NULL)
    {
        printf("ERROR! THE FILE DID NOT OPEN!!");
        exit(0);
    }
    if(ptr==NULL)
    {
        printf("ERROR! THE FILE DID NOT OPEN!!");
        exit(0);
    }
    int m,ch=0,ch2;
    m = ReadLunchOrders(LunchOrders, fp);
    PrintLunchOrders(LunchOrders, m);
    fclose(fp);
    
    do{
        printf("Enter 0 to finalize orders and print final orders to file: \n\n");
        printf("Supersize which order? (1-3): ");
        scanf("%d",&ch);
        SuperSizeIt(&LunchOrders[ch-1]);
        
        if(ch <0 || ch>m)
            printf("Invalid input\n");
        else
            PrintLunchOrders(LunchOrders, m);
        
    }while(ch != 0);
    do
    {
        printf("Choose a sort before writing out the file\n\n");
        printf("0. No sort - write out in current order \n1. Sort by Name\n2. Sort by Sandwich\n3. Sort by Fry Size\n4. Sort by Drink Size\n5. Sort by Drink Type");
        printf("\n\nEnter Choice: ");
        scanf("%d",&ch2);
        printf("\n\n\nWriting lunch orders to file....\n\n");
        if(ch2 < 0 || ch2 > 5)
        {
            printf("Invalid input\n");
        }
    }while(ch2 < 0 || ch2 > 5);
    if(ch2){
        qsort(LunchOrders,m,sizeof(combos),(*func[ch2-1]));
        PrintLunchOrders(LunchOrders, m);
    }
    
    WriteLunchOrders(LunchOrders, m, ptr);
    
    fclose(ptr);
    
    
    return 0;
    
}

