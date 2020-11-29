""" Find middle node in linked lists
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

    def get_middle_node(self):
        """ find middle node in linkedlist using two pointer approach  """
        fast_ptr = self.head
        slow_ptr = self.head

        while fast_ptr.next is not None and fast_ptr.next.next is not None:
            fast_ptr = fast_ptr.next.next
            slow_ptr = slow_ptr.next

        return slow_ptr.data

def main():
    """ operational function """
    linkedlist = LinkedList()
    linkedlist.insert_head(10)
    linkedlist.insert_head(9)
    linkedlist.insert_head(7)
    linkedlist.insert_head(5)
    linkedlist.insert_head(1)

    print(linkedlist.get_middle_node())

if __name__ == '__main__':
    main()
