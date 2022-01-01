/*
 * Sorting Algorithms
 * Counting Sort (C++ implementation)
 *
 * Counting sort is a sorting algorithm that sorts the elements of an array
 * by counting the number of occurrences of each unique element in the array.
 * The count is stored in an auxiliary array
 * and the sorting is done by mapping the count as an index of the auxiliary array.
 */

#include <iostream>

/* Function Declaration */
void CountSort(int arr[], int len);

/* Main Driver Function */
int main() {
    int arr[] = {229, 79, 46, -23, 12, 58, 31, 34, 67, 89, 12, 67, 2};
    int arr_size = sizeof(arr) / sizeof(arr[0]);

    CountSort(arr, arr_size);

    for (int a: arr)
        std::cout << a << " ";
    std::cout << "\n";

    return 0;
}

/**
 * Count Sort Function
 * @param arr actual array to sort
 * @param len size of array
 */
void CountSort(int arr[], int len) {
    int minElement = *std::min_element(arr, arr+len);
    int maxElement = *std::max_element(arr, arr+len);

    int outputLen = maxElement - minElement + 1;
    int count[outputLen];
    int output[outputLen];

    // initialize count and output array to all zero
    for (int i = 0; i < outputLen; i++) {
        count[i] = 0;
        output[i] = 0;
    }

    // increase number count in count array.
    for (int i = 0; i < len; i++) {
        count[arr[i] - minElement]++;
    }

    // find cumulative frequency
    for (int i = 1; i < outputLen; i++) {
        count[i] += count[i-1];
    }

    for (int i = 0; i < len; i++) {
		output[count[arr[i]-minElement]-1] = arr[i];
		count[arr[i]-minElement]--; //decrease count for same numbers
	}

    // store output array to main array
    for (int i = 0; i < len; i++) {
      arr[i] = output[i];
   }
}
