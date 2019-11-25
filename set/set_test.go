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
