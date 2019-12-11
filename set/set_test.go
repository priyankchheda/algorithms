package set_test

import (
	"strings"
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

func TestIsEqual(t *testing.T) {
	a := set.NewSet()
	a.Add(1, 2, 3)
	b := set.NewSet()
	b.Add(1, 2, 3)

	ok := a.IsEqual(b)
	if !ok {
		t.Error("IsEqual: set a and b are equal. However it returns false")
	}

	// same size, different content
	a = set.NewSet()
	a.Add(1, 2, 3)
	b = set.NewSet()
	b.Add(4, 5, 6)

	ok = a.IsEqual(b)
	if ok {
		t.Error("IsEqual: set a and b are not equal. However it returns true")
	}

	// different size, similar content
	a = set.NewSet()
	a.Add(1, 2, 3)
	b = set.NewSet()
	b.Add(1, 2, 3, 4)

	ok = a.IsEqual(b)
	if ok {
		t.Error("IsEqual: set a and b are not equal. However it returns true")
	}
}

func TestIsSubset(t *testing.T) {
	s := set.NewSet()
	s.Add(1, 2, 3, 4)
	u := set.NewSet()
	u.Add(1, 2, 3)

	ok := s.IsSubset(u)
	if !ok {
		t.Error("IsSubset: u is a subset of s. However it returns false")
	}

	ok = u.IsSubset(s)
	if ok {
		t.Error("IsSubset: s is not a subset of u. However it returns true")
	}
}

func TestIsSuperset(t *testing.T) {
	s := set.NewSet()
	s.Add(1, 2, 3, 4)
	u := set.NewSet()
	u.Add(1, 2, 3)

	ok := u.IsSuperset(s)
	if !ok {
		t.Error("IsSuperset: u is a superset of s. However it returns false")
	}

	ok = s.IsSuperset(u)
	if ok {
		t.Error("IsSuperset: s is not a superset of u. However it returns true")
	}
}

func TestString(t *testing.T) {
	s := set.NewSet()
	if s.String() != "[]" {
		t.Errorf("String: output is not what is excepted '%s'", s.String())
	}

	s.Add(1, 2, 3, 4)
	if !strings.HasPrefix(s.String(), "[") {
		t.Error("String: output should begin with a square bracket")
	}

	if !strings.HasSuffix(s.String(), "]") {
		t.Error("String: output should end with a square bracket")
	}
}

func TestList(t *testing.T) {
	s := set.NewSet()
	if len(s.List()) != 0 {
		t.Errorf("len of list excepted - 0, got - '%v'", s.List())
	}

	s.Add(1, 2, 3, 4)
	if len(s.List()) != 4 {
		t.Errorf("len of list excepted - 4, got - '%v'", s.List())
	}
}

func TestCopy(t *testing.T) {
	s := set.NewSet()
	s.Add(1, 2, 3, 4, 5)
	u := s.Copy()

	if !s.IsEqual(u) {
		t.Error("Copy: set s and u are not equal")
	}
}

func TestMerge(t *testing.T) {
	s := set.NewSet()
	s.Add(1, 2, 3)
	r := set.NewSet()
	r.Add(3, 4, 5)
	s.Merge(r)

	if s.Size() != 5 {
		t.Error("Merge: the set doesn't have all items in it.")
	}

	if !s.Has(1, 2, 3, 4, 5) {
		t.Error("Merge: merged items are not availabile in the set.")
	}
}

func TestSeparate(t *testing.T) {
	s := set.NewSet()
	s.Add(1, 2, 3)
	r := set.NewSet()
	r.Add(3, 5)
	s.Separate(r)

	if s.Size() != 2 {
		t.Error("Separate: the set doesn't have all items in it.")
	}

	if !s.Has(1, 2) {
		t.Error("Separate: items after separation are not availabile in the set.")
	}
}

func TestUnion(t *testing.T) {
	s1 := set.NewSet()
	s1.Add(1, 2, 3)
	s2 := set.NewSet()
	s2.Add(4, 5, 6)
	s3 := set.NewSet()
	s3.Add(1, 5, 7)

	u := set.Union(s1, s2, s3)
	if u.Size() != 7 {
		t.Errorf("expected size 7 got %v", u.Size())
	}

	if !u.Has(1, 2, 3, 4, 5, 6, 7) {
		t.Error("merged items are not availabile in union set")
	}
}

func TestIntersection(t *testing.T) {
	s1 := set.NewSet()
	s1.Add(1, 2, 3, 4, 5)
	s2 := set.NewSet()
	s2.Add(4, 2, 6, 5)
	s3 := set.NewSet()
	s3.Add(1, 4, 5, 7)

	u := set.Intersection(s1, s2, s3)
	if u.Size() != 2 {
		t.Errorf("expected size 2 got %v", u.Size())
	}

	if !u.Has(4, 5) {
		t.Error("merged items are not availabile in union set")
	}
}

func TestIntersection2(t *testing.T) {
	s1 := set.NewSet()
	s1.Add(1, 2, 3, 4, 5)
	s2 := set.NewSet()
	s2.Add(6, 7)

	u := set.Intersection(s1, s2)
	if u.Size() != 0 {
		t.Errorf("expected size 0 got %v", u.Size())
	}

	if !u.IsEmpty() {
		t.Error("union set should be empty")
	}
}
