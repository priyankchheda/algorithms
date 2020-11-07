package search_test

import (
	"testing"

	"github.com/x899/algorithms/search"
)

func TestBinarySearch(t *testing.T) {
	tests := []struct {
		array  []int
		value  int
		result int
	}{
		{nil, 9, -1},
		{[]int{}, 4, -1},
		{[]int{1, 2, 3, 3, 4}, 3, 2},
		{[]int{3, 5, 6, 7, 8, 9}, 8, 4},
		{[]int{-9, -3, 0, 45, 234}, 0, 2},
	}

	for _, test := range tests {
		location := search.BinarySearch(test.array, test.value)
		if location != test.result {
			t.Errorf("wrong output expected: %v got: %v",
				test.result, location)
		}
	}
}
