package sort

import (
	"github.com/x899/algorithms/shuffle"
)

// partitionQS return partition index of pivot
func partitionQS(data []int, low int, high int) int {
	median := medianOfThree(data, low, high)
	data[median], data[high] = data[high], data[median]

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

// QuickSelect is a selection algorithm to find the k-th smallest element in
// an unordered list. It is related to the quick sort sorting algorithm.
func QuickSelect(data []int, k int) int {
	if k >= len(data) {
		return -1
	}
	shuffle.Shuffle(data)
	low := 0
	high := len(data) - 1

	for high > low {
		j := partitionQS(data, low, high)
		if j < k {
			low = j + 1
		} else if j > k {
			high = j - 1
		} else {
			return data[k]
		}
	}
	return data[k]
}
