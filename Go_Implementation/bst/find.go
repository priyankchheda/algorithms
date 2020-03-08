package bst

import "errors"

// FindMax returns the max element from the dataset
func (t *Tree) FindMax() (int, error) {
	if t.Root == nil {
		return 0, errors.New("tree is empty")
	}
	current := t.Root
	for current.Right != nil {
		current = current.Right
	}
	return current.Data, nil
}

// FindMin returns the max element from the dataset
func (t *Tree) FindMin() (int, error) {
	if t.Root == nil {
		return 0, errors.New("tree is empty")
	}
	current := t.Root
	for current.Left != nil {
		current = current.Left
	}
	return current.Data, nil
}

// Find returns true if integer is present in the binary search tree,
// else false.
func (t *Tree) Find(data int) bool {
	if t.Root == nil {
		return false
	}
	return t.Root.findNode(data)
}

// find is an internal method which works on node level
func (node *Node) findNode(data int) bool {
	if node == nil {
		return false
	}

	switch {
	case data == node.Data:
		return true
	case data < node.Data:
		return node.Left.findNode(data)
	default:
		return node.Right.findNode(data)
	}
}
