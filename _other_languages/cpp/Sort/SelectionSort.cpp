/*
 * Sorting Algorithms
 * Selection Sort (C++ implementation)
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

#include <iostream>

/**
 * Selection Sort Template Function
 * @param arr actual array to sort
 * @param len size of array
 */
template <typename>
void SelectionSort(int arr[], size_t len)
{
    for (int i = 0; i < len; i++) {
        int min_element_index = i;
        for (int j = i+1; j < len; j++) {
            if (arr[j] < arr[min_element_index])
                min_element_index = j;
        }
        std::swap(arr[i], arr[min_element_index]);
    }
}

/* Main Driver Function */
int main() {
    int arr[] = {229, 79, 46, 12, 58, 31, 34, 67, 89, 12, 67, 2};
    int arr_size = sizeof(arr) / sizeof(arr[0]);

    SelectionSort<int>(arr, arr_size);

    for (int a: arr)
        std::cout << a << " ";
    std::cout << "\n";

    return 0;
}