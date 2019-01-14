package main

import "errors"

type Queue struct {
	array []int
}

func NewQueue() Queue {
	return Queue{array: make([]int, 0)}
}

func (q *Queue) Enqueue(value int) {
	q.array = append(q.array, value)
}

func (q *Queue) Dequeue() (removedElement int, err error) {
	if q.IsEmpty() {
		return 0, errors.New("queue is empty")
	}
	removedElement = q.array[0]
	q.array[0] = 0
	q.array = q.array[1:]
	return removedElement, nil
}

func (q *Queue) Size() int {
	return len(q.array)
}

func (q *Queue) IsEmpty() bool {
	return len(q.array) <= 0
}
