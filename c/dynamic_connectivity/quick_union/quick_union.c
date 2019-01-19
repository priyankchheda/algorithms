#include <stdlib.h>
#include "quick_union.h"

int *
initialize(int n)
{
    int *arr = (int *) malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++)
        arr[i] = i;
    return arr;
}

int *
size_array_initialize(int n)
{
    int *arr = (int *) malloc(sizeof(int) * n);
    for (int i = 0; i < n; i++)
        arr[i] = 1;
    return arr;
}

static int
root(int *arr, int p)
{
    while (p != arr[p])
    {
        // path compression
        arr[p] = arr[arr[p]];
        p = arr[p];
    }
    return p;
}

void
join_union(int *arr, int *sz, int n, int p, int q)
{
    int a = root(arr, p);
    int b = root(arr, q);

    // weighted quick union
    if (a == b) return;
    if (sz[a] > sz[b]) {
        arr[b] = a;
        sz[b] += sz[a];
    } else {
        arr[a] = b;
        sz[a] += sz[b];
    }
}

int
connected(int *arr, int p, int q)
{
    return root(arr, p) == root(arr, q);
}

void
terminate(int *arr)
{
    free(arr);
}
