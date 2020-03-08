package queue_test

import (
	"testing"

	"github.com/x899/algorithms/queue"
)

func TestEnqueueDequeue(t *testing.T) {
	tables := []struct {
		data []int
	}{
		{[]int{67}},
		{[]int{1, 2, 3, 4, 5}},
		{[]int{67, 34, 23, 78, 78, 12}},
		{[]int{367, 834, 242}},
	}

	for _, table := range tables {
		q := queue.NewQueue()
		for i, element := range table.data {
			q.Enqueue(element)
			if i+1 != q.Size() {
				t.Errorf("Incorrect Size expected: %d got: %d",
					i+1, q.Size())
			}
		}

		for i := 0; i < len(table.data); i++ {
			removedItem, err := q.Dequeue()
			if err != nil {
				t.Errorf("error while dequeue")
			}
			if removedItem != table.data[i] {
				t.Errorf("Wrong output expected: %d got: %d",
					table.data[i], removedItem)
			}
		}
	}
}

func TestDequeueEmpty(t *testing.T) {
	q := queue.NewQueue()
	removedItem, err := q.Dequeue()
	if err == nil {
		t.Errorf("error: dequeuing from empty queue")
	}
	if removedItem != 0 {
		t.Errorf("removedItem is not zero valued")
	}
}
