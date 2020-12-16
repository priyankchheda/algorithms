""" Split a Circular Linked List into two halves
    If there are odd number of nodes, then first list should contain one extra.

    Input: A -> B -> C -> D -> ...
    Output: A -> B -> ... and C -> D -> ...

    URL: https://www.geeksforgeeks.org/split-a-circular-linked-list-into-two-halves/
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


def split_list(cll):
    """ split a circular linked list into two halves """
    slow_ptr = cll.head
    fast_ptr = cll.head

    while (fast_ptr.next is not cll.head and
           fast_ptr.next.next is not cll.head):
        slow_ptr = slow_ptr.next
        fast_ptr = fast_ptr.next.next

    while fast_ptr.next is not cll.head:
        fast_ptr = fast_ptr.next

    cll1 = CircularLinkedList()
    cll2 = CircularLinkedList()

    cll1.head = cll.head
    cll2.head = slow_ptr.next
    slow_ptr.next = cll1.head
    fast_ptr.next = cll2.head

    return cll1, cll2


def main():
    """ operational function """
    cll = CircularLinkedList()
    cll.insert_tail('A')
    cll.insert_tail('B')
    cll.insert_tail('C')
    cll.insert_tail('D')
    cll.insert_tail('E')
    cll.insert_tail('F')
    cll.insert_tail('G')
    cll.print()

    cll1, cll2 = split_list(cll)
    cll1.print()
    cll2.print()

if __name__ == '__main__':
    main()
