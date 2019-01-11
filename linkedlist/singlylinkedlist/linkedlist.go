package main

import (
	"errors"
	"fmt"
)

type Node struct {
	data int
	next *Node
}

type LinkedList struct {
	lenght int
	start  *Node
	end    *Node
}

func (list *LinkedList) Head() *Node {
	return list.start
}

func (list *LinkedList) Tail() *Node {
	return list.end
}

func (list *LinkedList) Lenght() int {
	return list.lenght
}

func (list *LinkedList) InsertStart(node *Node) {
	list.InsertAt(node, 1)
}

func (list *LinkedList) InsertEnd(node *Node) {
	list.InsertAt(node, list.Lenght()+1)
}

func (list *LinkedList) InsertAt(node *Node, position int) error {
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
		current.next = node
		list.end = node

	} else if position == 1 {
		// inserting element to first position (InsertStart)
		current := list.start
		list.start = node
		node.next = current

	} else {
		// inserting at nth position
		current := list.start
		currentPrev := list.start
		for i := 1; i < position; i++ {
			currentPrev = current
			current = current.next
		}
		currentPrev.next = node
		node.next = current
	}
	list.lenght++
	return nil
}

func (list *LinkedList) DeleteStart() (int, error) {
	return list.DeleteAt(1)
}

func (list *LinkedList) DeleteEnd() (int, error) {
	return list.DeleteAt(list.lenght)
}

func (list *LinkedList) DeleteAt(position int) (int, error) {
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
		list.start = current.next
		list.lenght--
		return current.data, nil

	} else if position == list.lenght {
		// deleting last element in the linked list (DeleteEnd)
		current := list.start
		currentPrev := list.start
		for {
			if current.next == nil {
				break
			}
			currentPrev = current
			current = current.next
		}
		currentPrev.next = nil
		list.lenght--
		return current.data, nil

	} else {
		// deleting nth element
		current := list.start
		currentPrev := list.start
		for i := 1; i < position; i++ {
			currentPrev = current
			current = current.next
		}
		currentPrev.next = current.next
		current.next = nil
		list.lenght--
		return current.data, nil
	}
}

func (list *LinkedList) DataAt(position int) (int, error) {
	if list.lenght < position {
		return 0, errors.New("list don't have that much elements")
	}
	current := list.start
	for i := 1; i < position; i++ {
		current = current.next
	}
	return current.data, nil
}

func (list *LinkedList) ReverseIterative() {
	var current, prev, next *Node
	current = list.start

	for current != nil {
		next = current.next
		current.next = prev
		prev = current
		current = next
	}
	list.start = prev
}

func (list *LinkedList) ReverseRecursive(p *Node) {
	if p.next == nil {
		list.start = p
		return
	}
	list.ReverseRecursive(p.next)
	q := p.next
	q.next = p
	p.next = nil
}

func (list *LinkedList) PrintList() {
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

func PrintReverseRecursive(p *Node) {
	if p == nil {
		return
	}
	PrintReverseRecursive(p.next)
	fmt.Printf("%d ", p.data)
}

func PrintRecursive(p *Node) {
	if p == nil {
		fmt.Println()
		return
	}
	fmt.Printf("%d ", p.data)
	PrintRecursive(p.next)
}
