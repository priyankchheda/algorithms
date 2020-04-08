// Package doublylinkedlist is a implementation for doubly linked list data
// structure in go language
package doublylinkedlist

import (
	"errors"
	"fmt"
)

// Node struct contains actual data and address to next node
type Node struct {
	Data int
	Prev *Node
	Next *Node
}

// DoublyLinkedList struct contains lenght of doubly linked list, address of
// first node and address of last node
type DoublyLinkedList struct {
	Len   int
	Start *Node
	End   *Node
}

// NewDoublyLinkedList creates new empty linked list
func NewDoublyLinkedList() DoublyLinkedList {
	return DoublyLinkedList{0, nil, nil}
}

// NewNode creates a new Node with integer data
func NewNode(data int) *Node {
	return &Node{data, nil, nil}
}

// Head returns the first doubly linked list node
func (list *DoublyLinkedList) Head() *Node {
	return list.Start
}

// Tail returns the last doubly linked list node
func (list *DoublyLinkedList) Tail() *Node {
	return list.End
}

// Lenght returns the number of node currently present in doubly linked list
func (list *DoublyLinkedList) Lenght() int {
	return list.Len
}

// InsertStart inserts node at the start of doubly linked list
func (list *DoublyLinkedList) InsertStart(node *Node) {
	list.InsertAt(node, 1)
}

// InsertEnd inserts node at the end of doubly linked list
func (list *DoublyLinkedList) InsertEnd(node *Node) {
	list.InsertAt(node, list.Lenght()+1)
}

// InsertAt inserts node at specified position in doubly linked list
func (list *DoublyLinkedList) InsertAt(node *Node, position int) error {
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
		list.End = node
		current.Next = node
		node.Prev = current

	} else if position == 1 {
		// inserting element to first position (InsertStart)
		current := list.Start
		list.Start = node
		node.Next = current
		current.Prev = node

	} else {
		// inserting at nth position
		current := list.Start
		for i := 1; i < position; i++ {
			current = current.Next
		}
		currentPrev := current.Prev
		node.Prev = currentPrev
		node.Next = current
		currentPrev.Next = node
		current.Prev = node
	}
	list.Len++
	return nil
}

// DeleteStart removes first doubly linked list node and returns data.
// Returns error, if linkedlist is empty.
func (list *DoublyLinkedList) DeleteStart() (int, error) {
	return list.DeleteAt(1)
}

// DeleteEnd removes last doubly linked list node and returns data.
// Returns error, if linkedlist is empty.
func (list *DoublyLinkedList) DeleteEnd() (int, error) {
	return list.DeleteAt(list.Len)
}

// DeleteAt removes specified node from doubly linked list and returns data.
// Returns error, if position is invalid.
func (list *DoublyLinkedList) DeleteAt(position int) (int, error) {
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
		list.Start = list.Start.Next
		list.Start.Prev = nil
		current.Next = nil
		list.Len--
		return current.Data, nil

	} else if position == list.Len {
		// deleting last element in the linked list (DeleteEnd)
		current := list.End
		list.End = list.End.Prev
		list.End.Next = nil
		list.Len--
		return current.Data, nil

	} else {
		// deleting nth element
		current := list.Start
		for i := 1; i < position; i++ {
			current = current.Next
		}
		current.Prev.Next = current.Next
		current.Next.Prev = current.Prev
		list.Len--
		return current.Data, nil
	}
}

// PrintList prints entire doubly linked list without changing underlying data.
func (list *DoublyLinkedList) PrintList() {
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
