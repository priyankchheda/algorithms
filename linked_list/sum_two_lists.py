""" You are given two non-empty linked lists representing two non-negative
    integers. The digits are stored in reverse order, and each of their
    nodes contains a single digit. Add the two numbers and return the sum
    as a linked list.

    You may assume the two numbers do not contain any leading zero,
    except the number 0 itself.

    Input: l1 = [2,4,3], l2 = [5,6,4]
    Output: [7,0,8]
    Explanation: 342 + 465 = 807.
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


def add_two_numbers(list1, list2):
    """ add two numbers which are represented by linkedlist """
    carry = 0
    current1 = list1.head
    current2 = list2.head
    result = LinkedList()
    result.insert_head(0)
    result_pointer = result.head

    while current1 or current2:
        val1 = getattr(current1, 'data', 0)
        val2 = getattr(current2, 'data', 0)
        temp_val = carry + val1 + val2
        carry = temp_val // 10
        result_pointer.next = Node(temp_val % 10)
        result_pointer = result_pointer.next
        current1 = getattr(current1, 'next', None)
        current2 = getattr(current2, 'next', None)

    if carry > 0:
        result_pointer.next = Node(carry)

    result.head = result.head.next
    return result



def main():
    """ operational function """
    linkedlist1 = LinkedList()
    linkedlist1.insert_head(3)
    linkedlist1.insert_head(6)
    linkedlist1.insert_head(5)
    linkedlist1.print()

    linkedlist2 = LinkedList()
    linkedlist2.insert_head(2)
    linkedlist2.insert_head(4)
    linkedlist2.insert_head(8)
    linkedlist2.print()

    add_two_numbers(linkedlist1, linkedlist2).print()


if __name__ == '__main__':
    main()
