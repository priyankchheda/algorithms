package redblacktree_test

import (
	"testing"

	"github.com/x899/algorithms/redblacktree"
)

func TestInsert(t *testing.T) {
	tree := redblacktree.NewRBTree()
	tree.Insert(1)
	tree.Insert(2)
	tree.Insert(3)
	tree.Insert(7)
	tree.Insert(7)
	tree.Insert(6)
	tree.Insert(4)
	tree.Insert(5)

	if actualValue := tree.Size; actualValue != 7 {
		t.Errorf("wrong answer expected: %v got:%v", 7, actualValue)
	}
}
