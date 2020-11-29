""" Josephus Circle using circular linked list
    URL: https://www.geeksforgeeks.org/josephus-circle-using-circular-linked-list/

    There are n people standing in a circle waiting to be executed. The
    counting out begins at some point in the circle and proceeds around the
    circle in a fixed direction. In each step, a certain number of people are
    skipped and the next person is executed. The elimination proceeds around
    the circle (which is becoming smaller and smaller as the executed people
    are removed), until only the last person remains, who is given freedom.
    Given the total number of persons n and a number m which indicates that
    m-1 persons are skipped and m-th person is killed in circle. The task is
    to choose the place in the initial circle so that you are the last one
    remaining and so survive.

    Example:
    Input: Length of circle: n = 4
           Count to choose next: m = 2
    Output : 1

    Input: n = 5
           m = 3
    Output: 4
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

    def insert_tail(self, data):
        """ inserts node at the end of linked list """
        node = Node(data)
        if self.head is None:
            self.head = node
        else:
            current = self.head
            while current.next is not None:
                current = current.next
            current.next = node

    def print(self):
        """ prints entire linked list without changing underlying data """
        current = self.head
        while current is not None:
            print(" ->", current.data, end="")
            current = current.next
        print()


class CircularLinkedList:
    """ Circular linked list is a linked list where all nodes are connected
        to form a circle.
    """
    def __init__(self):
        """ initializing circular linked list with zero node """
        self.head = None

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


def is_circular(llist):
    """ returns true if linkedlist is circular, else false """
    if llist.head is None:
        return False

    current = llist.head.next
    while current is not llist.head:
        if current is None:
            return False
        current = current.next
    return True


def main():
    """ operational function """
    cll = CircularLinkedList()
    cll.insert_tail(1)
    cll.insert_tail(2)
    cll.insert_tail(3)
    cll.insert_tail(4)
    cll.print()
    print("is circular?", is_circular(cll))

    ll = LinkedList()
    ll.insert_tail(1)
    ll.insert_tail(2)
    ll.insert_tail(3)
    ll.insert_tail(4)
    ll.print()
    print("is circular?", is_circular(ll))


if __name__ == '__main__':
    main()
