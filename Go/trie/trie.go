// Package trie is word dictionary implementation using trie in go
package trie

// trieNode saves trie structure
type trieNode struct {
	childMap map[rune]*trieNode
	isEnd    bool
}

// Trie struct contains data and methods
type Trie struct {
	root      *trieNode
	wordCount int
}

// NewTrie creates new instance of trie
func NewTrie() *Trie {
	return &Trie{
		root: &trieNode{
			childMap: map[rune]*trieNode{},
			isEnd:    false,
		},
		wordCount: 0,
	}
}

// Size returns word count in trie
func (pr *Trie) Size() int {
	return pr.wordCount
}

// Insert inserts new word in trie
// returns false if this word already present
func (pr *Trie) Insert(word string) bool {
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

// InsertAll inserts all words in trie returns number of words actually
// inserted.
func (pr *Trie) InsertAll(words []string) int {
	var res = 0
	for _, word := range words {
		if pr.Insert(word) {
			res++
		}
	}
	return res
}

// Retrieve retrieves all words in trie starting with prefix.
func (pr *Trie) Retrieve(prefix string) []string {
	node, depth := longestMatch(prefix, pr.root)
	if depth != len(prefix) {
		return []string{}
	}
	return allChild(prefix, node)
}

// Contains checks if given word is in trie.
func (pr *Trie) Contains(word string) bool {
	node, depth := longestMatch(word, pr.root)
	return depth == len(word) && node.isEnd
}

// Delete deletes given word from trie. Returns false if word is not in trie.
func (pr *Trie) Delete(word string) bool {
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
