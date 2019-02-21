// Package search is an implementation of various search algorithm in GoLang
package search

// BinarySearch is the most efficient searching algorithm having a run-time
// complexity of O(log2 N). This algorithm works only on a sorted list of
// elements.
//
// Binary search begins by comparing the middle element of the list with the
// target element. If the target value matches the middle element, its position
// in the list is returned. If it does not match, the list is divided into two
// halves. The first half consists of the first element to middle element
// whereas the second half consists of the element next to the middle element
// to the last element.
func BinarySearch(arr []int, value int) int {
	start := 0
	end := len(arr) - 1

	for start <= end {
		median := (start + end) / 2
		if arr[median] < value {
			start = median + 1
		} else {
			end = median - 1
		}
	}

	if start == len(arr) || arr[start] != value {
		return -1
	} else {
		return start
	}
}
