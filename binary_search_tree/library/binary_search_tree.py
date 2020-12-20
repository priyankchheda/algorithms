"""
Binary Search Tree (Python Implementation)

Binary Search Tree is a node-based binary tree data structure
which has the following properties:
- The left subtree of a node contains only nodes with keys lesser
  than the node’s key.
- The right subtree of a node contains only nodes with keys greater
  than the node’s key.
- The left and right subtree each must also be a binary search tree.
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

    def search(self, data):
        """ finds the integer in binary search tree
        """
        def _search(root, data):
            """ recursive internal method which works at node level """
            if root is None:
                return False

            if data == root.data:
                return True
            elif data < root.data:
                return _search(root.left, data)
            else:
                return _search(root.right, data)

        if self.root is None:
            return False
        return _search(self.root, data)

    def delete(self, data):
        """ delete value from binary search tree """
        def find_min_node(node):
            """ find the node with minimum value of give (sub)tree """
            while node.left is not None:
                node = node.left
            return node

        def _delete(root, data):
            """ interal recursive method that works at node-level """
            if root is None:
                return root

            if data < root.data:
                root.left = _delete(root.left, data)
            elif data > root.data:
                root.right = _delete(root.right, data)
            else:
                if root.left is None and root.right is None:
                    del root
                    root = None
                elif root.left is None:
                    temp = root
                    root = root.right
                    del temp
                elif root.right is None:
                    temp = root
                    root = root.left
                    del temp
                else:
                    temp = find_min_node(root.right)
                    root.data = temp.data
                    root.right = _delete(root.right, temp.data)
            return root

        self.root = _delete(self.root, data)

    def min(self):
        """ returns left-most item present in binary search tree which is also
            the minimum element in bst
        """
        if self.root is None:
            raise Exception("tree is empty")

        current = self.root
        while current.left is not None:
            current = current.left
        return current.data

    def max(self):
        """ returns right-most item present in binary search tree which is also
            the maximum element in bst
        """
        if self.root is None:
            raise Exception("tree is empty")

        current = self.root
        while current.right is not None:
            current = current.right
        return current.data

    def height(self):
        """ calculate height of binary search tree
        """
        def _height(root):
            """ recursive internal method that works at node-level """
            if root is None:
                return -1

            left_height = _height(root.left)
            right_height = _height(root.right)
            if left_height > right_height:
                return left_height + 1
            return right_height + 1

        if self.root is None:
            return -1
        return _height(self.root)


def main():
    """ operational function """
    bst = BinarySearchTree()
    bst.insert(4)
    bst.insert(2)
    bst.insert(8)
    bst.insert(5)
    bst.insert(10)

    print("is 4 present in bst?", bst.search(4))
    print("is 5 present in bst?", bst.search(5))
    print("is 11 present in bst?", bst.search(11))

    print("min value:", bst.min())
    print("max value:", bst.max())
    print("height of bst:", bst.height())

    bst.delete(10)
    bst.delete(8)
    bst.delete(2)


    print("is 8 present in bst?", bst.search(8))
    print("is 10 present in bst?", bst.search(10))

    print("min value:", bst.min())
    print("max value:", bst.max())


if __name__ == "__main__":
    main()
