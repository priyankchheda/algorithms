package dictionary_test

import (
	"algorithms-1/dictionary"
	"testing"
)

func TestEmptyDictionary(t *testing.T) {
	var dict = dictionary.NewDictionary()
	if dict.Size() != 0 {
		t.Errorf("dictionary should be empty")
	}

}
func TestInsertingSame(t *testing.T) {
	var dict = dictionary.NewDictionary()

	if dict.Insert("abc") == false {
		t.Errorf("dictionary should be empty")
	}
	if dict.Insert("abc") == true {
		t.Errorf("abc should already be in dictionary")
	}

}

func TestRetrieve(t *testing.T) {
	var dict = dictionary.NewDictionary()

	if dict.Insert("abc") == false {
		t.Errorf("dictionary should be empty")
	}
	if dict.Insert("abb") == false {
		t.Errorf("abb should't be in directory")
	}
	if dict.Insert("abcc") == false {
		t.Errorf("abcc should't be in directory")
	}

	if len(dict.Retrieve("a")) != 3 {
		t.Errorf("there sould be 3 words starting with a")
	}
	if len(dict.Retrieve("ab")) != 3 {
		t.Errorf("there sould be 3 words starting with ab")
	}
	if len(dict.Retrieve("abb")) != 1 {
		t.Errorf("there sould be 1 words starting with abb")
	}
	if len(dict.Retrieve("gg")) != 0 {
		t.Errorf("there sould be 0 words starting with gg")
	}

}

func TestContains(t *testing.T) {
	var dict = dictionary.NewDictionary()
	if dict.Insert("abc") == false {
		t.Errorf("dictionary should be empty")
	}
	if dict.Contains("abc") == false {
		t.Errorf("abc should be in dictionary")
	}

	var words = []string{
		"aaa",
		"b",
		"bbc",
		"ccccdddd",
		"d",
		"ddaaaa",
		"dddddddeeeeeeaaaa",
		"eabbbb",
		"eaccbbbbb",
	}

	var containsTests = []struct {
		word     string // input
		expected bool   // expected result
	}{
		{"aaa", true},
		{"ccccdddd", true},
		{"sdfdsf", false},
		{"eaccbbbba", false},
		{"", false},
		{"eabbbb", true},
		{"bb", false},
	}
	dict.InsertAll(words)

	for _, tt := range containsTests {
		actual := dict.Contains(tt.word)
		if actual != tt.expected {
			t.Errorf("contains(%s): expected %t, actual %t", tt.word, tt.expected, actual)
		}
	}

}
func TestDelete(t *testing.T) {
	var dict = dictionary.NewDictionary()
	if dict.Insert("abc") == false {
		t.Errorf("dictionary should be empty")
	}
	if dict.Delete("abc") == false {
		t.Errorf("abc should be in dictionary")
	}

	var words = []string{
		"aaa",
		"b",
		"bbc",
		"ccccdddd",
		"d",
		"ddaaaa",
		"dddddddeeeeeeaaaa",
		"eabbbb",
		"eaccbbbbb",
	}

	var containsTests = []struct {
		word     string // input
		expected bool   // expected result
	}{
		{"aaa", true},
		{"aaa", false},
		{"sdfdsf", false},
		{"eaccbbbba", false},
		{"", false},
		{"eabbbb", true},
		{"eabbbb", false},
		{"bb", false},
	}
	dict.InsertAll(words)

	for _, tt := range containsTests {
		actual := dict.Delete(tt.word)
		if actual != tt.expected {
			t.Errorf("delete(%s): expected %t, actual %t", tt.word, tt.expected, actual)
		}
	}

}
