/*
 * Sorting Algorithms
 * Selection Sort (C implementation)
 * Author: Priyank Chheda
 *         E: p.chheda29@gmail.com
 *         W: https://github.com/x899
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
 */

#include <stdio.h>


/* Function Declaration */
void selection_sort(int array[], size_t array_size);
static void print_array(int array[], size_t array_size);
static void swap(int *a, int *b);


/* Main Operational Function */
int
main(int argc, char *argv[])
{
    int array[] = {229, 79, 46, 12, 58, 31, 34, 67, 89, 12, 67, 2};
    size_t array_size = sizeof(array) / sizeof(array[0]);
    selection_sort(array, array_size);
    print_array(array, array_size);
    return 0;
}


/**
 * Selection Sort Function
 * @param array actual array to sort
 * @param array_size size of array
 */
void
selection_sort(int array[], size_t array_size)
{
    for (size_t i = 0; i < array_size; i++)
    {
        int min_element_index = i;
        for (size_t j = i+1; j < array_size; j++)
        {
            if (array[j] < array[min_element_index])
                min_element_index = j;
        }

        /* swap those two element */
        swap(&array[i], &array[min_element_index]);
    }
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
