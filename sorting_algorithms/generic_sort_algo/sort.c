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
    char temp[elem_size];
    memcpy(temp, x, elem_size);
    memcpy(x, y, elem_size);
    memcpy(y, temp, elem_size);
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
