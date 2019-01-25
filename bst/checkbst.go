package bst

// IsBST returns true if the existing binary tree is a binary search tree,
// else false.
func (t *Tree) IsBST() bool {
	return t.Root.isBSTNode(1, 10000000)
}

// isBSTNode is an internal method which works at node level
func (node *Node) isBSTNode(minValue, maxValue int) bool {
	if node == nil {
		return true
	}
	if node.Data >= minValue &&
		node.Data < maxValue &&
		node.Left.isBSTNode(minValue, node.Data) &&
		node.Right.isBSTNode(node.Data, maxValue) {
		return true
	}
	return false
}
