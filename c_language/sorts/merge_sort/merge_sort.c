/*
 * Sorting Algorithms
 * Merge Sort (C implementation)
 * Author: Priyank Chheda
 *         E: p.chheda29@gmail.com
 *         W: https://github.com/x899
 *
 * Like QuickSort, Merge Sort is a Divide and Conquer algorithm. It divides
 * input array in two halves, calls itself for the two halves and then
 * merges the two sorted halves. The merge() function is used for merging
 * two halves. The merge(arr, l, m, r) is key process that assumes that
 * arr[l..m] and arr[m+1..r] are sorted and merges the two sorted
 * sub-arrays into one.
 */

#include <stdio.h>


/* Function Declaration */
void merge_sort(int array[], int low, int high);
static void merge(int array[], int low, int high, int mid);
static void print_array(int array[], size_t array_size);


/* Main Operational Function */
int
main(int argc, char *argv[])
{
    int array[] = {229, 79, 46, 12, 58, 31, 34, 67, 89, 12, 67, 2};
    size_t array_size = sizeof(array) / sizeof(array[0]);
    merge_sort(array, 0, (int)array_size - 1);
    print_array(array, array_size);
    return 0;
}


/* Merge Sort Function
 * @param array partial array to sort
 * @param low first index of the parital array
 * @param high last index of the parital array
 */
void
merge_sort(int array[], int low, int high)
{
    int  mid;
	if (low < high)
    {
        mid = (low + high) / 2;
        merge_sort(array, low, mid);
        merge_sort(array, mid + 1, high);

        merge(array, low, high, mid);
    }
}


/* Merge Function
 * @param array partial array to sort
 * @param low first index of the parital array
 * @param high last index of the parital array
 * @param mid middle index of the parital array
 */
static void
merge(int array[], int low, int high, int mid)
{
    int i, j, k;
    int temp_array[high-low+1];
    i = low;
    j = mid + 1;
    k = 0;

    while (i <= mid && j <= high)
    {
        if (array[i] <= array[j])
        {
            temp_array[k] = array[i];
            i++;
        }
        else
        {
            temp_array[k] = array[j];
            j++;
        }
        k++;
    }

    while (i <= mid)
    {
        temp_array[k] = array[i];
        i++;
        k++;
    }

    while (j <= high)
    {
        temp_array[k] = array[j];
        j++;
        k++;
    }

    for (i = low; i <= high; i++)
        array[i] = temp_array[i - low];
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
