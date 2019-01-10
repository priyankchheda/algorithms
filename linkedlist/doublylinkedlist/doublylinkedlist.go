package main

import (
	"errors"
	"fmt"
)

type Node struct {
	data int
	prev *Node
	next *Node
}

type DoublyLinkedList struct {
	lenght int
	start  *Node
	end    *Node
}

func (list *DoublyLinkedList) Head() *Node {
	return list.start
}

func (list *DoublyLinkedList) Tail() *Node {
	return list.end
}

func (list *DoublyLinkedList) Lenght() int {
	return list.lenght
}

func (list *DoublyLinkedList) InsertStart(node *Node) {
	list.InsertAt(node, 1)
}

func (list *DoublyLinkedList) InsertEnd(node *Node) {
	list.InsertAt(node, list.Lenght()+1)
}

func (list *DoublyLinkedList) InsertAt(node *Node, position int) error {
	if position > list.lenght+1 || position < 0 {
		// validation check for position value
		// position should be between 0 and list lenght + 1
		return errors.New("invalid position")

	} else if list.lenght == 0 {
		// if linked list is empty
		list.start = node
		list.end = node

	} else if position == list.lenght+1 {
		// inserting element to last position (InsertEnd)
		current := list.end
		list.end = node
		current.next = node
		node.prev = current

	} else if position == 1 {
		// inserting element to first position (InsertStart)
		current := list.start
		list.start = node
		node.next = current
		current.prev = node

	} else {
		// inserting at nth position
		current := list.start
		for i := 1; i < position; i++ {
			current = current.next
		}
		currentPrev := current.prev
		node.prev = currentPrev
		node.next = current
		currentPrev.next = node
		current.prev = node
	}
	list.lenght++
	return nil
}

func (list *DoublyLinkedList) DeleteStart() (int, error) {
	return list.DeleteAt(1)
}

func (list *DoublyLinkedList) DeleteEnd() (int, error) {
	return list.DeleteAt(list.lenght)
}

func (list *DoublyLinkedList) DeleteAt(position int) (int, error) {
	if list.lenght < position {
		// validation check for position value
		// position should not be more than list lenght
		return 0, errors.New("list don't have that much elements")

	} else if list.lenght == 0 {
		// if linked list is empty
		return 0, errors.New("list is empty")

	} else if list.lenght == 1 {
		// if linked list only contains one element
		current := list.start
		list.start = nil
		list.end = nil
		list.lenght--
		return current.data, nil

	} else if position == 1 {
		// deleting first element in the linked list (DeleteStart)
		current := list.start
		list.start = list.start.next
		list.start.prev = nil
		current.next = nil
		list.lenght--
		return current.data, nil

	} else if position == list.lenght {
		// deleting last element in the linked list (DeleteEnd)
		current := list.end
		list.end = list.end.prev
		list.end.next = nil
		list.lenght--
		return current.data, nil

	} else {
		// deleting nth element
		current := list.start
		for i := 1; i < position; i++ {
			current = current.next
		}
		current.prev.next = current.next
		current.next.prev = current.prev
		list.lenght--
		return current.data, nil
	}
}

func (list *DoublyLinkedList) PrintList() {
	current := list.start
	for {
		fmt.Printf("%d", current.data)
		if current.next == nil {
			break
		}
		current = current.next
		fmt.Printf(" -> ")
	}
	fmt.Println()
}
