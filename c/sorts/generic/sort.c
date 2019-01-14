/*
 * Generic Sorting Algorithms
 * Author: Priyank Chheda 
 *         E: p.chheda29@gmail.com
 *         W: https://github.com/x899
 *
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sort.h"


/**
 * Swapping two array elements
 * @param a an integer to swap
 * @param b an integer to swap
 * @param elem_size size of each element
 */
static void
swap(void* x, void* y, size_t elem_size)
{
    void* temp = malloc(elem_size);
    memcpy(temp, x, elem_size);
    memcpy(x, y, elem_size);
    memcpy(y, temp, elem_size);
    free(temp);
}


/**
 * Bubble Sort Function
 *
 * Bubble sort is a simple sorting algorithm that repeatedly steps through
 * the list to be sorted, compares each pair of adjacent items and swaps
 * them if they are in the wrong order. The pass through the list is repeated
 * until no swaps are needed, which indicates that the list is sorted.
 *
 * @param array actual array to sort
 * @param elem_count number of elements in array
 * @param elem_size size of each element
 * @param compare pointer to compare function
 */
void
bubble_sort(void *array,
            size_t elem_count,
            size_t elem_size,
            compareFunction compare)
{
    int swapped;
    for (size_t i = 0; i < (elem_count - 1); i++)
    {
        swapped = 0;
        for (size_t j = 0; j < (elem_count - 1); j++)
        {
            void *elem1 = array + (j * elem_size);
            void *elem2 = array + ((j + 1) * elem_size);
            if (compare(elem1, elem2) > 0)
            {
                swap(elem1, elem2, elem_size);
                swapped = 1;
            }
        }
        if (swapped == 0)
            break;
    }
}


/**
 * Insertion Sort Function
 *
 * Insertion sort is based on the idea that one element from the input
 * elements is consumed in each iteration to find its correct position
 * i.e, the position to which it belongs in a sorted array.
 *
 * @param array actual array to sort
 * @param elem_count number of elements in array
 * @param elem_size size of each element
 * @param compare pointer to compare function
 */
void
insertion_sort( void* array,
                size_t elem_count,
                size_t elem_size,
                compareFunction compare)
{
    for (size_t i = 0; i < elem_count; i++)
    {
        int index = i;
        void *value = malloc(elem_size);
        memcpy(value, array + (i * elem_size), elem_size);
        
        while ( index > 0 &&
                compare(array + ((index - 1) * elem_size), value) > 0)
        {
            memcpy( array + (index * elem_size),
                    array + ((index - 1 ) * elem_size),
                    elem_size);
            index--;
        }
        memcpy(array + (index * elem_size), value, elem_size);
        free(value);
    }
}


/**
 * Selection Sort Function
 *
 * The selection sort algorithm sorts an array by repeatedly finding the
 * minimum element (considering ascending order) from unsorted part and 
 * putting it at the beginning. The algorithm maintains two subarrays in 
 * a given array.
 * - The subarray which is already sorted.
 * - Remaining subarray which is unsorted.
 *
 * In every iteration of selection sort, the minimum element (considering
 * ascending order) from the unsorted subarray is picked and moved to the
 * sorted subarray.
 *
 * @param array actual array to sort
 * @param elem_count number of elements in array
 * @param elem_size size of each element
 * @param compare pointer to compare function
 */
void
selection_sort( void *array,
                size_t elem_count,
                size_t elem_size,
                compareFunction compare)
{
    for (size_t i = 0; i < elem_count; i++)
    {
        int min_element_index = i;
        for (size_t j = i+1; j < elem_count; j++)
        {
            void *elem1 = array + (j * elem_size);
            void *elem2 = array + (min_element_index * elem_size);
            if (compare(elem1, elem2) < 0)
                min_element_index = j;
        }
        /* swap those two element */
        swap(   array + (i * elem_size),
                array + (min_element_index * elem_size),
                elem_size);
    }
}


/* Merge Function
 * @param array actual array to sort
 * @param elem_count number of elements in array
 * @param elem_size size of each element
 * @param compare pointer to compare function
 * @param low first index of the parital array
 * @param high last index of the parital array
 * @param mid middle index of the parital array
 */
static void
merge(  void *array,
        size_t elem_count,
        size_t elem_size,
        compareFunction compare,
        int low,
        int high,
        int mid)
{
    int i, j, k;
    void *temp_array = malloc((high-low+1) * elem_size);

    i = low;
    j = mid + 1;
    k = 0;

    while (i <= mid && j <= high)
    {
        void *elem1 = array + (i * elem_size);
        void *elem2 = array + (j * elem_size);
        if (compare(elem2, elem1) > 0)
        {
            memcpy(temp_array + (k * elem_size), elem1, elem_size);
            i++;
        }
        else
        {
            memcpy(temp_array + (k * elem_size), elem2, elem_size);
            j++;
        }
        k++;
    }

    while (i <= mid)
    {
        memcpy( temp_array + (k * elem_size),
                array + (i * elem_size),
                elem_size);
        i++;
        k++;
    }

    while (j <= high)
    {
        memcpy( temp_array + (k * elem_size),
                array + (j * elem_size),
                elem_size);
        j++;
        k++;
    }

    for (i = low; i <= high; i++)
        memcpy( array + (i * elem_size),
                temp_array + ((i - low) * elem_size),
                elem_size);

    free(temp_array);
}


/* Merge Sort Function
 * @param array actual array to sort
 * @param elem_count number of elements in array
 * @param elem_size size of each element
 * @param compare pointer to compare function
 * @param low first index of the parital array
 * @param high last index of the parital array
 */
