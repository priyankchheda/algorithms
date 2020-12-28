""" Depth First Traversals of Binary Tree
    - Inorder Traversals (left, root, right)
    - Preorder Traversals (root, left, right)
    - Postorder Traversals (left, righti, root)
"""

class Node:
    """ class representing node in binary tree """
    def __init__(self, data):
        self.data = data
        self.left = None
        self.right = None


def inorder(root):
    """ inorder traversal (left, root, right) """
    if root is not None:
        inorder(root.left)
        print(root.data, end=" ")
        inorder(root.right)


def preorder(root):
    """ preorder traversal (root, left, right) """
    if root is not None:
        print(root.data, end=" ")
        preorder(root.left)
        preorder(root.right)


def postorder(root):
    """ postorder traversal (left, right, root) """
    if root is not None:
        postorder(root.left)
        postorder(root.right)
        print(root.data, end=" ")


def main():
    """ operational function """
    root = Node(1)
    root.left = Node(2)
    root.right = Node(3)
    root.left.left = Node(4)
    root.left.right = Node(5)

    print("Inorder Traversals: ", end="")
    inorder(root)
    print()

    print("Preorder Traversals: ", end="")
    preorder(root)
    print()

    print("Postorder Traversals: ", end="")
    postorder(root)
    print()


if __name__ == "__main__":
    main()
