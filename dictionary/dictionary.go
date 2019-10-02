// Package dictionary is word dictionary implementation using trie in go
package dictionary

// trieNode saves trie structure
type trieNode struct {
	childMap map[rune]*trieNode
	isEnd    bool
}

// Dictionary struct contains data and methods
type Dictionary struct {
	root      *trieNode
	wordCount int
}

// NewDictionary creates new instance of dictionary
func NewDictionary() *Dictionary {
	return &Dictionary{
		root: &trieNode{
			childMap: map[rune]*trieNode{},
			isEnd:    false,
		},
		wordCount: 0,
	}
}

// Size returns word count in dictionary
func (pr *Dictionary) Size() int {
	return pr.wordCount
}

// Insert inserts new word in dictionary
// returns false if this word already present
func (pr *Dictionary) Insert(word string) bool {
	node := pr.root
	for _, ch := range word {
		if newNode, ok := node.childMap[ch]; ok {
			node = newNode
		} else {
			node.childMap[ch] = &trieNode{
				childMap: map[rune]*trieNode{},
				isEnd:    false,
			}
			node = node.childMap[ch]
		}
	}
	if node.isEnd {
		return false
	}
	node.isEnd = true
	pr.wordCount++
	return true
}

// InsertAll inserts all words in dictionary
// returns number of words actually inserted
func (pr *Dictionary) InsertAll(words []string) int {
	var res = 0
	for _, word := range words {
		if pr.Insert(word) {
			res++
		}
	}
	return res
}

// Retrieve retrieves all words in dictionary starting with prefix
func (pr *Dictionary) Retrieve(prefix string) []string {
	node, depth := longestMatch(prefix, pr.root)
	if depth != len(prefix) {
		return []string{}
	}
	return allChild(prefix, node)
}

// Contains checks if given word is in dictionary
func (pr *Dictionary) Contains(word string) bool {
	node, depth := longestMatch(word, pr.root)
	return depth == len(word) && node.isEnd
}

// Delete deletes given word from dictionary
// returns false if word is'n in dictionary
func (pr *Dictionary) Delete(word string) bool {
	node, depth := longestMatch(word, pr.root)
	if depth == len(word) && node.isEnd {
		node.isEnd = false
		return true
	}
	return false
}

func longestMatch(prefix string, root *trieNode) (*trieNode, int) {
	node := root
	var depth = 0
	for _, ch := range prefix {
		if newNode, ok := node.childMap[ch]; ok {
			node = newNode
			depth++
		} else {
			return node, depth
		}
	}
	return node, depth
}

func allChild(prefix string, node *trieNode) []string {
	var res []string
	if node.isEnd {
		res = append(res, prefix)
	}

	for ch, childNode := range node.childMap {
		newStr := prefix + string(ch)
		res = append(res, allChild(newStr, childNode)...)
	}
	return res
}
