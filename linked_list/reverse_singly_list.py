""" Reverse singly linked lists
    input: 1 -> 5 -> 7 -> 9 -> 10
    output: 10 -> 9 -> 7 -> 5 -> 1
"""

class Node:
    """ Node class contains everything related to Linked List node """
    def __init__(self, data):
        """ initializing single node with data """
        self.data = data
        self.next = None


class LinkedList:
    """ Singly Linked List is a linear data structure """
    def __init__(self):
        """ initializing singly linked list with zero node """
        self.head = None

    def insert_head(self, data):
        """ inserts node at the start of linked list """
        node = Node(data)
        node.next = self.head
        self.head = node

    def print(self):
        """ prints entire linked list without changing underlying data """
        current = self.head
        while current is not None:
            print(" ->", current.data, end="")
            current = current.next
        print()

    def reverse(self):
        """ reverse linked list """
        previous = None
        following = None
        current = self.head

        while current is not None:
            following = current.next
            current.next = previous
            previous = current
            current = following

        self.head = previous


def main():
    """ operational function """
    linkedlist = LinkedList()
    linkedlist.insert_head(10)
    linkedlist.insert_head(9)
    linkedlist.insert_head(7)
    linkedlist.insert_head(5)
    linkedlist.insert_head(1)

    linkedlist.print()
    linkedlist.reverse()
    linkedlist.print()


if __name__ == '__main__':
    main()
