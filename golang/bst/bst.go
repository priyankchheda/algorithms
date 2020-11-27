// Package bst is an implementation for binary search tree data structure
// in go language
package bst

// Node struct contains actual data and address to left and right node
type Node struct {
	Data  int
	Left  *Node
	Right *Node
}

// Tree struct contains the pointer to root node
type Tree struct {
	Root *Node
}

// NewBST creates an empty BST Tree
func NewBST() *Tree {
	return &Tree{nil}
}

// NewNode creates a new Node with integer data
func NewNode(data int) *Node {
	return &Node{data, nil, nil}
}
