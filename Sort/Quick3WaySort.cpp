/*
 * Sorting Algorithms
 * Quick Sort (C++ implementation)
 *
 * Quick 3Way Sort is a variant of Quick Sort 3-way partitioning.
 * 3-way quicksort is optimization which works in specific cases like when
 * input to be sorted contains few unique keys, in this case having
 * traditional approach of one pivot does not perform well compared to
 * 3-way quicksort.
 */

#include <iostream>

/* Function Declarations */
template <typename T>
void QuickSort(T data[], int low, int high);

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

    int lt = low;
	int gt = high;
	T pivot = data[low];
	int i = low;

	while (i <= gt) {
		if (data[i] < pivot) {
			std::swap(data[lt], data[i]);
			lt++;
			i++;
		} else if (data[i] > pivot) {
			std::swap(data[gt], data[i]);
			gt--;
		} else {
			i++;
		}
	}

	QuickSort(data, low, lt-1);
	QuickSort(data, gt+1, high);
}
