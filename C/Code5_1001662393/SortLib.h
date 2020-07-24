//Sahil Bajaj 1001662393

#ifndef _SORTLIB_H
#define _SORTLIB_H

typedef struct Combos
{
    char name[100];
    char sandwich[100];
    char fry_size;
    char drink_size;
    char drink_type[100];
    
}combos;
int name_sort(const void *a,const void *b);
int sandwich_sort(const void *a,const void *b);
int fry_size_sort(const void *a, const void *b);
int drink_size_sort(const void *a, const void *b);
int drink_type_sort(const void *a,const void *b);

#endif


