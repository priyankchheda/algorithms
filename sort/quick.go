package sort

// partition return partition index of pivot
func partition(data []int, low int, high int) int {
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

// QuickSort is a Divide and Conquer algorithm.
// It picks an element as pivot and partitions the given array around the
// picked pivot. It uses last element as pivot element
func QuickSort(data []int, low int, high int) {
	if high <= low {
		return
	}
	j := partition(data, low, high)
	QuickSort(data, low, j-1)
	QuickSort(data, j+1, high)
}

// medianOfThree to return pivot index
func medianOfThree(data []int, low int, high int) int {
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

// QuickSortOptimized function implements optimized version of Quick Sort
// algorithm. It uses Insertion sort for dataset with less than or equal to 7
// elements. It uses media of three strategy to select the pivot element.
func QuickSortOptimized(data []int, low int, high int) {
	if high <= low {
		return
	}

	// use insertion sort for data set of size <=7
	if high <= low+cutoff-1 {
		InsertionSort(data[low : high+1])
		return
	}

	// Use median of Three to find the Pivot index
	median := medianOfThree(data, low, high)
	data[median], data[high] = data[high], data[median]

	j := partition(data, low, high)
	QuickSortOptimized(data, low, j-1)
	QuickSortOptimized(data, j+1, high)
}

// Quick3WaySort is a variant of Quick Sort 3-way partitioning.
// 3-way quicksort is optimization which works in specific cases like when
// input to be sorted contains few unique keys, in this case having
// traditional approach of one pivot does not perform well compared to
// 3-way quicksort.
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
