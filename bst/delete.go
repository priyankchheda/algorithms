package bst

import "errors"

// Delete deletes a node with said data such that the binary search tree
// property is still maintained.
func (t *Tree) Delete(data int) error {
	if t.Root == nil {
		return errors.New("can not delete from an empty tree")
	}

	fakeParent := &Node{Right: t.Root}
	err := t.Root.deleteNode(data, fakeParent)
	if err != nil {
		return err
	}

	if fakeParent.Right == nil {
		t.Root = nil
	}
	return nil
}

// findMaxNode returns pointer of node with max data and it's parent
func (node *Node) findMaxNode(parent *Node) (*Node, *Node) {
	if node == nil {
		return nil, parent
	}
	if node.Right == nil {
		return node, parent
	}
	return node.Right.findMaxNode(node)
}

// replaceNode replaces node with replacement (parameter)
func (node *Node) replaceNode(parent, replacement *Node) error {
	if node == nil {
		return errors.New("replaceNode() not allowed on a nil node")
	}

	if node == parent.Left {
		parent.Left = replacement
	} else {
		parent.Right = replacement
	}
	return nil
}

//deleteNode is an internal method which works at node level
func (node *Node) deleteNode(data int, parent *Node) error {
	if node == nil {
		return errors.New("value to be deleted does not exist in the tree")
	}

	switch {
	case data < node.Data:
		return node.Left.deleteNode(data, node)

	case data > node.Data:
		return node.Right.deleteNode(data, node)

	default:
		if node.Left == nil && node.Right == nil {
			node.replaceNode(parent, nil)
			return nil
		}
		if node.Left == nil {
			node.replaceNode(parent, node.Right)
			return nil
		}
		if node.Right == nil {
			node.replaceNode(parent, node.Left)
			return nil
		}

		replacement, replParent := node.Left.findMaxNode(node)
		node.Data = replacement.Data
		return replacement.deleteNode(replacement.Data, replParent)
	}
}
