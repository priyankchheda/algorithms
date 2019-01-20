// Package queue is a implementation of queue data structure in go
package main

import "errors"

// Queue struct contains data and methods are queue operations.
type Queue struct {
	array []int
}

// NewQueue creates new empty integer queue.
func NewQueue() Queue {
	return Queue{array: make([]int, 0)}
}

// Enqueue adds an item to the queue.
func (q *Queue) Enqueue(value int) {
	q.array = append(q.array, value)
}

// Dequeue removes an item front the queue.
// Returns error if the queue is empty.
func (q *Queue) Dequeue() (removedElement int, err error) {
	if q.IsEmpty() {
		return 0, errors.New("queue is empty")
	}
	removedElement = q.array[0]
	q.array[0] = 0
	q.array = q.array[1:]
	return removedElement, nil
}

// Size returns the number of elements currently present in queue
func (q *Queue) Size() int {
	return len(q.array)
}

// IsEmpty checks if the queue is empty or not
func (q *Queue) IsEmpty() bool {
	return len(q.array) <= 0
}
