"""
Red Black Tree is an implementation for left leaning red black tree
data structure in go language.

Red-Black Tree is a self-balancing Binary Search Tree (BST) where every node
has a color either red or black. Root of tree is always black. There are no
two adjacent red nodes (A red node cannot have a red parent or red child).
Every path from a node (including root) to any of its descendant NULL node has
the same number of black nodes.

Why Red-Black Trees

Most of the BST operations (e.g., search, max, min, insert, delete.. etc)
take O(h) time where h is the height of the BST. The cost of these
operations may become O(n) for a skewed Binary tree. If we make sure that
height of the tree remains O(Logn) after every insertion and deletion, then
we can guarantee an upper bound of O(Logn) for all these operations. The
height of a Red-Black tree is always O(Logn) where n is the number of nodes
in the tree.

The main problem with BST deletion (Hibbard Deletion) is that It is not
symmetric. After many insertion and deletion BST become less balance.
Researchers proved that after sufficiently long number of random insert
and delete height of the tree becomes sqrt(n) .So now every operation
(search, insert, delete) will take sqrt(n) time which is not good compare
to O(logn) .

This is very long standing(around 50 years) open problem to efficient
symmetric delete for BST. for guaranteed balanced tree, we have to use
RedBlack Tree etc.

Properties
 - No Node has two red links connected to it.
 - Every path from root to null link has the same number of black links.
 - Red links lean left.
"""

RED = 0
BLACK = 1

class Node: # pylint: disable=too-few-public-methods
    """ Red Black Node contains actual data and color bit along with
        links to left, right, parent node
    """
    def __init__(self, data, color):
        self.data = data
        self.color = color
        self.left = None
        self.right = None
        self.parent = None

    def __repr__(self):
        return f"Node (data:{self.data} color: {self.color})"

class RedBlackTree:
    """ Red Black Tree Implementation """
    def __init__(self):
        self.root = None
        self.size = 0

    def insert(self, data): # pylint: disable=too-many-statements
        """ inserts new integer data into the tree at the position, so that
            the red black tree property is maintained.
        """
        def insert_case1(node):
            if node.parent is None:
                node.color = BLACK
            else:
                insert_case2(node)

        def insert_case2(node):
            if self.get_node_color(node.parent) == BLACK:
                return
            insert_case3(node)

        def insert_case3(node):
            uncle_node = self.uncle(node)
            if self.get_node_color(uncle_node) == RED:
                node.parent.color = BLACK
                uncle_node.color = BLACK
                grandparent_node = self.grandparent(node)
                grandparent_node.color = RED
                insert_case1(grandparent_node)
            else:
                insert_case4(node)

        def insert_case4(node):
            grandparent_node = self.grandparent(node)
            if (node is node.parent.right and
                    node.parent is grandparent_node.left):
                self.left_rotate(node.parent)
                node = node.left
            elif (node is node.parent.left and
                  node.parent is grandparent_node.right):
                self.right_rotate(node.parent)
                node = node.right
            insert_case5(node)

        def insert_case5(node):
            node.parent.color = BLACK
            grandparent_node = self.grandparent(node)
            grandparent_node.color = RED
            if (node is node.parent.left and
                    node.parent is grandparent_node.left):
                self.right_rotate(grandparent_node)
            elif (node is node.parent.right and
                  node.parent is grandparent_node.right):
                self.left_rotate(grandparent_node)

        inserted_node = None
        if self.root is None:
            self.root = Node(data, RED)
            inserted_node = self.root
        else:
            node = self.root
            while True:
                if data < node.data:
                    if node.left is None:
                        node.left = Node(data, RED)
                        inserted_node = node.left
                        break
                    node = node.left
                elif data > node.data:
                    if node.right is None:
                        node.right = Node(data, RED)
                        inserted_node = node.right
                        break
                    node = node.right
                else:
                    node.data = data
                    return
            inserted_node.parent = node
        insert_case1(inserted_node)
        self.size += 1

    def search(self, data):
        """ finds the integer in red black tree
        """
        def _search(root, data):
            """ recursive internal method which works at node level """
            if root is None:
                return False

            # pylint: disable=no-else-return
            if data == root.data:
                return True
            elif data < root.data:
                return _search(root.left, data)
            else:
                return _search(root.right, data)

        if self.root is None:
            return False
        return _search(self.root, data)

    def min(self):
        """ returns left-most item present in red black tree which is also
            the minimum element in rb-tree
        """
        if self.root is None:
            raise Exception("tree is empty")

        current = self.root
        while current.left is not None:
            current = current.left
        return current.data

    def max(self):
        """ returns right-most item present in red black tree which is also
            the maximum element in rb-tree
        """
        if self.root is None:
            raise Exception("tree is empty")

        current = self.root
        while current.right is not None:
            current = current.right
        return current.data

    @staticmethod
    def get_node_color(node):
        """ returns node color """
        if node is None:
            return BLACK
        return node.color

    @staticmethod
    def uncle(node):
        """ returns uncle of node """
        if node is None or node.parent is None or node.parent.parent is None:
            return None
        return RedBlackTree.sibling(node.parent)

    @staticmethod
    def sibling(node):
        """ returns sibling of given node """
        if node is None or node.parent is None:
            return None

        if node is node.parent.left:
            return node.parent.right
        return node.parent.left

    @staticmethod
    def grandparent(node):
        """ returns grandparent of node """
        if node is None or node.parent is None:
            return None
        return node.parent.parent

    def left_rotate(self, node):
        """ performs left rotation on given node """
        right = node.right
        self.replace_node(node, right)
        node.right = right.left
        if right.left is not None:
            right.left.parent = node
        right.left = node
        node.parent = right

    def right_rotate(self, node):
        """ performs right rotation on given node """
        left = node.left
        self.replace_node(node, left)
        node.left = left.right
        if left.right is not None:
            left.right.parent = node
        left.right = node
        node.parent = left

    def replace_node(self, old_node, new_node):
        """ replace old node with new node """
        if old_node.parent is None:
            self.root = new_node
        else:
            if old_node is old_node.parent.left:
                old_node.parent.left = new_node
            else:
                old_node.parent.right = new_node

        if new_node is not None:
            new_node.parent = old_node.parent


def main():
    """ operational function """
    rb_tree = RedBlackTree()
    rb_tree.insert(1)
    rb_tree.insert(2)
    rb_tree.insert(3)
    rb_tree.insert(4)
    rb_tree.insert(5)

    print("min value:", rb_tree.min())
    print("max value:", rb_tree.max())

    print("is 1 present?", rb_tree.search(1))
    print("is 11 present?", rb_tree.search(11))
    print("is 5 present?", rb_tree.search(5))


if __name__ == "__main__":
    main()
