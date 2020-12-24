""" check whether the given binary tree is Binary Search Tree or not
"""

import sys

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


def is_bst(root):
    """ checks if binary tree is binary search tree """
    def is_bst_util(root, min_value, max_value):
        """ binary search tree check utility function """
        if root is None:
            return True

        if (root.data >= min_value and root.data < max_value
                and is_bst_util(root.left, min_value, root.data)
                and is_bst_util(root.right, root.data, max_value)):
            return True
        return False

    return is_bst_util(root, -sys.maxsize - 1, sys.maxsize)


def main():
    """ operational function """
    bst1 = BinarySearchTree()
    for elem in [9, 5, 3, 10, 6, 1, 7, 4]:
        bst1.insert(elem)
    print("is BST?", is_bst(bst1.root))

    bst2 = BinarySearchTree()
    bst2.root = Node(5)
    bst2.root.right = Node(7)
    bst2.root.left = Node(5)
    bst2.root.left.left = Node(1)
    bst2.root.left.right = Node(4)
    bst2.root.right.right = Node(6)
    print("is BST?", is_bst(bst2.root))


if __name__ == "__main__":
    main()
