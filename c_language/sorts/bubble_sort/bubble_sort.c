/*
 * Sorting Algorithms
 * Bubble Sort (C implementation)
 * Author: Priyank Chheda
 *         E: p.chheda29@gmail.com
 *         W: https://github.com/priyankchheda
 *
 * Bubble sort is a simple sorting algorithm that repeatedly steps through
 * the list to be sorted, compares each pair of adjacent items and swaps
 * them if they are in the wrong order. The pass through the list is repeated
 * until no swaps are needed, which indicates that the list is sorted.
 */

#include <stdio.h>


/* Function Declaration */
void bubble_sort(int array[], size_t array_size);
static void print_array(int array[], size_t array_size);
static void swap(int *a, int *b);


/* Main Operational Function */
int
main(int argc, char *argv[])
{
    int array[] = {229, 79, 46, 12, 58, 31, 34, 67, 89, 12, 67, 2};
    size_t array_size = sizeof(array) / sizeof(array[0]);
    bubble_sort(array, array_size);
    print_array(array, array_size);
    return 0;
}


/**
 * Bubble Sort Function
 * @param array actual array to sort
 * @param array_size size of array
 */
void
bubble_sort(int array[], size_t array_size)
{
    int swapped;
    for (size_t i = 0; i < (array_size - 1); i++)
    {
        swapped = 0;
        for (size_t j = 0; j < (array_size - 1); j++)
        {
            if (array[j] > array[j+1])
            {
                swap(&array[j], &array[j+1]);
                swapped = 1;
            }
        }
        if (swapped == 0)
            break;
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
