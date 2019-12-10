package set

import (
	"fmt"
	"strings"
)

// Set defines a non-thread safe set data structure
type Set struct {
	m map[int]struct{} // struct{} doesn't take up space
}

// helpful to not write everywhere struct{}{}
var keyExists = struct{}{}

// NewSet creates and initializes a new non-threatsafe Set.
func NewSet() *Set {
	s := &Set{}
	s.m = make(map[int]struct{})
	return s
}

// Add includes the specified items (one or more) to the set. The underlying
// Set s is modified. If passed nothing it silently returns.
func (s *Set) Add(items ...int) {
	if len(items) == 0 {
		return
	}
	for _, item := range items {
		s.m[item] = keyExists
	}
}

// Size returns the number of items in a set.
func (s *Set) Size() int {
	return len(s.m)
}

// Has looks for the existance of items passed. It returns false if nothing is
// passed. For multiple items, it returns true if all of the items exist.
func (s *Set) Has(items ...int) bool {
	// assume checked for empty item, which not exist
	if len(items) == 0 {
		return false
	}

	has := true
	for _, item := range items {
		if _, has = s.m[item]; !has {
			break
		}
	}
	return has
}

// Remove deletes the specified items from the set. The underlying Set s is
// modified. If passed nothing it silently returns.
func (s *Set) Remove(items ...int) {
	if len(items) == 0 {
		return
	}
	for _, item := range items {
		delete(s.m, item)
	}
}

// Pop deletes and return an item from the set. The underlying Set s is
// modified. If set is empty, nil is returned.
func (s *Set) Pop() (int, error) {
	for item := range s.m {
		delete(s.m, item)
		return item, nil
	}
	return 0, fmt.Errorf("set is empty")
}

// Clear removes all items from the set.
func (s *Set) Clear() {
	s.m = make(map[int]struct{})
}

// IsEmpty reports whether the set is empty.
func (s *Set) IsEmpty() bool {
	return s.Size() == 0
}

// IsEqual tests whether s and t are same in size and have exactly same
// content.
func (s *Set) IsEqual(t *Set) bool {
	if s.Size() != t.Size() {
		return false
	}

	equal := true
	for item := range t.m {
		_, equal = s.m[item]
		if !equal {
			break
		}
	}
	return equal
}

//IsSubset tests whether t is a subset of s.
func (s *Set) IsSubset(t *Set) bool {
	subset := true
	for item := range t.m {
		_, subset = s.m[item]
		if !subset {
			break
		}
	}
	return subset
}

// IsSuperset tests whether t is a superset of s.
func (s *Set) IsSuperset(t *Set) bool {
	return t.IsSubset(s)
}

// Copy returns a new Set with a copy of s.
func (s *Set) Copy() *Set {
	u := NewSet()
	for item := range s.m {
		u.Add(item)
	}
	return u
}

// String returns a string representation of s
func (s *Set) String() string {
	t := make([]string, 0, s.Size())
	for item := range s.m {
		t = append(t, fmt.Sprintf("%v", item))
	}

	return fmt.Sprintf("[%s]", strings.Join(t, ", "))
}

// List returns a slice of all items.
func (s *Set) List() []int {
	list := make([]int, 0, s.Size())

	for item := range s.m {
		list = append(list, item)
	}
	return list
}

// Merge is like Union, however it modifies the current set it's applied on
// with the given t set.
func (s *Set) Merge(t *Set) {
	for item := range t.m {
		s.m[item] = keyExists
	}
}

// Separate removes the set items containing in t from set s. Please aware that
// it's not the opposite of Merge.
func (s *Set) Separate(t *Set) {
	s.Remove(t.List()...)
}

// Union is the merger of multiple sets. It returns a new set with all the
// elements present in all the sets that are passed.
func Union(set1, set2 *Set, setItems ...*Set) *Set {
	u := set1.Copy()
	for item := range set2.m {
		u.Add(item)
	}

	for _, setItem := range setItems {
		for item := range setItem.m {
			u.Add(item)
		}
	}
	return u
}
