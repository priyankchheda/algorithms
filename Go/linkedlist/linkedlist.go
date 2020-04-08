// Package linkedlist is a implementation for linked list data
// structure in go languaue
package linkedlist

import (
	"errors"
	"fmt"
)

// Node struct contains actual data and address to next node
type Node struct {
	Data int
	Next *Node
}

// LinkedList struct contains lenght of linked list, address of first node
// and address of last node
type LinkedList struct {
	Len   int
	Start *Node
	End   *Node
}

// NewLinkedList creates new empty linked list
func NewLinkedList() LinkedList {
	return LinkedList{0, nil, nil}
}

// NewNode creates a new Node with integer data
func NewNode(data int) *Node {
	return &Node{data, nil}
}

// Head returns the first linked list node
func (list *LinkedList) Head() *Node {
	return list.Start
}

// Tail returns the last linked list node
func (list *LinkedList) Tail() *Node {
	return list.End
}

// Lenght returns the number of node currently present in linked list
func (list *LinkedList) Lenght() int {
	return list.Len
}

// InsertStart inserts node at the start of linked list
func (list *LinkedList) InsertStart(node *Node) {
	list.InsertAt(node, 1)
}

// InsertEnd inserts node at the end of linked list
func (list *LinkedList) InsertEnd(node *Node) {
	list.InsertAt(node, list.Lenght()+1)
}

// InsertAt inserts node at specified position in linked list
func (list *LinkedList) InsertAt(node *Node, position int) error {
	if position > list.Len+1 || position < 0 {
		// validation check for position value
		// position should be between 0 and list lenght + 1
		return errors.New("invalid position")

	} else if list.Len == 0 {
		// if linked list is empty
		list.Start = node
		list.End = node

	} else if position == list.Len+1 {
		// inserting element to last position (InsertEnd)
		current := list.End
		current.Next = node
		list.End = node

	} else if position == 1 {
		// inserting element to first position (InsertStart)
		current := list.Start
		list.Start = node
		node.Next = current

	} else {
		// inserting at nth position
		current := list.Start
		currentPrev := list.Start
		for i := 1; i < position; i++ {
			currentPrev = current
			current = current.Next
		}
		currentPrev.Next = node
		node.Next = current
	}
	list.Len++
	return nil
}

// DeleteStart removes first linked list node and returns data.
// Returns error, if linkedlist is empty.
func (list *LinkedList) DeleteStart() (int, error) {
	return list.DeleteAt(1)
}

// DeleteEnd removes last linked list node and returns data.
// Returns error, if linkedlist is empty.
func (list *LinkedList) DeleteEnd() (int, error) {
	return list.DeleteAt(list.Lenght())
}

// DeleteAt removes specified node from linked list and returns data.
// Returns error, if position is invalid.
func (list *LinkedList) DeleteAt(position int) (int, error) {
	if list.Len < position {
		// validation check for position value
		// position should not be more than list lenght
		return 0, errors.New("list don't have that much elements")

	} else if list.Len == 0 {
		// if linked list is empty
		return 0, errors.New("list is empty")

	} else if list.Len == 1 {
		// if linked list only contains one element
		current := list.Start
		list.Start = nil
		list.End = nil
		list.Len--
		return current.Data, nil

	} else if position == 1 {
		// deleting first element in the linked list (DeleteStart)
		current := list.Start
		list.Start = current.Next
		list.Len--
		return current.Data, nil

	} else if position == list.Len {
		// deleting last element in the linked list (DeleteEnd)
		current := list.Start
		currentPrev := list.Start
		for {
			if current.Next == nil {
				break
			}
			currentPrev = current
			current = current.Next
		}
		currentPrev.Next = nil
		list.Len--
		return current.Data, nil

	} else {
		// deleting nth element
		current := list.Start
		currentPrev := list.Start
		for i := 1; i < position; i++ {
			currentPrev = current
			current = current.Next
		}
		currentPrev.Next = current.Next
		current.Next = nil
		list.Len--
		return current.Data, nil
	}
}

// DataAt returns node data without removing it.
// Returns error, if position is invalid.
func (list *LinkedList) DataAt(position int) (int, error) {
	if list.Len < position {
		return 0, errors.New("list don't have that much elements")
	}
	current := list.Start
	for i := 1; i < position; i++ {
		current = current.Next
	}
	return current.Data, nil
}

// ReverseIterative reverse the original linked list using iterative approach.
func (list *LinkedList) ReverseIterative() {
	var current, prev, next *Node
	current = list.Start

	for current != nil {
		next = current.Next
		current.Next = prev
		prev = current
		current = next
	}
	list.Start = prev
}

// ReverseRecursive reverse the original linked list using recursive approach.
func (list *LinkedList) ReverseRecursive(p *Node) {
	if p.Next == nil {
		list.Start = p
		return
	}
	list.ReverseRecursive(p.Next)
	q := p.Next
	q.Next = p
	p.Next = nil
}

// PrintList prints entire linked list without changing underlying data.
func (list *LinkedList) PrintList() {
	current := list.Start
	for {
		fmt.Printf("%d", current.Data)
		if current.Next == nil {
			break
		}
		current = current.Next
		fmt.Printf(" -> ")
	}
	fmt.Println()
}

// PrintReverseRecursive prints entire linked list in reverse order without
// changing underlying data. It uses recursive approach.
func PrintReverseRecursive(p *Node) {
	if p == nil {
		return
	}
	PrintReverseRecursive(p.Next)
	fmt.Printf("%d ", p.Data)
}

// PrintRecursive prints entire linked list without changing underlying data.
// It uses recursive approach.
func PrintRecursive(p *Node) {
	if p == nil {
		fmt.Println()
		return
	}
	fmt.Printf("%d ", p.Data)
	PrintRecursive(p.Next)
}
