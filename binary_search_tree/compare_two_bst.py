""" Check whether thw two binary search tree are identical or not
"""

class Node:
    """ Node contains actual data and address to left and right node """
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None


def is_identical(root1, root2):
    """ checks if two bst are identical """
    if root1 is None and root2 is None:
        return True

    if root1 is not None and root2 is None:
        return False

    if root1 is None and root2 is not None:
        return False

    if (root1.data == root2.data and
        is_identical(root1.left, root2.left) and
        is_identical(root1.right, root2.right)):
        return True
    return False


def main():
    """ operational function """
    root1 = Node(5)
    root1.left = Node(3)
    root1.right = Node(8)
    root1.left.left = Node(2)
    root1.left.right = Node(4)

    root2 = Node(5)
    root2.left = Node(3)
    root2.right = Node(8)
    root2.left.left = Node(2)

    print(is_identical(root1, root2))

    root2.left.right = Node(4)
    print(is_identical(root1, root2))


if __name__ == "__main__":
    main()
