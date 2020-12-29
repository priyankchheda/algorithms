""" Vertical Order Traversal On Binary Tree
"""

from collections import defaultdict


class Node:
    """ class representing node in binary tree """
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None


def preorder(root, horizontal_dist, hd_map):
    if root is None:
        return

    hd_map[horizontal_dist].append(root.data)
    preorder(root.left, horizontal_dist-1, hd_map)
    preorder(root.right, horizontal_dist+1, hd_map)


def vertical_order(root):
    """ vertical order traversal of binary tree  """
    hd_map = defaultdict(list)
    horizontal_dist = 0
    preorder(root, horizontal_dist, hd_map)
    for key, value in hd_map.items():
        print(f"{key}: {value}")


def main():
    """ operational function """

    root = Node(2)
    root.left = Node(7)
    root.left.left = Node(2)
    root.left.right = Node(6)
    root.left.right.left = Node(5)
    root.left.right.right = Node(11)
    root.right = Node(5)
    root.right.right = Node(9)
    root.right.right.left = Node(4)

    vertical_order(root)


if __name__ == "__main__":
    main()

