package main

import "errors"

type Stack struct {
	array []int
}

func NewStack() Stack {
	return Stack{array: make([]int, 0)}
}

func (s *Stack) Push(value int) {
	s.array = append(s.array, value)
}

func (s *Stack) Pop() (removedElement int, err error) {
	if s.IsEmpty() {
		return 0, errors.New("stack is empty")
	}
	arraySize := len(s.array)
	removedElement = s.array[arraySize-1]
	s.array[arraySize-1] = 0 // prevent memory leak
	s.array = s.array[:arraySize-1]
	return removedElement, nil
}

func (s *Stack) Peek() (topElement int, err error) {
	if s.IsEmpty() {
		return 0, errors.New("stack is empty")
	}
	return s.array[len(s.array)-1], nil
}

func (s *Stack) Size() int {
	return len(s.array)
}

func (s Stack) IsEmpty() bool {
	return len(s.array) <= 0
}
