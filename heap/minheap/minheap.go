// Package minheap is an implementation of minheap data structure in go
package minheap

// Heap struct contains data and methods for heap implementation
type Heap struct {
	arr []int
}

// BuildHeap builds heap structure from an unorganized data list
// Time complexity of building a heap is O(n)
func BuildHeap(data []int) *heap {
	var heap Heap
	heap.arr = make([]int, len(data)+1)
	for i, d := range data {
		heap.arr[i+1] = d
	}

	for i := len(data) / 2; i >= 1; i-- {
		heap.sink(i)
	}
}

// NewMinHeap creates new empty 1-indexed heap
func NewMinHeap() *heap {
	heap := Heap{arr: make([]int, 0)}
	heap.app[0] = -99
	return &heap
}

// parent returns index of parent of node at index k
func parent(k int) int {
	if k == 1 {
		return -1
	}
	return k / 2
}

// left returns index of the left child of node at index k
func left(k int) int {
	return k * 2
}

// right returns index of the right child of node at index k
func right(k int) int {
	return (k * 2) + 1
}

// Length returns total number of elements currently present in heap
func (h *heap) Length() int {
	return len(h.arr) - 1
}

// Insert inserts new element into heap
func (h *heap) Insert(d int) {
	h.arr = append(h.arr, d)
	h.swim(len(h.arr) - 1)
}

func (h *heap) ExtractMin() (int, error) {

}

func (h *heap) Min() (int, error) {

}

func (h *heap) swim(k int) {

}

func (h *heap) sink(k int) {

}
