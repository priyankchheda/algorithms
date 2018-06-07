/* Sorting Test Function */

#include <stdio.h>
#include "sort.h"


/* Function Declaration */
int compare_int(void*, void*);
int compare_float(void*, void*);
void print_array(void*, size_t, size_t);


/* Main Operational Function */
int
main(int argc, char *argv[])
{
    // int array[] = {229, 79, 46, 12, 58, 31, 34, 67, 89, 12, 67, 2};
    float array[] = {229.56, 79.34, 46.67, 12.3, 58.56, 31.78, 34.78, 67.2,
                    89.98, 12.34, 67.78, 2.8};
    size_t elem_count = sizeof(array) / sizeof(array[0]);
    size_t elem_size = sizeof(array[0]);
    
    printf("Original Array: ");
    print_array(array, elem_count, elem_size);
    // bubble_sort(array, elem_count, elem_size, compare_int);
    insertion_sort(array, elem_count, elem_size, compare_float);
    // selection_sort(array, elem_count, elem_size, compare_int);
    printf("Sorted Array:   ");
    print_array(array, elem_count, elem_size);
}


/**
 * Pretty print array Function
 * @param array actual array to sort
 * @param elem_count number of elements in array
 * @param elem_size size of each element
 */
void
print_array(void* array, size_t elem_count, size_t elem_size)
{
    for (size_t i = 0; i < elem_count; i++)
    {
        void *p = array + (i * elem_size);
        // printf("%d ", *((int*)p));
        printf("%.2f ", *((float*)p));
    }
    printf("\n");
}


/* Integer Comparison Function */
int
compare_int(void* elem1, void* elem2)
{
    int *p1 = (int*) elem1;
    int *p2 = (int*) elem2;
    return *p1 - *p2; 
}


/* Float Comparison Function */
int
compare_float(void* elem1, void* elem2)
{
    float *p1 = (float*) elem1;
    float *p2 = (float*) elem2;
    return *p1 - *p2; 
}
