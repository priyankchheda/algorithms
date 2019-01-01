package main

import "fmt"

func merge(data []int, low int, mid int, high int) {
	aux := make([]int, high-low+1)
	i := low
	j := mid + 1
	k := 0

	for i <= mid && j <= high {
		if data[i] < data[j] {
			aux[k] = data[i]
			i++
		} else {
			aux[k] = data[j]
			j++
		}
		k++
	}

	for i <= mid {
		aux[k] = data[i]
		k++
		i++
	}

	for j <= high {
		aux[k] = data[j]
		k++
		j++
	}

	for i := low; i <= high; i++ {
		data[i] = aux[i-low]
	}
}

// MergeSort function implements Merge Sorting algorithm
func MergeSort(data []int, low int, high int) {
	if low < high {
		mid := (low + high) / 2
		MergeSort(data, low, mid)
		MergeSort(data, mid+1, high)
		merge(data, low, mid, high)
	}
}

func mergeSortInit() {
	data := []int{-229, 79, 46, 12, 58, 31, 34, 67, -89, 12, 67, 2}
	fmt.Println("\nUsing Merge Sort:")
	fmt.Println("Original Array: ", data)
	MergeSort(data, 0, len(data)-1)

	fmt.Println("  Sorted Array: ", data)
}
