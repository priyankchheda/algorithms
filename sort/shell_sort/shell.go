package main

import "fmt"

// ShellSort is mainly a variation of Insertion Sort. In insertion sort, we
// move elements only one position ahead. When an element has to be moved far
// ahead, many movements are involved. The idea of shellSort is to allow
// exchange of far items. In shellSort, we make the array h-sorted for a large
// value of h. We keep reducing the value of h until it becomes 1. An array is
// said to be h-sorted if all sublists of every h’th element is sorted.
func ShellSort(data []int) {
	dataLen := len(data)

	h := 1
	for h < dataLen/3 {
		h = h*3 + 1
	}

	for h >= 1 {
		// h-sort the array
		for i := h; i < dataLen; i++ {
			for j := i; j >= h && data[j] < data[j-h]; j = j - h {
				data[j], data[j-h] = data[j-h], data[j]
			}
		}
		h = h / 3
	}
}

func main() {
	data := []int{-229, 79, 46, 12, 58, 31, 34, 67, -89, 12, 67, 2}
	fmt.Println("Original Array: ", data)
	ShellSort(data)
	fmt.Println("  Sorted Array: ", data)
}
