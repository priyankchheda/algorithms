package bst

import "errors"

// Insert inserts new integer data into the tree at the position, so that
// the binary search tree property is maintained.
func (t *Tree) Insert(data int) error {
	if t.Root == nil {
		t.Root = NewNode(data)
		return nil
	}
	return t.Root.insertNode(data)
}

// insert is an internal method which works on node level
func (node *Node) insertNode(data int) error {
	if node == nil {
		return errors.New("Cannot insert a value into a nil tree")
	}

	switch {
	case data <= node.Data:
		if node.Left == nil {
			node.Left = NewNode(data)
			return nil
		}
		return node.Left.insertNode(data)

	case data > node.Data:
		if node.Right == nil {
			node.Right = NewNode(data)
			return nil
		}
		return node.Right.insertNode(data)
	}
	return nil
}
