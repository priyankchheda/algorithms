package sort

// InsertionSort is based on the idea that one element from the input
// elements is consumed in each iteration to find its correct position
// i.e, the position to which it belongs in a sorted array.
func InsertionSort(data []int) {
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
