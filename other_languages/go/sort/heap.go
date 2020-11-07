package sort

// buildHeap builds heap structure from an unorganized data list
// Time complexity of building a heap is O(n)
func buildHeap(arr []int) {
	for i := len(arr) / 2; i >= 0; i-- {
		heapify(arr, i, len(arr))
	}
}

// heapify maintains the heap invariant (property)
func heapify(arr []int, root int, length int) {
	max := root
	left := 2*root + 1
	right := 2*root + 2

	if left < length && arr[left] > arr[max] {
		max = left
	}

	if right < length && arr[right] > arr[max] {
		max = right
	}

	if max != root {
		arr[root], arr[max] = arr[max], arr[root]
		heapify(arr, max, length)
	}
}

// HeapSort is a comparison based sorting technique based on Binary Heap
// data structure. It is similar to selection sort where we first find the
// maximum element and place the maximum element at the end. We repeat the
// same process for remaining element. Heap Sort is not stable, In-place
// sorting algorithm with guarantee NlogN time complexity in worst-case.
func HeapSort(data []int) {
	buildHeap(data)
	for i := len(data) - 1; i > 0; i-- {
		data[0], data[i] = data[i], data[0]
		heapify(data, 0, i)
	}
}
