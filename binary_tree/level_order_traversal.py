""" Level Order Traversal On Binary Tree
"""

from collections import deque


class Node:
    """ class representing node in binary tree """
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None


def level_order(root):
    """ level order traversal of binary tree using queue """
    if root is None:
        return

    queue = deque([root])

    while queue:
        node = queue.popleft()
        print(node.data, end=" ")
        if node.left is not None:
            queue.append(node.left)
        if node.right is not None:
            queue.append(node.right)


def main():
    """ operational function """

    root = Node(1)
    root.left = Node(2)
    root.right = Node(3)
    root.left.left = Node(4)
    root.left.right = Node(5)

    level_order(root)


if __name__ == "__main__":
    main()
