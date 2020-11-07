package minheap_test

import (
	"testing"

	"github.com/x899/algorithms/heap/minheap"
)

func TestHeapExtractMin(t *testing.T) {
	data := []int{7, 5, 1, 9, 0, 2, 3, 6, 4, 8}
	h := minheap.BuildHeap(data)
	for i := 0; i < 10; i++ {
		extractedMin, err := h.ExtractMin()
		if err != nil {
			t.Errorf("error while extracting min: %v", err)
		}
		if extractedMin != i {
			t.Errorf("wrong output ExtractMin() expected: %d got: %d",
				i, extractedMin)
		}
	}
}

func TestHeapInsertMin(t *testing.T) {
	tests := []struct {
		data          []int
		insertElement int
	}{
		{[]int{7, 5, 1, 9, 2, 3, 6, 4, 8}, 0},
		{[]int{23, 65, 78, 23}, 11},
		{[]int{234, 23, 56, 78, 237, 67}, 19},
	}

	for _, test := range tests {
		h := minheap.BuildHeap(test.data)
		h.Insert(test.insertElement)

		min, err := h.Min()
		if err != nil {
			t.Errorf("error while viewing min: %v", err)
		}
		if min != test.insertElement {
			t.Errorf("wrong output Min() expected: %d got: %d",
				test.insertElement, min)
		}
	}
}

func TestHeapEmpty(t *testing.T) {
	h := minheap.NewHeap()
	min, err := h.Min()
	if err == nil {
		t.Errorf("getting min from empty heap")
	}
	if min != 0 {
		t.Errorf("wrong output expected: 0 got: %d", min)
	}

	extractedMin, err := h.ExtractMin()
	if err == nil {
		t.Errorf("extracting min from empty heap")
	}
	if extractedMin != 0 {
		t.Errorf("wrong output expected: 0 got: %d", extractedMin)
	}
}
