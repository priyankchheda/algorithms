package maxheap_test

import (
	"testing"

	"github.com/x899/algorithms/heap/maxheap"
)

func TestHeapExtractMax(t *testing.T) {
	data := []int{7, 5, 1, 9, 0, 2, 3, 6, 4, 8}
	h := maxheap.BuildHeap(data)
	for i := 9; i >= 0; i-- {
		extractedMax, err := h.ExtractMax()
		if err != nil {
			t.Errorf("error while extracting max: %v", err)
		}
		if extractedMax != i {
			t.Errorf("wrong output ExtractMax() expected: %d got: %d",
				i, extractedMax)
		}
	}
}

func TestHeapInsertMax(t *testing.T) {
	tests := []struct {
		data          []int
		insertElement int
	}{
		{[]int{7, 5, 1, 9, 2, 3, 6, 4, 8}, 10},
		{[]int{23, 65, 78, 23}, 89},
		{[]int{234, 23, 56, 78, 237, 67}, 339},
	}

	for _, test := range tests {
		h := maxheap.BuildHeap(test.data)
		h.Insert(test.insertElement)

		max, err := h.Max()
		if err != nil {
			t.Errorf("error while viewing max: %v", err)
		}
		if max != test.insertElement {
			t.Errorf("wrong output Max() expected: %d got: %d",
				test.insertElement, max)
		}
	}
}

func TestHeapEmpty(t *testing.T) {
	h := maxheap.NewHeap()
	max, err := h.Max()
	if err == nil {
		t.Errorf("getting max from empty heap")
	}
	if max != 0 {
		t.Errorf("wrong output expected: 0 got: %d", max)
	}

	extractedMax, err := h.ExtractMax()
	if err == nil {
		t.Errorf("extracting max from empty heap")
	}
	if extractedMax != 0 {
		t.Errorf("wrong output expected: 0 got: %d", extractedMax)
	}
}
