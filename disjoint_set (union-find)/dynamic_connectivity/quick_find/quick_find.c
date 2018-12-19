#include <stdlib.h>
#include "quick_find.h"

int *
initialize(int n)
{
    int *array = (int*) malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++)
        array[i] = i;
    return array;
}

void
join_union(int *arr, int n, int p, int q)
{
    int pid = arr[p];
    int qid = arr[q];
    
    for (int i = 0; i < n; i++)
        if (arr[i] == pid)
            arr[i] = qid; 
}

int
connected(int* arr, int p, int q)
{
    return arr[p] == arr[q];
}

void
terminate(int* arr)
{
    free(arr);
}
