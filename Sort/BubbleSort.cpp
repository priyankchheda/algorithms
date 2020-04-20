/*
 * Sorting Algorithms
 * Bubble Sort (C++ implementation)
 *
 * Bubble sort is a simple sorting algorithm that repeatedly steps through
 * the list to be sorted, compares each pair of adjacent items and swaps
 * them if they are in the wrong order. The pass through the list is repeated
 * until no swaps are needed, which indicates that the list is sorted.
 */

#include <iostream>

/**
 * Bubble Sort Template Function
 * @param arr actual array to sort
 * @param len size of array
 */
template <typename T>
void BubbleSort(T arr[], int len) {
    bool swapped = false;
    for (int i = 0; i < len-1; i++) {
        for (int j = 0; j < len-1; j++) {
            if (arr[j] > arr[j+1]) {
                std::swap(arr[j], arr[j+1]);
                swapped = true;
            }
        }
        if (!swapped)
            break;
    }
}

/* Main Driver Function */
int main() {
    int arr[] = {229, 79, 46, 12, 58, 31, 34, 67, 89, 12, 67, 2};
    int arr_size = sizeof(arr) / sizeof(arr[0]);

    BubbleSort<int>(arr, arr_size);

    for (int a: arr)
        std::cout << a << " ";
    std::cout << "\n";

    return 0;
}