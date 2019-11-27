package set

import "fmt"

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
