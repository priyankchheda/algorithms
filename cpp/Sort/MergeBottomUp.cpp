/*
 * Sorting Algorithms
 * Merge Sort (C++ implementation)
 *
 * Merge BottomUp algorithm first merges pairs of adjacent arrays of
 * 1 elements then merges pairs of adjacent arrays of 2 elements
 * and next merges pairs of adjacent arrays of 4 elements
 * and so on until the whole array is merged. Hence, completely avoiding
 * recursive approach.
 */

#include <iostream>

/* Function Declarations */
template <typename T>
void MergeSort(T data[], int dataLen);
template <typename T>
void merge(T data[], T aux[], int low, int mid, int high);

/* Main Driver Function */
int main() {
    int arr[] = {229, 79, 46, 12, 58, 31, 34, 67, 89, 12, 67, 2};
    int arr_size = sizeof(arr) / sizeof(arr[0]);

    MergeSort<int>(arr, arr_size);

    for (int a: arr)
        std::cout << a << " ";
    std::cout << "\n";

    return 0;
}

/**
 * Merge Sort Template Function
 * @param data actual array to sort
 * @param dataLen size of array
 */
template <typename T>
void MergeSort(T data[], int dataLen) {
    T aux[dataLen];
    for (int sz = 1; sz < dataLen; sz = sz + sz) {
        for (int low = 0; low < dataLen - sz; low += sz + sz) {
            merge<T>(data, aux, low, low + sz - 1,
                     std::min(low + sz + sz - 1, dataLen - 1));
        }
    }
}

/**
 * merge function for Merge Sort
 * @param data actual array to sort
 * @param low lower bound of partial array
 * @param mid middle of partial array
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