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


    def nth_to_last_node(self, position):
        """ returns nth to last node """
        fast_ptr = self.head
        slow_ptr = self.head

        while position > 0:
            slow_ptr = slow_ptr.next
            position -= 1

        while slow_ptr is not None:
            slow_ptr = slow_ptr.next
            fast_ptr = fast_ptr.next

        return fast_ptr


def main():
    """ operational function """
    linkedlist = LinkedList()
    linkedlist.insert_head('D')
    linkedlist.insert_head('C')
    linkedlist.insert_head('B')
    linkedlist.insert_head('A')

    linkedlist.print()
    result = linkedlist.nth_to_last_node(3)
    print(result.data)



if __name__ == '__main__':
    main()
