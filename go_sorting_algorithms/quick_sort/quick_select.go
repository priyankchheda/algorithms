package main

import (
	"fmt"
	"math/rand"
	"time"
)

func shuffleQuickSelect(data []int) {
	random := rand.New(rand.NewSource(time.Now().UnixNano()))
	for i := 0; i < len(data); i++ {
		r := random.Intn(i + 1)
		data[i], data[r] = data[r], data[i]
	}
}

func medianOf3(data []int, low int, high int) int {
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

func partitionQS(data []int, low int, high int) int {
	median := medianOf3(data, low, high)
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

func QuickSelect(data []int, k int) int {
	if k >= len(data) {
		return -1
	}
	shuffleQuickSelect(data)
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

func quickSelectInit() {
	k := 3
	data := []int{8, 7, 6, 4, 9, 2, 3, 5, 1}
	fmt.Println("\nUsing Quick Select:")
	fmt.Println("kth element is ", QuickSelect(data, k))
}
