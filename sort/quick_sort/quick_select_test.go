package main

import "testing"

func TestQuickSelect(t *testing.T) {
	tables := []struct {
		data       []int
		k          int
		kthElement int
	}{
		{nil, 45, -1},
		{[]int{}, 34, -1},
		{[]int{5}, 0, 5},
		{[]int{5, 8, 2, 9}, 3, 9},
		{[]int{-9, -3, 9, -12}, 1, -9},
	}

	for _, table := range tables {
		output := QuickSelect(table.data, table.k)
		if output != table.kthElement {
			t.Errorf("Incorrect kth element k:%d\n got: %d expected: %d",
				table.k, output, table.kthElement)
			break
		}
	}
}
