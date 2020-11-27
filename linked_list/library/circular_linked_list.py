""" Implementation of Circular Linked List Data Structure
    Circular linked list is a linked list where all nodes are connected to
    form a circle. There is no NULL at the end. A circular linked list can
    be a singly circular linked list or doubly circular linked list.
"""

class Node:
    """ Node class contains everything related to Linked List node """
    def __init__(self, data):
        """ initializing single node with data """
        self.data = data
        self.next = None


class CircularLinkedList:
    """ Circular linked list is a linked list where all nodes are connected
        to form a circle.
    """
    def __init__(self):
        """ initializing circular linked list with zero node """
        self.head = None

    def __len__(self):
        """ get number of nodes currently present in circular linked list """
        if self.head is None:
            return 0

        current = self.head
        count = 1
        while current.next is not self.head:
            count += 1
            current = current.next
        return count

    def insert_head(self, data):
        """ inserts node at the start of linked list """
        if self.head is None:
            self.head = Node(data)
            self.head.next = self.head
            return

        new_node = Node(data)
        current = self.head
        while current.next is not self.head:
            current = current.next
        current.next = new_node
        new_node.next = self.head
        self.head = new_node

    def insert_tail(self, data):
        """ inserts node at the end of linked list """
        if self.head is None:
            self.head = Node(data)
            self.head.next = self.head
            return

        new_node = Node(data)
        current = self.head
        while current.next is not self.head:
            current = current.next
        current.next = new_node
        new_node.next = self.head

    def remove(self, key):
        """ remove data key from circular linked list """
        if self.head.data == key:
            previous = self.head
            while previous.next is not self.head:
                previous = previous.next
            previous.next = self.head.next
            self.head = previous.next
            return

        current = self.head.next
        previous = self.head
        while current is not self.head:
            if current.data == key:
                break
            previous = current
            current = current.next
        previous.next = current.next

    def print(self):
        """ prints entire linked list without changing underlying data """
        current = self.head
        while current is not None:
            print(" ->", current.data, end="")
            current = current.next
            if current == self.head:
                break
        print(end=" -> ...")
        print()


def main():
    """ operational function """
    cll = CircularLinkedList()
    cll.insert_tail('C')
    cll.print()
    cll.insert_tail('D')
    cll.print()
    cll.insert_head('B')
    cll.print()
    cll.insert_head('A')
    cll.print()
    print("size:", len(cll))

    cll.remove('B')
    cll.print()
    print("size:", len(cll))

    cll.remove('A')
    cll.print()
    print("size:", len(cll))


if __name__ == '__main__':
    main()
