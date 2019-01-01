package main

import "fmt"

const cutoff int = 7

func insertionSort(data []int) {
	dataLen := len(data)

	for i := 0; i < dataLen; i++ {
		index := i
		value := data[i]

		for index > 0 && data[index-1] > value {
			data[index] = data[index-1]
			index--
		}
		data[index] = value
	}
}

func mergeOptimized(data []int, aux []int, low int, mid int, high int) {
	for k := low; k <= high; k++ {
		aux[k] = data[k]
	}

	i := low
	j := mid + 1
	for k := low; k <= high; k++ {
		if i > mid {
			data[k] = aux[j]
			j++
		} else if j > high {
			data[k] = aux[i]
			i++
		} else if aux[j] < aux[i] {
			data[k] = aux[j]
			j++
		} else {
			data[k] = aux[i]
			i++
		}
	}
}

// MergeSortOptimized function implements optimized version of Merge Sorting
// algorithm
func MergeSortOptimized(data []int, aux []int, low int, high int) {
	if high <= low+cutoff-1 {
		insertionSort(data[low:high])
	}

	if low < high {
		mid := (low + high) / 2
		MergeSortOptimized(data, aux, low, mid)
		MergeSortOptimized(data, aux, mid+1, high)

		// stop if already sorted
		// iff biggest item in fist half <= smallest item in second half
		// helps for partially-ordered arrays
		if data[mid] <= data[mid+1] {
			return
		}
		mergeOptimized(data, aux, low, mid, high)
	}
}

func mergeSortOptimizedInit() {
	data := []int{-229, 79, 46, 12, 58, 31, 34, 67, -89, 12, 67, 2}
	fmt.Println("\nUsing Optimized Merge Sort:")
	fmt.Println("Original Array: ", data)

	// It's important to not create auxillary array in the recursive routine
	// because that code lead to extensive cost of extra array creation
	aux := make([]int, len(data))
	MergeSortOptimized(data, aux, 0, len(data)-1)

	fmt.Println("  Sorted Array: ", data)
}
