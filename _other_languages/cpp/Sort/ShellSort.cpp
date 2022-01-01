/*
 * Sorting Algorithms
 * Shell Sort (C++ implementation)
 *
 * ShellSort is mainly a variation of Insertion Sort. In insertion sort, we
 * move elements only one position ahead. When an element has to be moved far
 * ahead, many movements are involved. The idea of shellSort is to allow
 * exchange of far items. In shellSort, we make the array h-sorted for a large
 * value of h. We keep reducing the value of h until it becomes 1. An array is
 * said to be h-sorted if all sublists of every h’th element is sorted.
 */
#include <iostream>

/* Function Declarations */
template <typename T>
void ShellSort(T data[], int dataLen);

/* Main Driver Function */
int main() {
    int arr[] = {229, 79, 46, 12, 58, 31, 34, 67, 89, 12, 67, 2};
    int arr_size = sizeof(arr) / sizeof(arr[0]);

    ShellSort<int>(arr, arr_size);

    for (int a: arr)
        std::cout << a << " ";
    std::cout << "\n";

    return 0;
}

/**
 * Shell Sort Template Function
 * @param data actual array to sort
 * @param dataLen size of array
 */
template <typename T>
void ShellSort(T data[], int dataLen) {
    int h = 1;
    while (h < dataLen / 3) {
        h = (h * 3) + 1;
    }

    while (h >= 1) {
        // h-sort the array
        for (int i = h; i < dataLen; i++) {
            for (int j = i; j >= h && data[j] < data[j - h]; j = j - h) {
                std::swap(data[j], data[j - h]);
            }
        }
        h = h / 3;
    }
}