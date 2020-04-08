/*
 * Sorting Algorithms
 * Quick Sort (C implementation)
 * Author: Priyank Chheda 
 *         E: p.chheda29@gmail.com
 *         W: https://github.com/x899
 * Quick sort is based on the divide-and-conquer approach based on the idea
 * of choosing one element as a pivot element and partitioning the array
 * around it such that: Left side of pivot contains all the elements that
 * are less than the pivot element Right side contains all elements greater
 * than the pivot
 */

#include <stdio.h>
#include <stdlib.h>


/* Function Declaration */
void quick_sort(int array[], int start, int end);
static int partition(int array[], int start, int end);
static int randomizedPartition(int array[], int start, int end);
static void print_array(int array[], size_t array_size);
static void swap(int *a, int *b);


/* Main Operational Function */
int
main(int argc, char *argv[])
{
    int array[] = {229, 79, 46, 12, 58, 31, 34, 67, 89, 12, 67, 2};
    size_t array_size = sizeof(array) / sizeof(array[0]);
    quick_sort(array, 0, (int)array_size - 1);
    print_array(array, array_size);
    return 0;
}


/**
 * Quick Sort Function
 * @param array actual array to sort
 * @param array_size size of array
 */
void
quick_sort(int array[], int start, int end)
{
    if (start < end)
    {
        int partitionIndex = randomizedPartition(array, start, end);
        quick_sort(array, start, partitionIndex - 1);
        quick_sort(array, partitionIndex + 1, end);
    }
}

/* Get Randomized Partition element
 * @param array actual array to sort
 * @param start first index of the array (usually 0)
 * @param end last index of the array
 */

static int
randomizedPartition(int array[], int start, int end)
{
    int pivotIndex = start + rand() % (end - start + 1);
    swap(&array[end], &array[pivotIndex]);
    return partition(array, start, end);
}


/**
 * Partition Element
 * @param array partial array to sort
 * @param start first index of the partial array
 * @param end last index of the partial array
 */
static int
partition(int array[], int start, int end)
{
    int pivot = array[end];
    int partitionIndex = start;
    for (int i = start; i < end; i++)
    {
        if (array[i] <= pivot)
        {
            swap(&array[i], &array[partitionIndex]);
            partitionIndex++;
        }
    }
    swap(&array[end], &array[partitionIndex]);
    return partitionIndex;
}

/**
 * Pretty print array Function
 * @param array actual array to sort
 * @param array_size size of array
 */
static void
print_array(int array[], size_t array_size)
{
    for (size_t i = 0; i < array_size; i++)
    {
        printf("%d ", array[i]);
    }
    printf("\n");
}

/**
 * Swapping two array elements
 * @param a an integer to swap
 * @param b an integer to swap
 */
static void
swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
