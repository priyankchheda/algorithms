package main

import (
	"fmt"
	"math/rand"
	"time"
)

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

func shuffleOptimized(data []int) {
	random := rand.New(rand.NewSource(time.Now().UnixNano()))
	for i := 0; i < len(data); i++ {
		r := random.Intn(i + 1)
		data[i], data[r] = data[r], data[i]
	}
}

func medianOfThree(data []int, low int, high int) int {
	mid := (low + high) / 2
	if data[high] < data[low] {
		data[low], data[high] = data[high], data[low]
	}
	if data[low] > data[mid] {
		data[low], data[mid] = data[mid], data[low]
	}
	if data[mid] > data[high] {
		data[mid], data[high] = data[high], data[mid]
	}
	return mid
}

func partitionOptimized(data []int, low int, high int) int {
	pivot := data[high]
	partitionIndex := low
	for i := low; i < high; i++ {
		if data[i] <= pivot {
			data[i], data[partitionIndex] = data[partitionIndex], data[i]
			partitionIndex++
		}
	}
	data[high], data[partitionIndex] = data[partitionIndex], data[high]
	return partitionIndex
}

// QuickSortOptimized is go implementation of Optimized Quick Sort
func QuickSortOptimized(data []int, low int, high int) {
	if high <= low {
		return
	}

	// use insertion sort for data set of size <=7
	if high <= low+cutoff-1 {
		insertionSort(data[low : high+1])
		return
	}

	// Use median of Three to find the Pivot index
	median := medianOfThree(data, low, high)
	data[median], data[high] = data[high], data[median]

	j := partitionOptimized(data, low, high)
	QuickSortOptimized(data, low, j-1)
	QuickSortOptimized(data, j+1, high)
}

func quickSortOptimizedInit() {
	data := []int{-229, 79, 46, 12, 58, 31, 34, 67, -89, 12, 67, 2}
	fmt.Println("\nUsing Optimized Quick Sort:")
	fmt.Println("Original Array: ", data)
	shuffleOptimized(data)
	QuickSortOptimized(data, 0, len(data)-1)
	fmt.Println("  Sorted Array: ", data)
}
