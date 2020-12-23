""" Binary Search Tree Traversals

    DFS (Depth-first search) is technique used for traversing tree or graph.

    Here backtracking is used for traversal. In this traversal first the
    deepest node is visited and then backtracks to it’s parent node if no
    sibling of that node exist.
"""

from collections import deque


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


    def level_order_traversal(self):
        """ Breadth First Traversal (Level Order Traversal) """
        if self.root is None:
            return

        queue = deque()
        queue.append(self.root)

        while queue:
            node = queue[0]
            print(node.data, end=" ")
            if node.left is not None:
                queue.append(node.left)
            if node.right is not None:
                queue.append(node.right)
            queue.popleft()


def main():
    """ operational function """
    bst = BinarySearchTree()
    for elem in [9, 5, 3, 10, 6, 1, 7, 4]:
        bst.insert(elem)

    bst.level_order_traversal()
    print()


if __name__ == "__main__":
    main()
