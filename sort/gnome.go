package sort


// The gnome sort is a sorting algorithm which is similar
// to insertion sort in that it works with one item at a time
// but gets the item to the proper place by a series of swaps.
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