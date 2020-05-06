/*
 * Sorting Algorithms
 * Heap Sort (C++ implementation)
 *
 * HeapSort is a comparison based sorting technique based on Binary Heap
 * data structure. It is similar to selection sort where we first find the
 * maximum element and place the maximum element at the end. We repeat the
 * same process for remaining element. Heap Sort is not stable, In-place
 * sorting algorithm with guarantee NlogN time complexity in worst-case.
 */

#include <iostream>

/* Function declarations */
template <typename T>
void HeapSort(T data[], int dataLen);
template <typename T>
void heapify(T data[], int root, int length);
template <typename T>
void buildHeap(T data[], int dataLen);

/* Main Driver Function */
int main() {
    char arr[] = {'d', 't', 'a', 'b', 'q', 'z', 'd', 'e', 'x'};
    int arr_size = sizeof(arr) / sizeof(arr[0]);

    HeapSort<char>(arr, arr_size);

    for (char a: arr)
        std::cout << a << " ";
    std::cout << "\n";

    return 0;
}

/**
 * Heap Sort Template Function
 * @param data actual array to sort
 * @param dataLen size of array
 */
template <typename T>
void HeapSort(T data[], int dataLen)
{
    buildHeap<T>(data, dataLen);
    for (int i = dataLen - 1; i > 0; i--) {
        std::swap(data[0], data[i]);
        heapify<T>(data, 0, i);
    }
}

/* heapify maintains the heap invariant (property) */
template <typename T>
void heapify(T data[], int root, int length)
{
    int max = root;
    int left = 2 * root + 1;
    int right = 2 * root + 2;

    if (left < length && data[left] > data[max]) {
        max = left;
    }

    if (right < length && data[right] > data[max]) {
        max = right;
    }

    if (max != root) {
        std::swap(data[root], data[max]);
        heapify<T>(data, max, length);
    }
}

/**
 * buildHeap builds heap structure from an unorganized data list
 * Time complexity of building a heap is O(n)
 * @param data actual array to sort
 * @param dataLen size of array
*/
template <typename T>
void buildHeap(T data[], int dataLen)
{
    for (int i = dataLen / 2; i >= 0; i--) {
        heapify<T>(data, i, dataLen);
    }
}

