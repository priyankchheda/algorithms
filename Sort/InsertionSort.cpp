/*
 * Sorting Algorithms
 * Insertion Sort (C++ implementation)
 *
 * Insertion sort is based on the idea that one element from the input
 * elements is consumed in each iteration to find its correct position
 * i.e, the position to which it belongs in a sorted array.
 */

#include <iostream>

/**
 * Insertion Sort Template Function
 * @param arr actual array to sort
 * @param len size of array
 */
template <typename T>
void InsertionSort(T arr[], int len) {
    for (int i = 0; i < len; i++) {
        int index = i;
        int value = arr[i];
        while (index > 0 && arr[index-1] > value) {
            arr[index] = arr[index-1];
            index--;
        }
        arr[index] = value;
    }
}

/* Main Driver Function */
int main() {
    int arr[] = {229, 79, 46, 12, 58, 31, 34, 67, 89, 12, 67, 2};
    int arr_size = sizeof(arr) / sizeof(arr[0]);

    InsertionSort<int>(arr, arr_size);

    for (int a: arr)
        std::cout << a << " ";
    std::cout << "\n";

    return 0;
}