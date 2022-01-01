/*
 * Sorting Algorithms
 * Quick Sort (C++ implementation)
 *
 * QuickSort is a Divide and Conquer algorithm.
 * It picks an element as pivot and partitions the given array around the
 * picked pivot. It uses last element as pivot element
 */

#include <iostream>
#define CUTOFF 7

/* Function Declarations */
template <typename T>
T QuickSelect(T data[], int dataLen, int key);
template <typename T>
int partition(T data[], int low, int high);
template <typename T>
int medianOfThree(T data[], int low, int high);
template <typename T>
void Shuffle(T arr[], int len);

/* Main Driver Function */
int main() {
    int arr[] = {229, 79, 46, 12, 58, 31, 34, 67, 89, 12, 67, 2};
    // char arr[] = {'d', 't', 'a', 'b', 'q', 'z', 'd', 'e', 'x'};
    int arr_size = sizeof(arr) / sizeof(arr[0]);

    int result = QuickSelect<int>(arr, arr_size, 3);
    std::cout << "3rd sorted element is " << result << "\n";
    return 0;
}

/**
 * Shuffle Array Template Function
 * @param arr actual array to sort
 * @param len size of array
 */
template <typename T>
void Shuffle(T arr[], int len)
{
     // use current time as seed for random generator
    std::srand(std::time(nullptr));
    for (int i = 0; i < len; i++) {
        int r = rand() % (i + 1);
        std::swap(arr[i], arr[r]);
    }
}


/**
 * Quick Sort Template Function
 * @param data actual array to sort
 * @param dataLen size of actual array
 * @param key index of which sorted element is required
 */
template <typename T>
T QuickSelect(T data[], int dataLen, int key)
{
    if (key >= dataLen) {
        return -1;
    }

    Shuffle<T>(data, dataLen);
    int low = 0;
    int high = dataLen - 1;

    while (high > low) {
        int j = partition(data, low, high);
        if (j < key) {
            low = j + 1;
        } else if (j > key) {
            high = j - 1;
        } else {
            return data[key];
        }
    }
    return data[key];
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
    int median = medianOfThree(data, low, high);
    std::swap(data[median], data[high]);

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

/**
 * medianOfThree to return pivot index
 * @param data actual array to sort
 * @param low lower bound of partial array
 * @param high upper bound of partial array
*/
template <typename T>
int medianOfThree(T data[], int low, int high)
{
    int mid = (low + high) / 2;
    if (data[high] < data[low]) {
        std::swap(data[high], data[low]);
    }
    if (data[low] > data[mid]) {
        std::swap(data[mid], data[low]);
    }
    if (data[mid] > data[high]) {
        std::swap(data[high], data[mid]);
    }
    return mid;
}