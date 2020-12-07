""" Swap two nodes in a linked list
    input: 1 -> 5 -> 2 -> 3 -> 7 -> 9 -> 10
    output: 1 -> 7 -> 2 -> 3 -> 5 -> 9 -> 10
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


    def swap_node(self, node1, node2):
        """ swap node1 with node2 """
        previous1 = None
        current1 = self.head
        while current1 is not None:
            if current1 is node1:
                break
            previous1 = current1
            current1 = current1.next

        previous2 = None
        current2 = self.head
        while current2 is not None:
            if current2 is node2:
                break
            previous2 = current2
            current2 = current2.next

        if previous1 is not None:
            previous1.next = current2
        else:
            self.head = current2
        if previous2 is not None:
            previous2.next = current1
        else:
            self.head = current1

        current1.next, current2.next = current2.next, current1.next


def main():
    """ operational function """
    linkedlist = LinkedList()
    linkedlist.insert_head(10)
    linkedlist.insert_head(9)
    linkedlist.insert_head(7)
    linkedlist.insert_head(3)
    linkedlist.insert_head(2)
    linkedlist.insert_head(5)
    linkedlist.insert_head(1)

    linkedlist.print()
    linkedlist.swap_node(linkedlist.head.next, linkedlist.head.next.next.next.next)
    linkedlist.print()


if __name__ == '__main__':
    main()
