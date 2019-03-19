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
	tests := []struct {
		key   int
		value int
	}{
		{1, 2}, {2, 3}, {1, 3}, {3, 6}, {4, 5}, {12, 3}, {18, 5},
	}
	ht := hashtable.CreateHashTable()
	for _, test := range tests {
		ht.Put(test.key, test.value)
	}
	present, value := ht.Get(1)
	if present == false || value != 3 {
		t.Errorf("wrong output got: %t %d expected: false 3", present, value)
	}
	ht.Put(4, 6)
	present, value = ht.Get(4)
	if present == false || value != 6 {
		t.Errorf("wrong output got: %t %d expected: false 6", present, value)
	}
}

func TestGet(t *testing.T) {
	tests := []struct {
		key   int
		value int
	}{
		{1, 2}, {2, 3}, {1, 3}, {3, 6}, {4, 5}, {12, 3}, {18, 5},
	}
	ht := hashtable.CreateHashTable()
	for _, test := range tests {
		ht.Put(test.key, test.value)
	}

	dataSet := []struct {
		key   int
		value int
	}{
		{1, 3}, {2, 3}, {3, 6}, {4, 5}, {12, 3}, {18, 5},
	}
	for _, data := range dataSet {
		present, value := ht.Get(data.key)
		if present == false || value != data.value {
			t.Errorf("wrong output got: %t %d expected: true %d",
				present, value, data.value)
		}
	}

	present, value := ht.Get(5)
	if present == true {
		t.Errorf("wrong output got: true %d expected: false 0", value)
	}
}

func TestDel(t *testing.T) {
	tests := []struct {
		key   int
		value int
	}{
		{1, 2}, {2, 3}, {1, 3}, {12, 3}, {18, 5}, {15, 3},
		{9, 4}, {7, 5}, {24, 4}, {3, 6}, {4, 5}, {34, 4},
	}
	ht := hashtable.CreateHashTable()
	for _, test := range tests {
		ht.Put(test.key, test.value)
	}

	dataSet := []struct {
		key            int
		expectedResult bool
	}{
		{18, true}, {50, false}, {2, true}, {1, true}, {1, false}, {17, false},
		{24, true}, {12, true}, {15, true}, {3, true}, {4, true}, {9, true},
		{7, true}, {34, true},
	}

	for _, data := range dataSet {
		result := ht.Del(data.key)
		if result != data.expectedResult {
			t.Errorf("wrong output got: %t expected: %t",
				result, data.expectedResult)
		}
	}
}
