// Package bst is an implementation for binary search tree data structure
// in go language
package main

import (
	"errors"
	"fmt"
	"log"
	"strconv"
)

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

// InOrder traverses through the tree in inorder fashion
func (t *Tree) InOrder(node *Node, printFunction func(*Node)) {
	if node == nil {
		return
	}
	t.InOrder(node.Left, printFunction)
	printFunction(node)
	t.InOrder(node.Right, printFunction)
}

// PreOrder traverses through the tree in inorder fashion
func (t *Tree) PreOrder(node *Node, printFunction func(*Node)) {
	if node == nil {
		return
	}
	printFunction(node)
	t.PreOrder(node.Left, printFunction)
	t.PreOrder(node.Right, printFunction)
}

// PostOrder traverses through the tree in inorder fashion
func (t *Tree) PostOrder(node *Node, printFunction func(*Node)) {
	if node == nil {
		return
	}
	t.PostOrder(node.Left, printFunction)
	t.PostOrder(node.Right, printFunction)
	printFunction(node)
}

func (t *Tree) Height() int {
	if t.Root == nil {
		return -1
	}
	return t.Root.height()
}

func (node *Node) height() int {
	if node == nil {
		return -1
	}
	leftHeight := node.Left.height()
	rightHeight := node.Right.height()
	if leftHeight > rightHeight {
		return leftHeight + 1
	}
	return rightHeight + 1
}

func (t *Tree) LevelOrder() {
	if t.Root == nil {
		return
	}
	q := NewQueue()
	q.Enqueue(t.Root)
	for !q.IsEmpty() {
		current, _ := q.Dequeue()
		fmt.Println(current.Data)
		if current.Left != nil {
			q.Enqueue(current.Left)
		}
		if current.Right != nil {
			q.Enqueue(current.Right)
		}
	}
}

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

func (t *Tree) IsBST() bool {
	return t.Root.isBSTNode(1, 10000000)
}

// Main Function
func main() {
	dataSet := []int{3, 4, 2, 1, 5, 6, 8, 12, 10, 9, 11, 14, 16}
	tree := NewBST()
	for _, data := range dataSet {
		err := tree.Insert(data)
		if err != nil {
			log.Fatal("Error inserting value: %s %s", data, err)
		}
	}

	fmt.Print("Sorted values: | ")
	tree.InOrder(tree.Root, func(n *Node) { fmt.Print(n.Data) })
	fmt.Println()
	fmt.Println("IsBST: ", tree.IsBST())
	fmt.Println("Level Order")
	tree.LevelOrder()
	fmt.Println()
	fmt.Println("height: ", tree.Height())

	s := 4
	fmt.Println("Find Node: ", s)
	found := tree.Find(s)
	if !found {
		fmt.Println("not found")
	}
	fmt.Println("found")

	err := tree.Delete(s)
	if err != nil {
		log.Fatal("Error deleting "+strconv.Itoa(s)+": ", err)
	}

	fmt.Println("After deleting")
	tree.InOrder(tree.Root, func(n *Node) { fmt.Print(n.Data) })
	fmt.Println()

	max, err := tree.FindMax()
	fmt.Println("max: ", max)
	min, err := tree.FindMin()
	fmt.Println("min: ", min)
	fmt.Println("height: ", tree.Height())

	fmt.Println("Single-node tree")
	tree = &Tree{}

	tree.Insert(6)
	fmt.Println("After insert:")
	tree.InOrder(tree.Root, func(n *Node) { fmt.Print(n.Data) })
	fmt.Println()
	fmt.Println("height: ", tree.Height())

	tree.Delete(6)
	fmt.Println("After delete:")
	tree.InOrder(tree.Root, func(n *Node) { fmt.Print(n.Data) })
	fmt.Println()
	fmt.Println("height: ", tree.Height())
}
