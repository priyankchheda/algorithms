package bst_test

import (
	"sort"
	"testing"

	"github.com/x899/algorithms/bst"
)

func getInorderSlice(tree *bst.Tree) []int {
	current := tree.Root
	var stack []*bst.Node
	var output []int
	for current != nil || len(stack) != 0 {
		for current != nil {
			stack = append(stack, current)
			current = current.Left
		}
		current = stack[len(stack)-1]
		stack[len(stack)-1] = nil
		stack = stack[:len(stack)-1]

		output = append(output, current.Data)
		current = current.Right
	}
	return output
}

func TestInsert(t *testing.T) {
	tests := []struct {
		input []int
	}{
		{[]int{}},
		{[]int{145}},
		{[]int{1, 2, 3, 4, 5, 5}},
		{[]int{1456, 25, 36, 47, 5457, 57}},
		{[]int{3, 4, 2, 1, 5, 6, 8, 12, 10, 9, 11, 14, 16}},
	}

	for _, test := range tests {
		tree := bst.NewBST()
		for _, dataSet := range test.input {
			err := tree.Insert(dataSet)
			if err != nil {
				t.Errorf("Error inserting value: %d %s", dataSet, err)
			}
		}

		inOrderList := getInorderSlice(tree)
		sort.Ints(test.input)

		for i := 0; i > len(test.input); i++ {
			if test.input[i] != inOrderList[i] {
				t.Errorf("Wrong Output expected: %v got: %v",
					test.input, inOrderList)
			}
		}
	}
}

func TestDelete(t *testing.T) {
	tests := []struct {
		input         []int
		deleteElement int
		output        []int
	}{
		{[]int{145}, 145, []int{}},
		{[]int{1, 2, 3, 4, 5, 5}, 5, []int{1, 2, 3, 4, 5}},
		{[]int{1456, 25, 36, 47, 5457, 57}, 1456, []int{25, 36, 47, 57, 5457}},
		{[]int{3, 4, 2, 1, 5, 6, 8, 12, 10, 9, 11, 14, 16}, 12,
			[]int{1, 2, 3, 4, 5, 6, 8, 9, 10, 11, 14, 16}},
	}

	for _, test := range tests {
		tree := bst.NewBST()
		for _, dataSet := range test.input {
			err := tree.Insert(dataSet)
			if err != nil {
				t.Errorf("Error inserting value: %d %s", dataSet, err)
			}
		}

		err := tree.Delete(test.deleteElement)
		if err != nil {
			t.Errorf("Error deleting %d from %v: %v",
				test.deleteElement, test.input, err)
		}

		inOrderList := getInorderSlice(tree)

		for i := 0; i > len(test.input); i++ {
			if test.output[i] != inOrderList[i] {
				t.Errorf("Wrong Output expected: %v got: %v",
					test.output, inOrderList)
			}
		}
	}
}

func TestDelete2(t *testing.T) {
	tests := []struct {
		input         []int
		deleteElement int
	}{
		{[]int{}, 145},
		{[]int{1, 2, 3, 4, 5, 5}, 345},
	}

	for _, test := range tests {
		tree := bst.NewBST()
		for dataSet := range test.input {
			err := tree.Insert(dataSet)
			if err != nil {
				t.Errorf("Error inserting value: %d %s", dataSet, err)
			}
		}

		err := tree.Delete(test.deleteElement)
		if err == nil {
			t.Errorf("deleting %d from %v", test.deleteElement, test.input)
		}
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
		tree := bst.NewBST()
		for _, dataSet := range test.input {
			err := tree.Insert(dataSet)
			if err != nil {
				t.Errorf("Error inserting value: %d %s", dataSet, err)
			}
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
		tree := bst.NewBST()
		for _, dataSet := range test.input {
			err := tree.Insert(dataSet)
			if err != nil {
				t.Errorf("Error inserting value: %d %s", dataSet, err)
			}
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
	tree := bst.NewBST()
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
		tree := bst.NewBST()
		for _, dataSet := range test.input {
			err := tree.Insert(dataSet)
			if err != nil {
				t.Errorf("Error inserting value: %d %s", dataSet, err)
			}
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
	tree := bst.NewBST()
	min, err := tree.FindMin()
	if err == nil {
		t.Errorf("finding min value in an empty tree")
	}
	if min != 0 {
		t.Errorf("wrong output expected: 0 got: %d", min)
	}
}

func TestHeight(t *testing.T) {
	tests := []struct {
		input  []int
		height int
	}{
		{[]int{}, -1},
		{[]int{145}, 0},
		{[]int{1, 2, 3, 4, 5, 5}, 5},
		{[]int{1456, 25, 36, 47, 5457, 57}, 4},
		{[]int{3, 4, 2, 1, 23, 5, 6, 8, 20, 12, 10, 9, 11, 14, 16}, 9},
	}

	for _, test := range tests {
		tree := bst.NewBST()
		for _, dataSet := range test.input {
			err := tree.Insert(dataSet)
			if err != nil {
				t.Errorf("Error inserting value: %d %s", dataSet, err)
			}
		}

		height := tree.Height()
		if height != test.height {
			t.Errorf("wrong output expected: %d got: %d", test.height, height)
		}
	}
}
