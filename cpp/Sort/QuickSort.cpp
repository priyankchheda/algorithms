/*
 * Sorting Algorithms
 * Quick Sort (C++ implementation)
 *
 * QuickSort is a Divide and Conquer algorithm.
 * It picks an element as pivot and partitions the given array around the
 * picked pivot. It uses last element as pivot element
 */

#include <iostream>

/* Function Declarations */
template <typename T>
void QuickSort(T data[], int low, int high);
template <typename T>
int partition(T data[], int low, int high);

/* Main Driver Function */
int main() {
    int arr[] = {229, 79, 46, 12, 58, 31, 34, 67, 89, 12, 67, 2};
    int arr_size = sizeof(arr) / sizeof(arr[0]);

    QuickSort<int>(arr, 0, arr_size - 1);

    for (int a: arr)
        std::cout << a << " ";
    std::cout << "\n";

    return 0;
}

/**
 * Quick Sort Template Function
 * @param data actual array to sort
 * @param low lower bound of partial array
 * @param high upper bound of partial array
 */
template <typename T>
void QuickSort(T data[], int low, int high)
{
    if (high <= low) {
        return;
    }
    int j = partition(data, low, high);
    QuickSort(data, low, j-1);
    QuickSort(data, j+1, high);
}

/**
 * partition return partition index of pivot
 * @param data actual array to sort
 * @param low lower bound of partial array
 * @param high upper bound of partial array
*/
template <typename T>
int partition(T data[], int low, int high)
{
    T pivot = data[high];
    int partitionIndex = low;
    for (int i = low; i < high; i++) {
        if (data[i] <= pivot) {
            std::swap(data[i], data[partitionIndex]);
            partitionIndex++;
        }
    }
    std::swap(data[high], data[partitionIndex]);
    return partitionIndex;
}