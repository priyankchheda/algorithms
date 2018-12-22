package main

import (
	"errors"
)

type stack struct {
	array []string
}

func newStack() stack {
	return stack{array: make([]string, 0, 10)}
}

func (s *stack) push(value string) {
	s.array = append(s.array, value)
}

func (s *stack) pop() (removedElement string, err error) {
	if s.isEmpty() {
		return "", errors.New("stack is empty")
	}
	arraySize := len(s.array)
	removedElement = s.array[arraySize-1]
	s.array = s.array[:arraySize-1]
	return removedElement, nil
}

func (s stack) isEmpty() bool {
	return len(s.array) <= 0
}
