package main

import (
	"testing"
)

func TestPush(t *testing.T) {
	tables := []struct {
		data []int
	}{
		{[]int{67}},
		{[]int{1, 2, 3, 4, 5}},
		{[]int{67, 34, 23, 78, 78, 12}},
		{[]int{367, 834, 242}},
	}

	for _, table := range tables {
		s := NewStack()
		for i, element := range table.data {
			s.Push(element)
			if i+1 != s.Size() {
				t.Errorf("Incorrect Size expected: %d got: %d",
					i+1, s.Size())
			}
		}
		for i := 0; i < s.Size(); i++ {
			if s.array[i] != table.data[i] {
				t.Errorf("Wrong Output expected:%d got: %d",
					table.data[i], s.array)
			}
		}
	}
}

func TestPeekPop(t *testing.T) {
	tables := []struct {
		data []int
	}{
		{[]int{67}},
		{[]int{1, 2, 3, 4, 5}},
		{[]int{67, 34, 23, 78, 78, 12}},
		{[]int{367, 834, 242}},
	}

	for _, table := range tables {
		s := NewStack()
		for i, element := range table.data {
			s.Push(element)
			if i+1 != s.Size() {
				t.Errorf("Incorrect Size expected: %d got: %d",
					i+1, s.Size())
			}
		}

		for i := 0; i < len(table.data); i++ {
			peekItem, err := s.Peek()
			if err != nil {
				t.Errorf("Error while peeking: %v", err)
			}
			if peekItem != table.data[len(table.data)-1-i] {
				t.Errorf("Wrong Answer expected: %v got: %v",
					table.data[s.Size()-1-i], peekItem)
			}

			removedItem, err := s.Pop()
			if err != nil {
				t.Errorf("Error while poping: %v", err)
			}
			if removedItem != table.data[len(table.data)-1-i] {
				t.Errorf("Wrong Answer expected: %v got: %v",
					table.data[s.Size()-1-i], removedItem)
			}
		}
	}
}

func TestPeekPopEmpty(t *testing.T) {
	s := NewStack()
	peekItem, err := s.Peek()
	if err == nil {
		t.Errorf("error: peeking from empty stack")
	}
	if peekItem != 0 {
		t.Errorf("wrong peeking item expected: 0 got: %v", peekItem)
	}

	removedItem, err := s.Pop()
	if err == nil {
		t.Errorf("error: popping from empty stack")
	}
	if removedItem != 0 {
		t.Errorf("wrong removed item expected: 0 got: %v", removedItem)
	}
}
