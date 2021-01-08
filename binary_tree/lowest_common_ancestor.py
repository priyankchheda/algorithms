""" Lowest Common Ancestor in Binary Tree
"""


class Node:
    """ Node contains actual data and address to left and right node """
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None


def lowest_common_ancestor(root, a, b):
    """ lowest common ancestor in BST """
    if root is None:
        return None

    if root.data == a or root.data == b:
        return root

    left = lowest_common_ancestor(root.left, a, b)
    right = lowest_common_ancestor(root.right, a, b)

    if left is not None and right is not None:
        return root

    if left is None and right is None:
        return None

    if left is not None:
        return left
    else:
        return right


def main():
    """ operational function """
    root = Node(2)
    root.left = Node(7)
    root.left.left = Node(21)
    root.left.right = Node(6)
    root.left.right.left = Node(5)
    root.left.right.right = Node(11)
    root.right = Node(5)
    root.right.right = Node(9)
    root.right.right.left = Node(4)
    root.right.right.left.right = Node(40)
    root.right.right.left.right.right = Node(46)

    lca_node = lowest_common_ancestor(root, 21, 11)
    print("lowest_common_ancestor for 21 and 11:", lca_node.data)


if __name__ == "__main__":
    main()
