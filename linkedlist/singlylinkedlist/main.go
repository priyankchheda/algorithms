package main

import (
	"fmt"
)

func main() {
	fmt.Println("Linked List Program")
	list := LinkedList{0, nil, nil}

	node := Node{5, nil}
	list.InsertStart(&node)

	node1 := Node{6, nil}
	list.InsertStart(&node1)

	node3 := Node{7, nil}
	list.InsertEnd(&node3)

	node4 := Node{8, nil}
	list.InsertStart(&node4)

	list.InsertEnd(&Node{2, nil})

	list.InsertAt(&Node{99, nil}, 4)

	list.InsertStart(&Node{9, nil})

	list.PrintList()
	list.ReverseRecursive(list.Head())
	list.PrintList()
	PrintRecursive(list.Head())
	PrintReverseRecursive(list.Head())

	i, _ := list.DataAt(3)
	fmt.Printf("data at 3: %d\n", i)
	list.PrintList()

	fmt.Println("Lenght: ", list.Lenght())

	d2, _ := list.DeleteAt(3)
	fmt.Printf("deleted item: %d\n", d2)
	list.PrintList()
	fmt.Println("Lenght: ", list.Lenght())

	i2, _ := list.DataAt(2)
	fmt.Printf("data at 2: %d\n", i2)
	fmt.Println("Lenght: ", list.Lenght())
	list.PrintList()
	//list.ReverseIterative()
	list.ReverseRecursive(list.Head())
	list.PrintList()
}
