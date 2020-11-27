// Package maxheap is an implementation of minheap data structure in go
package maxheap

import "errors"

// Heap struct contains data and methods for heap implementation
type Heap struct {
	arr []int
}

// BuildHeap builds heap structure from an unorganized data list
// Time complexity of building a heap is O(n)
func BuildHeap(data []int) *Heap {
	var heap Heap
	heap.arr = make([]int, len(data)+1)
	heap.arr[0] = -99
	for i, d := range data {
		heap.arr[i+1] = d
	}

	for i := len(data) / 2; i >= 1; i-- {
		heap.sink(i)
	}
	return &heap
}

// NewHeap creates new empty 1-indexed heap
func NewHeap() *Heap {
	heap := Heap{arr: make([]int, 0)}
	heap.arr = append(heap.arr, -99)
	return &heap
}

// Length returns total number of elements currently present in heap
func (h *Heap) Length() int {
	return len(h.arr) - 1
}

// Insert inserts new element into heap
func (h *Heap) Insert(d int) {
	h.arr = append(h.arr, d)
	h.swim(len(h.arr) - 1)
}

// ExtractMax returns the maximum value (i.e. root) in the heap and removes it
// from the heap. Returns error, if heap is empty
func (h *Heap) ExtractMax() (int, error) {
	if h.Length() <= 0 {
		return 0, errors.New("heap is empty")
	}
	maxvalue := h.arr[1]
	h.arr[1] = h.arr[h.Length()]
	h.arr = h.arr[:h.Length()]
	h.sink(1)
	return maxvalue, nil
}

// Max returns the maximum value (i.e. root) in the heap, without removing it.
// Returns error, if heap is empty
func (h *Heap) Max() (int, error) {
	if h.Length() <= 0 {
		return 0, errors.New("heap is empty")
	}
	return h.arr[1], nil
}

// swim moves element at index k upward to maintain heap invariant
func (h *Heap) swim(k int) {
	if k <= 1 {
		// k is root node
		return
	}
	p := k / 2
	if h.arr[p] < h.arr[k] {
		h.arr[p], h.arr[k] = h.arr[k], h.arr[p]
		h.swim(p)
	}
}

// sink moves element at index k downward to maintain heap invariant
func (h *Heap) sink(k int) {
	min := k
	c := k * 2

	// find index of minimum value (k, k's left child, k's right child)
	for i := 0; i < 2; i++ {
		if (c + i) <= h.Length() {
			if h.arr[min] < h.arr[c+i] {
				min = c + i
			}
		}
	}
	if min != k {
		h.arr[k], h.arr[min] = h.arr[min], h.arr[k]
		h.sink(min)
	}
}
