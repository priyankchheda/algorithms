#ifndef QUICK_FIND_H
#define QUICK_FIND_H

int* initialize(int n);
void join_union(int* arr, int n, int p, int q);
int connected(int* arr, int p, int q);
void terminate(int* arr);

#endif
