package sort

// SelectionSort algorithm sorts an array by repeatedly finding the
// minimum element (considering ascending order) from unsorted part and
// putting it at the beginning.
func SelectionSort(data []int) {
	dataLen := len(data)
	for i := 0; i < dataLen-1; i++ {
		minElementIndex := i
		for j := i + 1; j < dataLen; j++ {
			if data[j] < data[minElementIndex] {
				minElementIndex = j
			}
		}
		data[i], data[minElementIndex] = data[minElementIndex], data[i]
	}
}
