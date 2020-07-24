//Sahil Bajaj 1001662393
#include "SortLib.h"

int name_sort(const void *a,const void *b)
{
    return (strcmp(((combos *)a)->name, ((combos *)b)->name));
}

int sandwich_sort(const void *a,const void *b)
{
    return (strcmp(((combos *)a)->sandwich, ((combos *)b)->sandwich));
}
int fry_size_sort(const void *a, const void *b)
{
    return (((combos *)a)->fry_size > ((combos *)b)->fry_size);
}

int drink_size_sort(const void *a, const void *b)
{
    return (((combos *)a)->drink_size> ((combos *)b)->drink_size);
}
int drink_type_sort(const void *a,const void *b)
{
    return (strcmp(((combos *)a)->drink_type, ((combos *)b)->drink_type));
}

