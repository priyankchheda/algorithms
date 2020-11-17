"""
A ternary search tree is a special trie data structure where the child nodes
of a standard trie are ordered as a binary search tree.

Representation of ternary search trees:

Unlike trie(standard) data structure where each node contains 26 pointers for
its children, each node in a ternary search tree contains only 3 pointers:
    1. The left pointer points to the node whose value is less than the
       value in the current node.
    2. The equal pointer points to the node whose value is equal to the
       value in the current node.
    3. The right pointer points to the node whose value is greater than the
       value in the current node.
"""

class Node: # pylint: disable=too-few-public-methods
    """ Node contains actual data and left, middle and right node """
    def __init__(self, character):
        self.character = character
        self.value = None
        self.left = None
        self.middle = None
        self.right = None


class TernarySearchTries:
    """ Ternary Search Tries Implemenation"""
    def __init__(self):
        self.root = None

    def put(self, key, value):
        """ inserts new key-value pair into the ternary search tries """
        def _put(node, key, value, depth):
            """ recursive internal method which works on node level """
            char = key[depth]
            if node is None:
                node = Node(char)

            if char < node.character:
                node.left = _put(node.left, key, value, depth)
            elif char > node.character:
                node.right = _put(node.right, key, value, depth)
            elif depth < len(key) - 1:
                node.middle = _put(node.middle, key, value, depth + 1)
            else:
                node.value = value
            return node

        self.root = _put(self.root, key, value, 0)

    def get(self, key):
        """ returns value of the key if the key is present, else -1 """
        def _get(node, key, depth):
            """ recursive internal method which works on node level """
            if node is None:
                return None

            char = key[depth]

            if char < node.character:
                return _get(node.left, key, depth)
            if char > node.character:
                return _get(node.right, key, depth)
            if depth < len(key) - 1:
                return _get(node.middle, key, depth + 1)
            return node

        node = _get(self.root, key, 0)

        if node is None:
            return -1
        return node.value


def main():
    """ operational function """
    tst = TernarySearchTries()
    tst.put("apple", 100)
    tst.put("orange", 200)

    print(tst.get("apple")) # 100
    print(tst.get("adam")) # -1

    tst.put("adam", 50)
    print(tst.get("adam")) # 50


if __name__ == "__main__":
    main()
