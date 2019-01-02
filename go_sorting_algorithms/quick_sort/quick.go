package main

import (
	"fmt"
	"math/rand"
	"time"
)

func shuffle(data []int) {
	random := rand.New(rand.NewSource(time.Now().UnixNano()))
	for i := 0; i < len(data); i++ {
		r := random.Intn(i + 1)
		data[i], data[r] = data[r], data[i]
	}
}

func partition(data []int, low int, high int) int {
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

// QuickSort is go implementation of Quick Sort
func QuickSort(data []int, low int, high int) {
	if high <= low {
		return
	}
	j := partition(data, low, high)
	QuickSort(data, low, j-1)
	QuickSort(data, j+1, high)
}

func main() {
	data := []int{-229, 79, 46, 12, 58, 31, 34, 67, -89, 12, 67, 2}
	fmt.Println("Original Array: ", data)
	shuffle(data)
	QuickSort(data, 0, len(data)-1)
	fmt.Println("  Sorted Array: ", data)
}
