/*
 * Generic Sorting Algorithms
 * Author: Priyank Chheda 
 *         E: p.chheda29@gmail.com
 *         W: https://github.com/x899
 *
 */


#ifndef SORT_H
#define SORT_H

typedef int (*compareFunction)(void*, void*);

/* Sort Function Declaration */
void bubble_sort(void*, size_t, size_t, compareFunction);
void insertion_sort(void*, size_t, size_t, compareFunction);
void selection_sort(void*, size_t, size_t, compareFunction);
void merge_sort(void*, size_t, size_t, compareFunction);
void quick_sort(void*, size_t, size_t, compareFunction);
void shell_sort(void*, size_t, size_t, compareFunction);

#endif
