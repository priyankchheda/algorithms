""" Remove duplicates from singly linked list
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


    def remove_duplicates(self):
        """ removes duplicates from list """
        duplicates = set()
        previous = None
        current = self.head

        while current is not None:
            if current.data not in duplicates:
                duplicates.add(current.data)
                previous = current
            else:
                previous.next = current.next
            current = current.next


def main():
    """ operational function """
    linkedlist = LinkedList()
    linkedlist.insert_head(4)
    linkedlist.insert_head(2)
    linkedlist.insert_head(2)
    linkedlist.insert_head(4)
    linkedlist.insert_head(1)
    linkedlist.insert_head(6)
    linkedlist.insert_head(1)

    linkedlist.print()
    linkedlist.remove_duplicates()
    linkedlist.print()


if __name__ == '__main__':
    main()
