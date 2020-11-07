package redblacktree

// Insert inserts new node into the red black tree
func (tree *RBTree) Insert(data int) {
	var insertedNode *Node
	if tree.Root == nil {
		tree.Root = NewNode(data, RED)
		insertedNode = tree.Root
	} else {
		node := tree.Root
		for true {
			if data < node.Data {
				if node.Left == nil {
					node.Left = NewNode(data, RED)
					insertedNode = node.Left
					break
				} else {
					node = node.Left
				}
			} else if data > node.Data {
				if node.Right == nil {
					node.Right = NewNode(data, RED)
					insertedNode = node.Right
					break
				} else {
					node = node.Right
				}
			} else {
				node.Data = data
				return
			}
		}
		insertedNode.Parent = node
	}
	tree.insertCase1(insertedNode)
	tree.Size++
}

func (tree *RBTree) insertCase1(node *Node) {
	if node.Parent == nil {
		node.Color = BLACK
	} else {
		tree.insertCase2(node)
	}
}

func (tree *RBTree) insertCase2(node *Node) {
	if nodeColor(node.Parent) == BLACK {
		return
	}
	tree.insertCase3(node)
}

func (tree *RBTree) insertCase3(node *Node) {
	uncle := node.uncle()
	if nodeColor(uncle) == RED {
		node.Parent.Color = BLACK
		uncle.Color = BLACK
		node.grandparent().Color = RED
		tree.insertCase1(node.grandparent())
	} else {
		tree.insertCase4(node)
	}
}

func (tree *RBTree) insertCase4(node *Node) {
	grandparent := node.grandparent()
	if node == node.Parent.Right && node.Parent == grandparent.Left {
		tree.leftRotate(node.Parent)
		node = node.Left
	} else if node == node.Parent.Left && node.Parent == grandparent.Right {
		tree.rightRotate(node.Parent)
		node = node.Right
	}
	tree.insertCase5(node)
}

func (tree *RBTree) insertCase5(node *Node) {
	node.Parent.Color = BLACK
	grandparent := node.grandparent()
	grandparent.Color = RED
	if node == node.Parent.Left && node.Parent == grandparent.Left {
		tree.rightRotate(grandparent)
	} else if node == node.Parent.Right && node.Parent == grandparent.Right {
		tree.leftRotate(grandparent)
	}
}
