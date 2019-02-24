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

// nodeColor returns the color of node
func nodeColor(node *Node) int {
	if node == nil {
		return BLACK
	}
	return node.Color
}

// uncle returns the uncle of node
func (node *Node) uncle() *Node {
	if node == nil || node.Parent == nil || node.Parent.Parent == nil {
		return nil
	}
	return node.Parent.sibling()
}

// sibling returns the sibling of node
func (node *Node) sibling() *Node {
	if node == nil || node.Parent == nil {
		return nil
	}
	if node == node.Parent.Left {
		return node.Parent.Right
	}
	return node.Parent.Left
}

// grandparent returns the grandparent of node
func (node *Node) grandparent() *Node {
	if node == nil || node.Parent == nil {
		return nil
	}
	return node.Parent.Parent
}
