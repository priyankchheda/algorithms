package main

import (
	"testing"
)

func getDLLDataInSlice(list *DoublyLinkedList) []int {
	var data []int
	current := list.start
	for {
		if current == nil {
			break
		}
		data = append(data, current.data)
		current = current.next
	}
	return data
}

func TestInsertStart(t *testing.T) {
	tables := []struct {
		data     []int
		expected []int
	}{
		{[]int{1, 2, 3, 4, 5}, []int{5, 4, 3, 2, 1}},
		{[]int{67, 34, 23, 78, 78, 12}, []int{12, 78, 78, 23, 34, 67}},
		{[]int{367, 834, 242}, []int{242, 834, 367}},
	}

	for _, table := range tables {
		list := DoublyLinkedList{0, nil, nil}
		array := table.data
		expected_array := table.expected
		for i, nodeData := range array {
			list.InsertStart(&Node{nodeData, nil, nil})
			if i+1 != list.Lenght() {
				t.Errorf("Wrong Lenght got: %v expected: %v",
					list.Lenght(), i+1)
			}
		}
		output := getDLLDataInSlice(&list)
		for i := 0; i < len(array); i++ {
			if output[i] != expected_array[i] {
				t.Errorf("Wrong Output expected: %d got: %d",
					array[i], output[i])
			}
		}
	}
}

func TestInsertEnd(t *testing.T) {
	tables := []struct {
		data []int
	}{
		{[]int{1, 2, 3, 4, 5}},
		{[]int{67, 34, 23, 78, 78, 12}},
		{[]int{367, 834, 242}},
	}

	for _, table := range tables {
		list := DoublyLinkedList{0, nil, nil}
		array := table.data
		for i, nodeData := range array {
			list.InsertEnd(&Node{nodeData, nil, nil})
			if i+1 != list.Lenght() {
				t.Errorf("Wrong Lenght got: %v expected: %v",
					list.Lenght(), i+1)
			}
		}
		output := getDLLDataInSlice(&list)
		for i := 0; i < len(array); i++ {
			if output[i] != array[i] {
				t.Errorf("Wrong Output expected: %d got: %d",
					array[i], output[i])
			}
		}
	}
}

func TestHeadTailLenght(t *testing.T) {
	tables := []struct {
		data []int
	}{
		{[]int{1, 2, 3, 4, 5}},
		{[]int{67, 34, 23, 78, 78, 12}},
		{[]int{367, 834, 242}},
	}

	for _, table := range tables {
		list := DoublyLinkedList{0, nil, nil}
		array := table.data
		for i, nodeData := range array {
			list.InsertEnd(&Node{nodeData, nil, nil})
			if i+1 != list.Lenght() {
				t.Errorf("Wrong Lenght got: %v expected: %v",
					list.Lenght(), i+1)
			}
		}
		output := getDLLDataInSlice(&list)
		head := list.Head()
		if output[0] != head.data {
			t.Errorf("Wrong Head expected: %d got: %d", output[0], head.data)
		}

		tail := list.Tail()
		if output[len(output)-1] != tail.data {
			t.Errorf("Wrong Tail expected: %d got: %d",
				output[len(output)-1], tail.data)
		}
		lenght := list.Lenght()
		if len(output) != lenght {
			t.Errorf("Wrong lenght expected: %d got: %d", len(output), lenght)
		}
	}
}

func TestDeleteStart1(t *testing.T) {
	tables := []struct {
		data []int
	}{
		{[]int{67}},
		{[]int{1, 2, 3, 4, 5}},
		{[]int{67, 34, 23, 78, 78, 12}},
		{[]int{367, 834, 242}},
	}

	for _, table := range tables {
		list := DoublyLinkedList{0, nil, nil}
		array := table.data
		for i, nodeData := range array {
			list.InsertEnd(&Node{nodeData, nil, nil})
			if i+1 != list.Lenght() {
				t.Errorf("Wrong Lenght got: %v expected: %v",
					list.Lenght(), i+1)
			}
		}
		output := getDLLDataInSlice(&list)
		for _, nodeData := range output {
			deletedNode, err := list.DeleteStart()
			if err != nil {
				t.Errorf("error msg: %v", err)
			}
			if deletedNode != nodeData {
				t.Errorf("Wrong output expected: %d got:%d",
					nodeData, deletedNode)
			}
		}
	}
}

func TestDeleteStart2(t *testing.T) {
	list := DoublyLinkedList{0, nil, nil}
	deletedNode, err := list.DeleteStart()
	if err == nil {
		t.Errorf("Error: no error when deleting from empty list")
	}
	if deletedNode != 0 {
		t.Errorf("deleted node is not zerod value")
	}
}

