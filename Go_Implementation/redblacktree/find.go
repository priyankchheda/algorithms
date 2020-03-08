package redblacktree

import "errors"

// FindMax returns the max element from the dataset
func (t *RBTree) FindMax() (int, error) {
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
func (t *RBTree) FindMin() (int, error) {
	if t.Root == nil {
		return 0, errors.New("tree is empty")
	}
	current := t.Root
	for current.Left != nil {
		current = current.Left
	}
	return current.Data, nil
}

// Find returns true if integer is present in RBTree, else false.
func (t *RBTree) Find(data int) bool {
	if t.Root == nil {
		return false
	}
	return t.Root.findNode(data)
}

// findNode is an internal method which works on node level
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
