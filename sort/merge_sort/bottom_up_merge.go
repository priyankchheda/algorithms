package main

import (
	"fmt"
)

func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

func mergeBottomUp(data []int, aux []int, low int, mid int, high int) {
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

// MergeSortBottomUp function implements optimized version of Merge Sorting
// algorithm
func MergeSortBottomUp(data []int) {
	dataLen := len(data)
	aux := make([]int, dataLen)

	for sz := 1; sz < dataLen; sz = sz + sz {
		for low := 0; low < dataLen-sz; low += sz + sz {
			mergeBottomUp(data, aux, low, low+sz-1, min(low+sz+sz-1, dataLen-1))
		}
	}
}

func mergeSortBottomUpInit() {
	data := []int{-229, 79, 46, 12, 58, 31, 34, 67, -89, 12, 67, 2}
	fmt.Println("\nUsing Bottom-up Merge Sort:")
	fmt.Println("Original Array: ", data)
	MergeSortBottomUp(data)
	fmt.Println("  Sorted Array: ", data)
}
