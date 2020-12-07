""" Merge two sorted linked lists
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

def print_linkedlist(head):
    """ prints entire linked list without changing underlying data """
    current = head
    while current is not None:
        print(" ->", current.data, end="")
        current = current.next
    print()


def merge_sorted(linkedlist1, linkedlist2):
    """ merge two sorted linked lists """
    node1_ptr = linkedlist1.head
    node2_ptr = linkedlist2.head
    s_ptr = None

    if node1_ptr is None:
        return node2_ptr

    if node2_ptr is None:
        return node1_ptr

    if node1_ptr.data > node2_ptr.data:
        s_ptr = node2_ptr
        node2_ptr = node2_ptr.next
    else:
        s_ptr = node1_ptr
        node1_ptr = node1_ptr.next

    result_head = s_ptr

    while node1_ptr and node2_ptr:
        if node1_ptr.data > node2_ptr.data:
            s_ptr.next = node2_ptr
            s_ptr = node2_ptr
            node2_ptr = node2_ptr.next
        else:
            s_ptr.next = node1_ptr
            s_ptr = node1_ptr
            node1_ptr = node1_ptr.next

    if node2_ptr is None:
        s_ptr.next = node1_ptr
    elif node1_ptr is None:
        s_ptr.next = node2_ptr

    return result_head



def main():
    """ operational function """
    linkedlist1 = LinkedList()
    linkedlist1.insert_head(10)
    linkedlist1.insert_head(9)
    linkedlist1.insert_head(7)
    linkedlist1.insert_head(5)
    linkedlist1.insert_head(1)

    linkedlist2 = LinkedList()
    linkedlist2.insert_head(8)
    linkedlist2.insert_head(6)
    linkedlist2.insert_head(4)
    linkedlist2.insert_head(3)
    linkedlist2.insert_head(2)
    linkedlist2.insert_head(1)

    print_linkedlist(merge_sorted(linkedlist1, linkedlist2))


if __name__ == '__main__':
    main()
