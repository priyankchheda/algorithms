package set

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
