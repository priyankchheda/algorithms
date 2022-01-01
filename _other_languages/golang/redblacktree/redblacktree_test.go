package redblacktree_test

import (
	"testing"

	"github.com/x899/algorithms/redblacktree"
)

func TestInsert(t *testing.T) {
	tree := redblacktree.NewRBTree()
	tree.Insert(1)
	tree.Insert(2)
	tree.Insert(3)
	tree.Insert(7)
	tree.Insert(7)
	tree.Insert(6)
	tree.Insert(4)
	tree.Insert(5)

	if actualValue := tree.Size; actualValue != 7 {
		t.Errorf("wrong answer expected: %v got:%v", 7, actualValue)
	}
}

func TestFind(t *testing.T) {
	tests := []struct {
		input   []int
		element int
		output  bool
	}{
		{[]int{}, 34, false},
		{[]int{145}, 145, true},
		{[]int{1, 2, 3, 4, 5, 5}, 5, true},
		{[]int{1456, 25, 36, 47, 5457, 57}, 44, false},
		{[]int{3, 4, 2, 1, 5, 6, 8, 12, 10, 9, 11, 14, 16}, 3, true},
	}

	for _, test := range tests {
		tree := redblacktree.NewRBTree()
		for _, dataSet := range test.input {
			tree.Insert(dataSet)
		}

		found := tree.Find(test.element)
		if found != test.output {
			t.Errorf("Wrong output for %v expected: %t got: %t",
				test.input, test.output, found)
		}
	}
}

func TestFindMax(t *testing.T) {
	tests := []struct {
		input      []int
		maxElement int
	}{
		{[]int{145}, 145},
		{[]int{1, 2, 3, 4, 5, 5}, 5},
		{[]int{1456, 25, 36, 47, 5457, 57}, 5457},
		{[]int{3, 4, 2, 1, 23, 5, 6, 8, 20, 12, 10, 9, 11, 14, 16}, 23},
	}

	for _, test := range tests {
		tree := redblacktree.NewRBTree()
		for _, dataSet := range test.input {
			tree.Insert(dataSet)
		}

		max, err := tree.FindMax()
		if err != nil {
			t.Errorf("Error finding max value %v", err)
		}
		if test.maxElement != max {
			t.Errorf("Error find max value expected: %d got: %d",
				test.maxElement, max)
		}
	}
}

func TestFindMax2(t *testing.T) {
	tree := redblacktree.NewRBTree()
	max, err := tree.FindMax()
	if err == nil {
		t.Errorf("finding max value in an empty tree")
	}
	if max != 0 {
		t.Errorf("wrong output expected: 0 got: %d", max)
	}
}

func TestFindMin(t *testing.T) {
	tests := []struct {
		input      []int
		minElement int
	}{
		{[]int{145}, 145},
		{[]int{1, 2, 3, 4, 5, 5}, 1},
		{[]int{1456, 25, 36, 47, 5457, 57}, 25},
		{[]int{3, 4, 2, 1, 23, 5, 6, 8, 20, 12, 10, 9, 11, 14, 16}, 1},
	}

	for _, test := range tests {
		tree := redblacktree.NewRBTree()
		for _, dataSet := range test.input {
			tree.Insert(dataSet)
		}

		min, err := tree.FindMin()
		if err != nil {
			t.Errorf("Error finding min value %v", err)
		}
		if test.minElement != min {
			t.Errorf("Error find min value expected: %d got: %d",
				test.minElement, min)
		}
	}
}

func TestFindMin2(t *testing.T) {
	tree := redblacktree.NewRBTree()
	min, err := tree.FindMin()
	if err == nil {
		t.Errorf("finding min value in an empty tree")
	}
	if min != 0 {
		t.Errorf("wrong output expected: 0 got: %d", min)
	}
}
