package hashtable_test

import (
	"testing"

	"github.com/x899/algorithms/hashtable"
)

func TestCreateHashTable(t *testing.T) {
	tableSize := 3
	ht := hashtable.CreateHashTable()
	if len(ht.Hash) != tableSize {
		t.Errorf("wrong output expected: %d got: %d", tableSize, len(ht.Hash))
	}
}

func TestPut(t *testing.T) {
	ht := hashtable.CreateHashTable()
	ht.Put(1, 2)
	present, value := ht.Get(1)
	if present == false || value != 2 {
		t.Errorf("wrong output got: %t %d expected: false 2", present, value)
	}
	ht.Put(1, 3)
	present, value = ht.Get(1)
	if present == false || value != 3 {
		t.Errorf("wrong output got: %t %d expected: false 3", present, value)
	}
}

func TestGet(t *testing.T) {
	ht := hashtable.CreateHashTable()
	ht.Put(1, 2)
	present, value := ht.Get(1)
	if present == false || value != 2 {
		t.Errorf("wrong output got: %t %d expected: false 2", present, value)
	}
	present, value = ht.Get(2)
	if present == true {
		t.Errorf("wrong output got: %t expected: false", present)
	}
}
