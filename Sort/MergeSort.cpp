/*
 * Sorting Algorithms
 * Merge Sort (C++ implementation)
 *
 * MergeSort is a Divide and Conquer algorithm. It divides input array in two
 * halves, calls itself for the two halves and then merges the two sorted
 * halves.
 */

#include <iostream>

/* Function Declarations */
template <typename T>
void MergeSort(T data[], int low, int high);
template <typename T>
void merge(T data[], int low, int mid, int high);

/* Main Driver Function */
int main() {
    int arr[] = {229, 79, 46, 12, 58, 31, 34, 67, 89, 12, 67, 2};
    int arr_size = sizeof(arr) / sizeof(arr[0]);

    MergeSort<int>(arr, 0, arr_size - 1);

    for (int a: arr)
        std::cout << a << " ";
    std::cout << "\n";

    return 0;
}

/**
 * Merge Sort Template Function
 * @param data actual array to sort
 * @param low lower bound of partial array
 * @param high upper bound of partial array
 */
template <typename T>
void MergeSort(T data[], int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;
        MergeSort(data, low, mid);
        MergeSort(data, mid+1, high);
        merge(data, low, mid, high);
    }
}

/**
 * merge function for MergeSort
 * @param data actual array to sort
 * @param low lower bound of partial array
 * @param high upper bound of partial array
*/
template <typename T>
void merge(T data[], int low, int mid, int high) {
    T aux[high - low + 1];
    int i = low;
    int j = mid + 1;
    int k = 0;

    while (i <= mid && j <= high) {
        if (data[i] < data[j]) {
            aux[k] = data[i];
            i++;
        } else {
            aux[k] = data[j];
            j++;
        }
        k++;
    }

    while (i <= mid) {
        aux[k] = data[i];
        k++;
        i++;
    }

    while (j <= high) {
        aux[k] = data[j];
        k++;
        j++;
    }

    for (i = low; i <= high; i++) {
        data[i] = aux[i-low];
    }
}