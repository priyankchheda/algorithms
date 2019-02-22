package redblacktree

const (
	RED   = 0
	BLACK = 1
)

// Node struct contains actual data, color and address to left, right and
// parent node
type Node struct {
	Data   int
	Color  int
	Parent *Node
	Left   *Node
	Right  *Node
}

// Tree struct contains the pointer to root node and total number of nodes.
type RBTree struct {
	Root *Node
	Size int
}

// NewRBTree creates an empty Red Black Tree
func NewRBTree() *RBTree {
	return &RBTree{nil, 0}
}

// NewNode creates a new Node with default integer data
func NewNode(data, color int) *Node {
	return &Node{data, color, nil, nil, nil}
}
