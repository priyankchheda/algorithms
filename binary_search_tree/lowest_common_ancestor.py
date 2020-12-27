""" Lowest Common Ancestor in Binary Search Tree
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

        self.root = _insert(self.root, data)


def lowest_common_ancestor(root, a, b):
    """ lowest common ancestor in BST """
    if root.data > max(a, b):
        return lowest_common_ancestor(root.left, a, b)
    if root.data < min(a, b):
        return lowest_common_ancestor(root.right, a, b)
    return root


def main():
    """ operational function """
    bst = BinarySearchTree()
    for elem in [9, 5, 3, 10, 6, 1, 7, 4]:
        bst.insert(elem)

    lca_node = lowest_common_ancestor(bst.root, 5, 4)
    print("lowest_common_ancestor for 5 and 4:", lca_node.data)


if __name__ == "__main__":
    main()
