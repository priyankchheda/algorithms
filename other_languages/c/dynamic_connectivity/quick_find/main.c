#include <stdio.h>
#include "quick_find.h"

int main()
{
    int n = 10;
    int *arr = initialize(n);

    join_union(arr, n, 4, 3);
    join_union(arr, n, 3, 8);
    join_union(arr, n, 6, 5);
    join_union(arr, n, 9, 4);
    join_union(arr, n, 2, 1);
    printf("%d\n", connected(arr, 0, 7));
    printf("%d\n", connected(arr, 8, 9));
    join_union(arr, n, 5, 0);
    join_union(arr, n, 7, 2);
    join_union(arr, n, 6, 1);
    join_union(arr, n, 1, 0);
    printf("%d\n", connected(arr, 0, 7));

    terminate(arr);
    return 0;
}
