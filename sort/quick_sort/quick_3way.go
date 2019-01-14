package main

import (
	"fmt"
	"math/rand"
	"time"
)

func shuffle3Way(data []int) {
	random := rand.New(rand.NewSource(time.Now().UnixNano()))
	for i := 0; i < len(data); i++ {
		r := random.Intn(i + 1)
		data[i], data[r] = data[r], data[i]
	}
}

// Quick3WaySort is go implementation of Quick Sort 3-way partition
func Quick3WaySort(data []int, low int, high int) {
	if high <= low {
		return
	}

	lt := low
	gt := high
	pivot := data[low]
	i := low

	for i <= gt {
		if data[i] < pivot {
			data[lt], data[i] = data[i], data[lt]
			lt++
			i++
		} else if data[i] > pivot {
			data[gt], data[i] = data[i], data[gt]
			gt--
		} else {
			i++
		}
	}

	Quick3WaySort(data, low, lt-1)
	Quick3WaySort(data, gt+1, high)
}

func quick3WaySortInit() {
	data := []int{-229, 34, 46, 12, 34, 34, 34, 67, -89, 12, 67, 2}
	fmt.Println("\nUsing 3-way Quick Sort:")
	fmt.Println("Original Array: ", data)
	shuffle3Way(data)
	Quick3WaySort(data, 0, len(data)-1)
	fmt.Println("  Sorted Array: ", data)
}
