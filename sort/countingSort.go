package sort

/*
Counting sort is a sorting algorithm that sorts the elements of an array
by counting the number of occurrences of each unique element in the array.
The count is stored in an auxiliary array
and the sorting is done by mapping the count as an index of the auxiliary array.
*/
func CountingSort(data []int) {
	size := len(data)
	min := data[0]
	max := data[0]
	for _, val := range data {
		if val < min {
			min = val
		}
		if val > max {
			max = val
		}
	}

	length := max - min + 1
	count := make([]int, length)
	output := make([]int, size)
	for i := 0; i < size; i++ {
		count[data[i]-min]++
	}

	for i := 1; i < length; i++ {
		count[i] += count[i-1]
	}

	for i := 0; i < size; i++ {
		output[count[data[i]-min]-1] = data[i]
		count[data[i]-min]--
	}

	data = output
}
