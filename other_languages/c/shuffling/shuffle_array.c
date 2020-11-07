/*
 * Shuffling Algorithms (C implementation)
 * Author: Priyank Chheda
 *         E: p.chheda29@gmail.com
 *         W: https://github.com/x899
 *
 * Given an array, write a program to generate a random permutation of array
 * elements. This question is also asked as shuffle a deck of cards or
 * randomize a given array. Here shuffle means that every permutation of
 * array element should equally likely.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>


/* Function Declaration */
void shuffle(int array[], size_t array_size);
static void print_array(int array[], size_t array_size);
static void swap(int *a, int *b);


/* Main Operational Function */
int
main(int argc, char *argv[])
{
    int array[] = {229, 79, 46, 12, 58, 31, 34, 67, 89, 12, 67, 2};
    size_t array_size = sizeof(array) / sizeof(array[0]);
    srand(time(0));
    shuffle(array, array_size);
    print_array(array, array_size);
    return 0;
}


/**
 * Shuffle Array Function
 * @param array actual array to sort
 * @param array_size size of array
 */
void
shuffle(int array[], size_t array_size)
{
    /* By Using Fisher-Yates (Knuth) shuffle algorithm */
    for (int i = 0; i < array_size; i++)
    {
        int r = rand() % (i + 1);
        swap(&array[i], &array[r]);
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
