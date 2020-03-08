package stack_test

import (
	"testing"

	"github.com/x899/algorithms/stack"
)

func TestPushPeekPop(t *testing.T) {
	tests := []struct {
		data []string
	}{
		{[]string{"stack test"}},
		{[]string{"a", "b", "c", "d", "e"}},
		{[]string{"67", "34", "23", "78", "78", "12"}},
		{[]string{"367", "834", "242"}},
	}

	for _, test := range tests {
		s := stack.NewStack()
		for i, element := range test.data {
			s.Push(element)
			if i+1 != s.Size() {
				t.Errorf("Incorrect Size expected: %d got: %d",
					i+1, s.Size())
			}
		}

		for i := 0; i < len(test.data); i++ {
			peekItem, err := s.Peek()
			if err != nil {
				t.Errorf("Error while peeking: %v", err)
			}
			if peekItem != test.data[len(test.data)-1-i] {
				t.Errorf("Wrong Answer expected: %v got: %v",
					test.data[s.Size()-1-i], peekItem)
			}

			removedItem, err := s.Pop()
			if err != nil {
				t.Errorf("Error while poping: %v", err)
			}
			if removedItem != test.data[len(test.data)-1-i] {
				t.Errorf("Wrong Answer expected: %v got: %v",
					test.data[s.Size()-1-i], removedItem)
			}
		}
	}
}

func TestPeekPopEmpty(t *testing.T) {
	s := stack.NewStack()
	peekItem, err := s.Peek()
	if err == nil {
		t.Errorf("error: peeking from empty stack")
	}
	if peekItem != "" {
		t.Errorf("wrong peeking item expected: 0 got: %v", peekItem)
	}

	removedItem, err := s.Pop()
	if err == nil {
		t.Errorf("error: popping from empty stack")
	}
	if removedItem != "" {
		t.Errorf("wrong removed item expected: 0 got: %v", removedItem)
	}
}
