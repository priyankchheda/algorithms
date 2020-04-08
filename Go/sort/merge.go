package sort

// merge function for MergeSort
func merge(data []int, low int, mid int, high int) {
	aux := make([]int, high-low+1)
	i := low
	j := mid + 1
	k := 0

	for i <= mid && j <= high {
		if data[i] < data[j] {
			aux[k] = data[i]
			i++
		} else {
			aux[k] = data[j]
			j++
		}
		k++
	}

	for i <= mid {
		aux[k] = data[i]
		k++
		i++
	}

	for j <= high {
		aux[k] = data[j]
		k++
		j++
	}

	for i := low; i <= high; i++ {
		data[i] = aux[i-low]
	}
}

// MergeSort is a Divide and Conquer algorithm. It divides input array in two
// halves, calls itself for the two halves and then merges the two sorted
// halves.
func MergeSort(data []int, low int, high int) {
	if low < high {
		mid := (low + high) / 2
		MergeSort(data, low, mid)
		MergeSort(data, mid+1, high)
		merge(data, low, mid, high)
	}
}

// merge function for MergeSortOptimized
func mergeOptimized(data []int, aux []int, low int, mid int, high int) {
	for k := low; k <= high; k++ {
		aux[k] = data[k]
	}

	i := low
	j := mid + 1
	for k := low; k <= high; k++ {
		if i > mid {
			data[k] = aux[j]
			j++
		} else if j > high {
			data[k] = aux[i]
			i++
		} else if aux[j] < aux[i] {
			data[k] = aux[j]
			j++
		} else {
			data[k] = aux[i]
			i++
		}
	}
}

// MergeSortOptimized function implements optimized version of Merge Sorting
// algorithm. It uses Insertion sort for dataset with less than or equal to 7
// elements. It also stops if data is already sorted i.e biggest item in first
// half is less than or equal to smallest item in seconh half. It is useful for
// partially-ordered arrays. We also pass auxillary array to this function
// because creating auxillary array in the recusive routine lead to extensive
// cost of extra array creation.
func MergeSortOptimized(data []int, aux []int, low int, high int) {
	if high <= low+cutoff-1 {
		InsertionSort(data[low : high+1])
	}

	if low < high {
		mid := (low + high) / 2
		MergeSortOptimized(data, aux, low, mid)
		MergeSortOptimized(data, aux, mid+1, high)

		// stop if already sorted
		// iff biggest item in fist half <= smallest item in second half
		// helps for partially-ordered arrays
		if data[mid] <= data[mid+1] {
			return
		}
		mergeOptimized(data, aux, low, mid, high)
	}
}

// min finds minimum of two given number
func min(a, b int) int {
	if a < b {
		return a
	}
	return b
}

// MergeSortBottomUp algorithm first merges pairs of adjacent arrays of
// 1 elements then merges pairs of adjacent arrays of 2 elements
// and next merges pairs of adjacent arrays of 4 elements
// and so on until the whole array is merged. Hence, completely avoiding
// recursive approach.
func MergeSortBottomUp(data []int) {
	dataLen := len(data)
	aux := make([]int, dataLen)

	for sz := 1; sz < dataLen; sz = sz + sz {
		for low := 0; low < dataLen-sz; low += sz + sz {
			mergeOptimized(data, aux, low, low+sz-1, min(low+sz+sz-1, dataLen-1))
		}
	}
}
