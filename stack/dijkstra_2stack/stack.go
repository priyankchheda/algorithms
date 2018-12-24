package main

import (
	"fmt"
)

type stackError struct {
	code int
	msg  string
}

func (se *stackError) Error() string {
	return fmt.Sprintf("code %d: %s", se.code, se.msg)
}

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
		return "", &stackError{2, "stack is empty"}
	}
	arraySize := len(s.array)
	removedElement = s.array[arraySize-1]
	s.array = s.array[:arraySize-1]
	return removedElement, nil
}

func (s *stack) peek() (topElement string, err error) {
	if s.isEmpty() {
		return "", &stackError{2, "stack is empty"}
	}
	return s.array[len(s.array)-1], nil
}

func (s *stack) size() int {
	return len(s.array)
}

func (s stack) isEmpty() bool {
	return len(s.array) <= 0
}
