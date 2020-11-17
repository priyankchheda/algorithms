""" Trie is an efficient information reTrieval data structure. Using Trie,
    search complexities can be brought to optimal limit (key length). If we
    store keys in binary search tree, a well balanced BST will need time
    proportional to M * log N, where M is maximum string length and N is
    number of keys in tree. Using Trie, we can search the key in O(M) time.
    However the penalty is on Trie storage requirements
"""

class Node:
    """ Node contains character and it's children trie node """
    def __init__(self):
        self.children = [None] * 26
        self.word_finished = False


class Trie:
    """ Trie Data Structure implementation """
    def __init__(self):
        self.root = Node()

    def char_to_index(self, char):
        """ converts key character into index
            use only 'a' through 'z' lower case
        """
        return ord(char) - ord('a')

    def insert(self, word):
        """ inserts a word in the trie data structure"""
        current = self.root
        for character in word:
            index = self.char_to_index(character)
            if not current.children[index]:
                current.children[index] = Node()
            current = current.children[index]
        current.word_finished = True

    def search(self, word):
        """ returns true if the complete word is present in trie,
            else false
        """
        current = self.root
        for character in word:
            index = self.char_to_index(character)
            if not current.children[index]:
                return False
            current = current.children[index]
        return current is not None and current.word_finished

    def starts_with(self, prefix):
        """ returns true if any word present in the trie start with the
            given prefix, else false
        """
        current = self.root
        for character in prefix:
            index = self.char_to_index(character)
            if not current.children[index]:
                return False
            current = current.children[index]
        return True

    def delete(self, word):
        """ deletes word by negating word_finished boolean variable """
        current = self.root
        for character in word:
            index = self.char_to_index(character)
            if not current.children[index]:
                raise Exception("word not present in trie")
            current = current.children[index]

        if current.word_finished:
            current.word_finished = False


def main():
    """ operational function """
    tree = Trie()
    tree.insert("apple")
    print("is apple present?", tree.search("apple")) # True
    print("is app present?", tree.search("app")) # False
    print("starts with app?", tree.starts_with("app")) # True

    print("inserting 'app' in trie")
    tree.insert("app")
    print("is app present?", tree.search("app")) # True

    print("removing 'app' from trie")
    tree.delete("app")
    print("is app present?", tree.search("app")) # False


if __name__ == "__main__":
    main()

