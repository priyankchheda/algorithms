package set_test

import (
	"testing"

	"github.com/x899/algorithms/set"
)

func TestHas(t *testing.T) {
	s := set.NewSet()
	s.Add(34, 546, 234, 78)

	if s.Has() {
		t.Error("empty parameters expected false, but returning true")
	}
	if !s.Has(34) {
		t.Error("the item 34 exist, but 'Has' is returning false")
	}
	if !s.Has(34, 546, 234, 78) {
		t.Error("the items all exist, but 'Has' is returning false")
	}
	if s.Has(34, 546, 234, 77) {
		t.Error("77 doesn't exist in set, but 'Has' is returning true")
	}
}

func TestAddSingle(t *testing.T) {
	s := set.NewSet()
	s.Add()
	s.Add(1)
	s.Add(1) // duplicate entry
	s.Add(2)
	s.Add(3)
	s.Add(2) // duplicate entry

	if actualSize := s.Size(); actualSize != 3 {
		t.Errorf("wrong answer expected: 5, got:%v", actualSize)
	}

	if !s.Has(1, 2, 3) {
		t.Error("added items are not availabile in the set.")
	}
}

func TestAddMultiple(t *testing.T) {
	s := set.NewSet()
	s.Add(12, 23, 35, 47)

	if actualSize := s.Size(); actualSize != 4 {
		t.Errorf("wrong answer expected: 5, got:%v", actualSize)
	}

	if !s.Has(12, 23, 35, 47) {
		t.Error("added items are not availabile in the set.")
	}
}

func TestRemoveSingle(t *testing.T) {
	s := set.NewSet()
	s.Add(1)
	s.Add(2)
	s.Add(3)

	s.Remove(2)
	if s.Size() != 2 {
		t.Error("Remove: set size should be two after removing")
	}

	s.Remove(2)
	if s.Size() != 2 {
		t.Error("Remove: set size should not change after removing 2 again")
	}

	s.Remove(1)
	s.Remove(3)
	if s.Size() != 0 {
		t.Error("Remove: set size should be zero")
	}

	// try to remove something from a zero length set
	s.Remove(34)
}

func TestRemoveMultiple(t *testing.T) {
	s := set.NewSet()
	s.Add(1, 3, 4, 5)
	s.Remove()
	if s.Size() != 4 {
		t.Error("Remove: items are not unique. The set size should be four")
	}

	s.Remove(3, 4, 5)
	if s.Size() != 1 {
		t.Error("Remove: items are not unique. The set size should be one")
	}

	if !s.Has(1) {
		t.Error("added items are not available in the set.")
	}
}

func TestPop(t *testing.T) {
	s := set.NewSet()
	s.Add(1, 3, 4, 5)
	a, _ := s.Pop()
	if s.Size() != 3 {
		t.Error("Pop: set size should be two after popping out")
	}

	if s.Has(a) {
		t.Error("Pop: returned item should not exist")
	}

	s.Pop()
	s.Pop()
	s.Pop()
	b, err := s.Pop()
	if b != 0 {
		t.Error("Pop: should return 0 because set is empty")
	}
	if err.Error() != "set is empty" {
		t.Error("error message should be 'set is empty'")
	}

	//try to remove something from a zero length set
	s.Pop()
}

func TestClear(t *testing.T) {
	s := set.NewSet()
	s.Add(1)
	s.Add(2)
	s.Add(3, 4, 5)

	s.Clear()
	if s.Size() != 0 {
		t.Error("Clear: set size should be zero")
	}
}

func TestIsEmpty(t *testing.T) {
	s := set.NewSet()
	if !s.IsEmpty() {
		t.Error("IsEmpty: set is empty, it should be true")
	}

	s.Add(1, 2, 3)
	if s.IsEmpty() {
		t.Error("IsEmpty: set is filled, it should be false")
	}
}
