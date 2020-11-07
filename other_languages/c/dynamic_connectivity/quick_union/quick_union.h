#ifndef QUICK_UNION_H
#define QUICK_UNION_H

int* initialize(int n);
int* size_array_initialize(int n);
void join_union(int *arr, int *sz, int n, int p, int q);
int connected(int *arr, int p, int q);
void terminate(int *arr);

#endif
