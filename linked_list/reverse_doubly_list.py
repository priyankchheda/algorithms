""" Reverse Doubly linked list
    URL: https://www.geeksforgeeks.org/reverse-a-doubly-linked-list/
"""

class Node:
    """ Node class contains everything related to linked list node """

    def __init__(self, data):
        """ initializing single node with data """
        self.data = data
        self.next = None
        self.previous = None


class DoublyLinkedList:
    """ A Doubly linked list (DLL) contains an extra pointer, typically
        called previous pointer, together with next pointer and data which
        are there in singly linked list.
    """
    def __init__(self):
        """ initializing doublt linked list with zero node """
        self.head = None

    def insert_tail(self, data):
        """ inserts node at the end of doubly linked list """
        if self.head is None:
            self.head = Node(data)
            return

        current = self.head
        new_node = Node(data)
        while current.next is not None:
            current = current.next
        current.next = new_node
        new_node.previous = current

    def print(self):
        """ prints entire linked list without changing underlying data """
        current = self.head
        while current is not None:
            print(" <->", current.data, end="")
            current = current.next
        print()

    def reverse(self):
        """ reverse doubly linked list """
        temp = None
        current = self.head

        while current is not None:
            temp = current.previous
            current.previous = current.next
            current.next = temp
            current = current.previous

        if temp is not None:
            self.head = temp.previous

def main():
    """ operational function """
    dll = DoublyLinkedList()
    dll.insert_tail(1)
    dll.insert_tail(2)
    dll.insert_tail(3)
    dll.insert_tail(4)
    dll.insert_tail(5)
    dll.insert_tail(6)
    dll.print()

    dll.reverse()
    dll.print()


if __name__ == '__main__':
    main()