func TestDeleteEnd1(t *testing.T) {
	tables := []struct {
		data []int
	}{
		{[]int{67}},
		{[]int{1, 2, 3, 4, 5}},
		{[]int{67, 34, 23, 78, 78, 12}},
		{[]int{367, 834, 242}},
	}

	for _, table := range tables {
		list := DoublyLinkedList{0, nil, nil}
		array := table.data
		for i, nodeData := range array {
			list.InsertStart(&Node{nodeData, nil, nil})
			if i+1 != list.Lenght() {
				t.Errorf("Wrong Lenght got: %v expected: %v",
					list.Lenght(), i+1)
			}
		}
		output := getDLLDataInSlice(&list)
		for i := len(output) - 1; i >= 0; i-- {
			deletedNode, err := list.DeleteEnd()
			if err != nil {
				t.Errorf("Error Msg: %v", err)
			}
			if output[i] != deletedNode {
				t.Errorf("Wrong Output expected: %d got: %d",
					output[i], deletedNode)
			}
		}
	}
}

func TestDeleteEnd2(t *testing.T) {
	list := DoublyLinkedList{0, nil, nil}
	deletedNode, err := list.DeleteEnd()
	if err == nil {
		t.Errorf("Error: no error when deleting from empty list")
	}
	if deletedNode != 0 {
		t.Errorf("deleted node is not zerod value")
	}
}

func TestDeleteAt1(t *testing.T) {
	tables := []struct {
		data        []int
		position    int
		output      []int
		deletedItem int
	}{
		{[]int{67}, 1, []int{}, 67},
		{[]int{1, 2, 3, 4, 5}, 3, []int{1, 2, 4, 5}, 3},
		{[]int{67, 34, 23, 78, 78, 12}, 5, []int{67, 34, 23, 78, 12}, 78},
		{[]int{367, 834, 242}, 3, []int{367, 834}, 242},
		{[]int{367, 834, 242}, 1, []int{834, 242}, 367},
	}
	for _, table := range tables {
		list := DoublyLinkedList{0, nil, nil}
		for i, nodeData := range table.data {
			list.InsertEnd(&Node{nodeData, nil, nil})
			if i+1 != list.Lenght() {
				t.Errorf("Wrong Lenght got: %v expected: %v",
					list.Lenght(), i+1)
			}
		}
		deletedNode, err := list.DeleteAt(table.position)
		if err != nil {
			t.Errorf("Error: %v", err)
		}
		if table.deletedItem != deletedNode {
			t.Errorf("Wrong Output expected: %v got: %v",
				table.deletedItem, deletedNode)
		}
		listAfterDeleting := getDLLDataInSlice(&list)
		for i, nodeData := range listAfterDeleting {
			if nodeData != table.output[i] {
				t.Errorf("Wrong Output expected: %v, got: %v",
					table.output, listAfterDeleting)
			}
		}
	}

}

func TestDeleteAt2(t *testing.T) {
	list := DoublyLinkedList{0, nil, nil}
	deletedNode, err := list.DeleteAt(9)
	if err == nil {
		t.Errorf("Error: %v", err)
	}
	if deletedNode != 0 {
		t.Errorf("deleted node is not zero valued")
	}
}

func TestInsertAt1(t *testing.T) {
	tables := []struct {
		input    []int
		element  int
		position int
		output   []int
	}{
		{[]int{}, 45, 1, []int{45}},
		{[]int{67}, 45, 1, []int{45, 67}},
		{[]int{1, 2, 3, 4, 5}, 6, 6, []int{1, 2, 3, 4, 5, 6}},
		{[]int{67, 34, 23, 78, 78, 12}, 12, 4, []int{67, 34, 23, 12, 78, 78, 12}},
		{[]int{367, 834, 242}, 345, 2, []int{367, 345, 834, 242}},
	}

	for _, table := range tables {
		list := DoublyLinkedList{0, nil, nil}
		for i, nodeData := range table.input {
			list.InsertEnd(&Node{nodeData, nil, nil})
			if i+1 != list.Lenght() {
				t.Errorf("Wrong Lenght got: %v expected: %v",
					list.Lenght(), i+1)
			}
		}
		err := list.InsertAt(&Node{table.element, nil, nil}, table.position)
		if err != nil {
			t.Errorf("Error: %v\n", err)
		}
		finalList := getDLLDataInSlice(&list)
		for i := 0; i < len(finalList); i++ {
			if finalList[i] != table.output[i] {
				t.Errorf("Wrong output got: %v expected: %v",
					finalList, table.output)
			}
		}
	}
}

func TestInsertAt2(t *testing.T) {
	list := DoublyLinkedList{0, nil, nil}
	err := list.InsertAt(&Node{6, nil, nil}, 9)
	if err == nil {
		t.Errorf("Error: %v", err)
	}
}
