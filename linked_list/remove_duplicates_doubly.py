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

    def remove_duplicates(self):
        """ removes duplicates from list """
        duplicates = set()
        current = self.head

        while current is not None:
            if current.data not in duplicates:
                duplicates.add(current.data)
                current = current.next
            else:
                previous_node = current.previous
                del_node = current
                current = current.next
                previous_node.next = current
                if current is not None:
                    current.previous = previous_node
                del_node.previous = None
                del_node.next = None
                del del_node


def main():
    """ operational function """
    dll = DoublyLinkedList()
    dll.insert_tail(4)
    dll.insert_tail(2)
    dll.insert_tail(2)
    dll.insert_tail(4)
    dll.insert_tail(1)
    dll.insert_tail(6)
    dll.insert_tail(1)
    dll.print()

    dll.remove_duplicates()
    dll.print()


if __name__ == '__main__':
    main()
