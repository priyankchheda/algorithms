// Package stack is a implementation of stack data structure in go
package stack

import (
	"errors"
)

// Stack struct contains data and methods are stack operations
type Stack struct {
	array []string
}

// NewStack creates new empty integer stack
func NewStack() Stack {
	return Stack{array: make([]string, 0)}
}

// Push element in the stack
func (s *Stack) Push(value string) {
	s.array = append(s.array, value)
}

// Pop removes element from the stack. Returns error if the stack is empty
func (s *Stack) Pop() (removedElement string, err error) {
	if s.IsEmpty() {
		return "", errors.New("stack is empty")
	}
	arraySize := len(s.array)
	removedElement = s.array[arraySize-1]
	s.array[arraySize-1] = "" // prevent memory leak
	s.array = s.array[:arraySize-1]
	return removedElement, nil
}

// Peek returns top element from the stack without removing it. Returns error
// if the stack is empty.
func (s *Stack) Peek() (topElement string, err error) {
	if s.IsEmpty() {
		return "", errors.New("stack is empty")
	}
	return s.array[len(s.array)-1], nil
}

// Size returns the number of elements currently present in stack
func (s *Stack) Size() int {
	return len(s.array)
}

// IsEmpty checks if the stack is empty or not
func (s Stack) IsEmpty() bool {
	return len(s.array) <= 0
}
