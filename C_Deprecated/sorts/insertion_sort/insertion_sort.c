/*
 * Sorting Algorithms
 * Insertion Sort (C implementation)
 * Author: Priyank Chheda 
 *         E: p.chheda29@gmail.com
 *         W: https://github.com/x899
 *
 * Insertion sort is based on the idea that one element from the input
 * elements is consumed in each iteration to find its correct position
 * i.e, the position to which it belongs in a sorted array.
 */

#include <stdio.h>


/* Function Declaration */
void insertion_sort(int array[], size_t array_size);
static void print_array(int array[], size_t array_size);


/* Main Operational Function */
int
main(int argc, char *argv[])
{
    int array[] = {229, 79, 46, 12, 58, 31, 34, 67, 89, 12, 67, 2};
    size_t array_size = sizeof(array) / sizeof(array[0]);
    insertion_sort(array, array_size);
    print_array(array, array_size);
    return 0;
}


/**
 * Insertion Sort Function
 * @param array actual array to sort
 * @param array_size size of array
 */
void
insertion_sort(int array[], size_t array_size)
{
    int index, value;
    for (size_t i = 0; i < array_size; i++)
    {
        index = i;
        value = array[i];
        while (index > 0 && array[index-1] > value)
        {
            array[index] = array[index - 1];
            index--;
        }
        array[index] = value;
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
