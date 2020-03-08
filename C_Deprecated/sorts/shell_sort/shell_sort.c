/*
 * Sorting Algorithms
 * Shell Sort (C implementation)
 * Author: Priyank Chheda 
 *         E: p.chheda29@gmail.com
 *         W: https://github.com/x899
 *
 * ShellSort is mainly a variation of Insertion Sort. In insertion sort, we
 * move elements only one position ahead. When an element has to be moved far
 * ahead, many movements are involved. The idea of shellSort is to allow
 * exchange of far items. In shellSort, we make the array h-sorted for a large
 * value of h. We keep reducing the value of h until it becomes 1. An array is
 * said to be h-sorted if all sublists of every h’th element is sorted.
 */

#include <stdio.h>


/* Function Declaration */
void shell_sort(int array[], size_t array_size);
static void print_array(int array[], size_t array_size);


/* Main Operational Function */
int
main(int argc, char *argv[])
{
    int array[] = {229, 79, 46, 12, 58, 31, 34, 67, 89, 12, 67, 2};
    size_t array_size = sizeof(array) / sizeof(array[0]);
    shell_sort(array, array_size);
    print_array(array, array_size);
    return 0;
}


/**
 * Shell Sort Function
 * @param array actual array to sort
 * @param array_size size of array
 */
void
shell_sort(int array[], size_t array_size)
{
	int gap, i, j, value;
	for (gap = array_size/2; gap > 0; gap /= 2) {
        for (i = gap; i < array_size; i += 1) {
            value = array[i];
            for (j = i; j >= gap && array[j-gap] > value; j -= gap) {
                array[j] = array[j - gap];
            }
            array[j] = value;
        }
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
