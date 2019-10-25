package sort

func GnomeSort(data []int) {
	index := 0
	for index < len(data) {
		if (index == 0 || data[index] >= data[index - 1]) {
			index = index + 1
		} else {
			// Swap value at index and (index - 1)
			tempVal := data[index - 1]
			data[index - 1] = data[index]
			data[index] = tempVal

			index = index - 1
		}
	}
}