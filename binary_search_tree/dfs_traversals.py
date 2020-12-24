""" Binary Search Tree Traversals

    DFS (Depth-first search) is technique used for traversing tree or graph.

    Here backtracking is used for traversal. In this traversal first the
    deepest node is visited and then backtracks to it’s parent node if no
    sibling of that node exist.
"""

class Node:
    """ Node contains actual data and address to left and right node """
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None


class BinarySearchTree:
    """ Binary Search Tree Implementation """
    def __init__(self):
        self.root = None

    def insert(self, data):
        """ inserts new integer data into the tree at the position, so that
            the binary search tree property is maintained.
        """
        def _insert(root, data):
            """ recursive internal method which works on node level """
            if root is None:
                root = Node(data)
            elif data <= root.data:
                root.left = _insert(root.left, data)
            else:
                root.right = _insert(root.right, data)
            return root

        if self.root is None:
            self.root = Node(data)
        else:
            self.root = _insert(self.root, data)


def preorder_traversal(node):
    """  Pre Order Tree Traversal
        * Visit the root node
        * Visit all the nodes in the left subtree
        * Visit all the nodes in the right subtree
    """
    if node is None:
        return

    print(node.data, end=" ")
    preorder_traversal(node.left)
    preorder_traversal(node.right)


def inorder_traversal(node):
    """ In Order Tree Traversal
        * Visit all the nodes in the left subtree
        * Visit the root node
        * Visit all the nodes in the right subtree
    """
    if node is None:
        return

    inorder_traversal(node.left)
    print(node.data, end=" ")
    inorder_traversal(node.right)


def postorder_traversal(node):
    """ Post Order Tree Traversal
        * Visit all the nodes in the left subtree
        * Visit all the nodes in the right subtree
        * Visit the root node
    """
    if node is None:
        return

    postorder_traversal(node.left)
    postorder_traversal(node.right)
    print(node.data, end=" ")


def main():
    """ operational function """
    bst = BinarySearchTree()
    for elem in [9, 5, 3, 10, 6, 1, 7, 4]:
        bst.insert(elem)

    preorder_traversal(bst.root)
    print()
    inorder_traversal(bst.root)
    print()
    postorder_traversal(bst.root)
    print()


if __name__ == "__main__":
    main()
