""" Top View of Binary Tree
"""

from collections import deque


class Node:
    """ class representing node in binary tree """
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None

def top_view(root):
    """ top view of binary tree """
    if root is None:
        return

    level_map = {}

    # queue of root and it's corresponding horizontal distance
    queue = deque([(root, 0)])

    while queue:
        node, hd = queue.popleft()
        if hd not in level_map:
            print(node.data, end=" ")
            level_map[hd] = node.data

        if node.left is not None:
            queue.append((node.left, hd-1))

        if node.right is not None:
            queue.append((node.right, hd+1))


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
    root.right.right.left.right = Node(40)
    root.right.right.left.right.right = Node(46)

    top_view(root)


if __name__ == "__main__":
    main()


