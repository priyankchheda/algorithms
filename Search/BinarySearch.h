/**
 * Search Algorithm
 * Binary Search (C++ Implementation)
 *
 * BinarySearch is the most efficient searching algorithm having a run-time
 * complexity of O(log2 N). This algorithm works only on a sorted list of
 * elements.
 *
 * Binary search begins by comparing the middle element of the list with the
 * target element. If the target value matches the middle element, its position
 * in the list is returned. If it does not match, the list is divided into two
 * halves. The first half consists of the first element to middle element
 * whereas the second half consists of the element next to the middle element
 * to the last element.
*/

#include <iostream>

/**
 * Binary Search (Iterative Approach)
 * @param data pointer to sorted array
 * @param dataLend number of elements in array
 * @param value item that needs to be searched
*/
template <typename T>
int binarySearch(T* data, int dataLen, T value)
{
    int start = 0;
    int end = dataLen - 1;

    while (start <= end) {
        int median = (start + end) / 2;
        if (data[median] < value) {
            start = median + 1;
        } else if (data[median] > value) {
            end = median - 1;
        } else {
            return median;
        }
    }
    return -1;
}

/**
 * Binary Search (Recursive Approach)
 * @param data pointer to sorted array
 * @param start start index of sub-array
 * @param end end index of sub-array
 * @param value item that needs to be searched
*/
template <typename T>
int binarySearchRecursive(T* data, int start, int end, T value)
{
    if (start > end) {
        return -1;
    }

    int median = (start + end) / 2;
    if (data[median] == value) {
        return median;
    } else if (data[median] > value) {
        return binarySearchRecursive<T>(data, start, median-1, value);
    } else {
        return binarySearchRecursive<T>(data, median+1, end, value);
    }
    return -1;
}