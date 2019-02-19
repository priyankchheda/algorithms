package search

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
