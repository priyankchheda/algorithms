""" Remove duplicates from linked list
    input: 1 -> 6 -> 1 -> 4 -> 2 -> 2 -> 4
    output: 1 -> 6 -> 4 -> 2
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


    def rotate(self, position):
        """ rotate linked list from given position """
        node_ptr = self.head
        last_ptr = self.head

        while position > 1:
            node_ptr = node_ptr.next
            position -= 1

        while last_ptr.next is not None:
            last_ptr = last_ptr.next

        last_ptr.next = self.head
        self.head = node_ptr.next
        node_ptr.next = None


def main():
    """ operational function """
    linkedlist = LinkedList()
    linkedlist.insert_head(6)
    linkedlist.insert_head(5)
    linkedlist.insert_head(4)
    linkedlist.insert_head(3)
    linkedlist.insert_head(2)
    linkedlist.insert_head(1)

    linkedlist.print()
    linkedlist.rotate(4)
    linkedlist.print()


if __name__ == '__main__':
    main()
