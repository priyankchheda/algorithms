package bst

import (
	"errors"
	"fmt"
)

// queue struct contains data and methods are queue operations.
type queue struct {
	array []*Node
}

// newQueue creates new empty integer queue.
func newQueue() queue {
	return queue{array: make([]*Node, 0)}
}

// enqueue adds an item to the queue.
func (q *queue) enqueue(value *Node) {
	q.array = append(q.array, value)
}

// dequeue removes an item front the queue.
// Returns error if the queue is empty.
func (q *queue) dequeue() (removedElement *Node, err error) {
	if q.isEmpty() {
		return nil, errors.New("queue is empty")
	}
	removedElement = q.array[0]
	q.array[0] = nil
	q.array = q.array[1:]
	return removedElement, nil
}

// isEmpty checks if the queue is empty or not
func (q *queue) isEmpty() bool {
	return len(q.array) <= 0
}

// LevelOrder traversal of a tree is breadth first traversal for the tree
//
//	Example:
//
//	        F
//	      /	  \
//	     B     G
//	   /   \    \
//	 A      D    I
//
//	Level Order Traversal := F -> B -> G -> A -> D -> I
func (t *Tree) LevelOrder() {
	if t.Root == nil {
		return
	}
	q := newQueue()
	q.enqueue(t.Root)
	for !q.isEmpty() {
		current, _ := q.dequeue()
		fmt.Println(current.Data)
		if current.Left != nil {
			q.enqueue(current.Left)
		}
		if current.Right != nil {
			q.enqueue(current.Right)
		}
	}
}

// InOrder traverses the tree in inorder fashion
//
//	Inorder Algorithm
//
//	Visit all the nodes in the left subtree
//	Visit the root node
//	Visit all the nodes in the right subtree
func (t *Tree) InOrder(node *Node, printFunction func(*Node)) {
	if node == nil {
		return
	}
	t.InOrder(node.Left, printFunction)
	printFunction(node)
	t.InOrder(node.Right, printFunction)
}

// PreOrder traverses the tree in inorder fashion
//
//	Preorder Algorithm
//
//	Visit the root node
//	Visit all the nodes in the left subtree
//	Visit all the nodes in the right subtree
func (t *Tree) PreOrder(node *Node, printFunction func(*Node)) {
	if node == nil {
		return
	}
	printFunction(node)
	t.PreOrder(node.Left, printFunction)
	t.PreOrder(node.Right, printFunction)
}

// PostOrder traverses the tree in inorder fashion
//
//	Postorder Algorithm
//
//	Visit all the nodes in the left subtree
//	Visit all the nodes in the right subtree
//	Visit the root node
func (t *Tree) PostOrder(node *Node, printFunction func(*Node)) {
	if node == nil {
		return
	}
	t.PostOrder(node.Left, printFunction)
	t.PostOrder(node.Right, printFunction)
	printFunction(node)
}
