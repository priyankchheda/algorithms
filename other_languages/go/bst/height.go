package bst

// Height returns the height of the tree
func (t *Tree) Height() int {
	if t.Root == nil {
		return -1
	}
	return t.Root.heightNode()
}

// heightNode is an internal method which works at node level
func (node *Node) heightNode() int {
	if node == nil {
		return -1
	}
	leftHeight := node.Left.heightNode()
	rightHeight := node.Right.heightNode()
	if leftHeight > rightHeight {
		return leftHeight + 1
	}
	return rightHeight + 1
}
