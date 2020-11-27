#include <stdio.h>
#include "quick_union.h"

int main()
{
    int n = 10;
    int *arr = initialize(n);
    int *sz = size_array_initialize(n);

    join_union(arr, sz, n, 4, 3);
    join_union(arr, sz, n, 3, 8);
    join_union(arr, sz, n, 6, 5);
    join_union(arr, sz, n, 9, 4);
    join_union(arr, sz, n, 2, 1);
    printf("%d\n", connected(arr, 0, 7));
    printf("%d\n", connected(arr, 8, 9));
    join_union(arr, sz, n, 5, 0);
    join_union(arr, sz, n, 7, 2);
    join_union(arr, sz, n, 6, 1);
    join_union(arr, sz, n, 1, 0);
    printf("%d\n", connected(arr, 0, 7));

    terminate(arr);
    return 0;
}
