/*
 * Sorting Algorithms
 * Merge Sort (C++ implementation)
 *
 * MergeSort (optimized version) function implements optimized version of Merge Sorting
 * algorithm. It uses Insertion sort for dataset with less than or equal to 7
 * elements. It also stops if data is already sorted i.e biggest item in first
 * half is less than or equal to smallest item in seconh half. It is useful for
 * partially-ordered arrays. We also pass auxillary array to this function
 * because creating auxillary array in the recusive routine lead to extensive
 * cost of extra array creation.
 */

#include <iostream>
#define CUTOFF 7

/* Function Declarations */
template <typename T>
void MergeSort(T data[], T aux[], int low, int high);
template <typename T>
void merge(T data[], T aux[], int low, int mid, int high);
template <typename T>
void InsertionSort(T arr[], int low, int high);

/* Main Driver Function */
int main() {
    int arr[] = {229, 79, 46, 12, 58, 31, 34, 67, 89, 12, 67, 2};
    // char arr[] = {'d', 't', 'a', 'b', 'q', 'z', 'd', 'e', 'x'};
    int arr_size = sizeof(arr) / sizeof(arr[0]);

    int aux[arr_size];
    MergeSort<int>(arr, aux, 0, arr_size - 1);

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
void MergeSort(T data[], T aux[], int low, int high) {
    if (high <= low + CUTOFF - 1) {
        InsertionSort<T>(data, low, high);
    }

    if (low < high) {
        int mid = (low + high) / 2;
        MergeSort<T>(data, aux, low, mid);
        MergeSort<T>(data, aux, mid+1, high);

        // stop if already sorted
        // iff biggest item in fist half <= smallest item in second half
        // helps for partially-ordered arrays
        if (data[mid] <= data[mid+1]) {
            return;
        }
        merge(data, aux, low, mid, high);
    }
}

/**
 * Insertion Sort Template Function
 * @param arr actual array to sort
 * @param len size of array
 */
template <typename T>
void InsertionSort(T arr[], int low, int high) {
    for (int i = low; i <= high; i++) {
        int index = i;
        int value = arr[i];
        while (index > 0 && arr[index-1] > value) {
            arr[index] = arr[index-1];
            index--;
        }
        arr[index] = value;
    }
}

/**
 * merge function for MergeSort
 * @param data actual array to sort
 * @param low lower bound of partial array
 * @param high upper bound of partial array
*/
template <typename T>
void merge(T data[], T aux[], int low, int mid, int high) {
    for (int k = low; k <= high; k++) {
        aux[k] = data[k];
    }

    int i = low;
    int j = mid + 1;
    for (int k = low; k <= high; k++){
        if (i > mid) {
            data[k] = aux[j];
            j++;
        } else if (j > high) {
            data[k] = aux[i];
            i++;
        } else if (aux[j] < aux[i]) {
            data[k] = aux[j];
            j++;
        } else {
            data[k] = aux[i];
            i++;
        }
    }
}