static void
merge_sort_recursion(   void* array,
                        size_t elem_count,
                        size_t elem_size,
                        compareFunction compare,
                        int low,
                        int high)
{
    int mid;
    if (low < high)
    {
        mid = (low + high) / 2;
        merge_sort_recursion(   array, elem_count, elem_size,
                                compare, low, mid);
        merge_sort_recursion(   array, elem_count, elem_size,
                                compare, mid + 1, high);
        merge(array, elem_count, elem_size, compare,low, high, mid);
    }
}


/* Merge Sort Function
 *
 * Like QuickSort, Merge Sort is a Divide and Conquer algorithm. It divides
 * input array in two halves, calls itself for the two halves and then
 * merges the two sorted halves. The merge() function is used for merging
 * two halves. The merge(arr, l, m, r) is key process that assumes that
 * arr[l..m] and arr[m+1..r] are sorted and merges the two sorted
 * sub-arrays into one.
 *
 * @param array actual array to sort
 * @param elem_count number of elements in array
 * @param elem_size size of each element
 * @param compare pointer to compare function
 */
void
merge_sort( void *array,
            size_t elem_count,
            size_t elem_size,
            compareFunction compare)
{
    merge_sort_recursion(   array, elem_count, elem_size,
                            compare, 0, (int)elem_count - 1);
}


/**
 * Partition Element
 * @param array actual array to sort
 * @param elem_count number of elements in array
 * @param elem_size size of each element
 * @param compare pointer to compare function
 * @param start first index of the array
 * @param end last index of the array
 */
static int
partition(  void *array,
            size_t elem_count,
            size_t elem_size,
            compareFunction compare,
            int start,
            int end)
{
    void *pivot = array + (end * elem_size);
    int partitionIndex = start;
    for (int i = start; i < end; i++)
    {
        if (compare(array + (i * elem_size), pivot) < 0)
        {
            swap(   array + (i * elem_size),
                    array + (partitionIndex * elem_size),
                    elem_size);
            partitionIndex++;
        }
    }
    swap(   array + (end * elem_size),
            array + (partitionIndex * elem_size),
            elem_size);
    return partitionIndex;
}

/**
 * Get Randomized Partition element
 * @param array actual array to sort
 * @param elem_count number of elements in array
 * @param elem_size size of each element
 * @param compare pointer to compare function
 * @param start first index of the array
 * @param end last index of the array
 */
static int
randomizedPartition(void *array,
                    size_t elem_count,
                    size_t elem_size,
                    compareFunction compare,
                    int start,
                    int end)
{
    int pivotIndex = start + rand() % (end - start + 1);
    swap(   array + (end * elem_size),
            array + (pivotIndex * elem_size),
            elem_size);
    return partition(array, elem_count, elem_size, compare, start, end);
}

/**
 * Quick Sort Function
 * @param array actual array to sort
 * @param elem_count number of elements in array
 * @param elem_size size of each element
 * @param compare pointer to compare function
 * @param start first index of the array
 * @param end last index of the array
 */
static void
quick_sort_recursion(   void* array,
                        size_t elem_count,
                        size_t elem_size,
                        compareFunction compare,
                        int start,
                        int end)
{
    if (start < end)
    {
        int partitionIndex = randomizedPartition(
            array, elem_count, elem_size, compare, start, end);
        quick_sort_recursion(   array, elem_count, elem_size, compare,
                                start, partitionIndex - 1);
        quick_sort_recursion(   array, elem_count, elem_size, compare,
                                partitionIndex + 1, end);
    }
}


/**
 * Quick Sort Function
 *
 * Quick sort is based on the divide-and-conquer approach based on the idea
 * of choosing one element as a pivot element and partitioning the array
 * around it such that: Left side of pivot contains all the elements that
 * are less than the pivot element Right side contains all elements greater
 * than the pivot
 *
 * @param array actual array to sort
 * @param elem_count number of elements in array
 * @param elem_size size of each element
 * @param compare pointer to compare function
 */
void
quick_sort( void *array,
            size_t elem_count,
            size_t elem_size,
            compareFunction compare)
{
    quick_sort_recursion(   array, elem_count, elem_size, compare,
                            0, (int)elem_count - 1);
}


/*
 * Shell Sort Function
 *
 * ShellSort is mainly a variation of Insertion Sort. In insertion sort, we
 * move elements only one position ahead. When an element has to be moved far
 * ahead, many movements are involved. The idea of shellSort is to allow
 * exchange of far items. In shellSort, we make the array h-sorted for a large
 * value of h. We keep reducing the value of h until it becomes 1. An array is
 * said to be h-sorted if all sublists of every h’th element is sorted.
 *
 *
 * @param array actual array to sort
 * @param elem_count number of elements in array
 * @param elem_size size of each element
 * @param compare pointer to compare function
 */
void
shell_sort(void *array,
        size_t elem_count,
        size_t elem_size,
        compareFunction compare)
{
    size_t gap, i, j;
	for (gap = elem_count/2; gap > 0; gap /= 2)
    {
        for (i = gap; i < elem_count; i += 1)
        {
            void *value = malloc(elem_size);
            memcpy(value, array + (i * elem_size), elem_size);
            for (j = i; j >= gap && compare(array + ((j - gap) * elem_size),
                value) > 0; j -= gap)
            {
                memcpy( array + (j * elem_size),
                        array + ((j - gap) * elem_size),
                        elem_size);
            }
            memcpy(array + (j * elem_size), value, elem_size);

        }
    }
}
