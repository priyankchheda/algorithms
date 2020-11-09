""" unittest for linked list operations """

import unittest
from linked_list import LinkedList

def linkedlist_to_array(linkedlist):
    """ converting linkedlist data to list """
    result = []
    current = linkedlist.get_head()
    while current:
        result.append(current.get_data())
        current = current.get_next()
    return result


class TestLinkedListEmpty(unittest.TestCase):
    """ tests on empty linked list """
    def setUp(self):
        """ setup empty linked list """
        self.linkedlist = LinkedList()

    def test_lenght(self):
        """ test for linked list lenght operation """
        self.assertEqual(len(self.linkedlist), 0)

    def test_get_head(self):
        """ test for linked list get_head operation """
        self.assertIsNone(self.linkedlist.head)

    def test_is_empty(self):
        """ test for linked list is_empty operation """
        self.assertTrue(self.linkedlist.is_empty())

    def test_insert_head(self):
        """ test for linked list insert_head operation """
        self.linkedlist.insert_head(45)
        self.linkedlist.insert_head(34)
        self.assertListEqual(linkedlist_to_array(self.linkedlist), [34, 45])

    def test_insert_tail(self):
        """ test for linked list insert_tail operation """
        self.linkedlist.insert_tail(45)
        self.linkedlist.insert_tail(34)
        self.linkedlist.insert_tail(56)
        self.assertListEqual(linkedlist_to_array(self.linkedlist), [45, 34, 56])


class TestLinkedList(unittest.TestCase):
    """ tests on filled linked list """
    def setUp(self):
        """ setup empty linked list """
        self.linkedlist = LinkedList()
        self.linkedlist.insert_tail(1)
        self.linkedlist.insert_tail(2)
        self.linkedlist.insert_tail(3)
        self.linkedlist.insert_tail(4)
        self.linkedlist.insert_tail(5)

    def test_lenght(self):
        """ test for linked list lenght operation """
        self.assertEqual(len(self.linkedlist), 5)

    def test_get_head(self):
        """ test for linked list get_head operation """
        self.assertIsNotNone(self.linkedlist.head)

    def test_is_empty(self):
        """ test for linked list is_empty operation """
        self.assertFalse(self.linkedlist.is_empty())

    def test_insert_head(self):
        """ test for linked list insert_head operation """
        self.linkedlist.insert_head(45)
        self.assertListEqual(linkedlist_to_array(self.linkedlist), [45, 1, 2, 3, 4, 5])
        self.linkedlist.insert_head(34)
        self.assertListEqual(linkedlist_to_array(self.linkedlist), [34, 45, 1, 2, 3, 4, 5])

    def test_insert_tail(self):
        """ test for linked list insert_tail operation """
        self.linkedlist.insert_tail(45)
        self.assertListEqual(linkedlist_to_array(self.linkedlist), [1, 2, 3, 4, 5, 45])
        self.linkedlist.insert_tail(34)
        self.assertListEqual(linkedlist_to_array(self.linkedlist), [1, 2, 3, 4, 5, 45, 34])
        self.linkedlist.insert_tail(56)
        self.assertListEqual(linkedlist_to_array(self.linkedlist), [1, 2, 3, 4, 5, 45, 34, 56])

    def test_insert_at(self):
        """ test for linked list insert_at operation """
        self.linkedlist.insert_at(45, 2)
        self.assertListEqual(linkedlist_to_array(self.linkedlist), [1, 45, 2, 3, 4, 5])
        self.linkedlist.insert_at(34, 4)
        self.assertListEqual(linkedlist_to_array(self.linkedlist), [1, 45, 2, 34, 3, 4, 5])
        self.linkedlist.insert_at(44, 10)
        self.assertListEqual(linkedlist_to_array(self.linkedlist), [1, 45, 2, 34, 3, 4, 5, 44])
        self.linkedlist.insert_at(23, 0)
        self.assertListEqual(linkedlist_to_array(self.linkedlist), [23, 1, 45, 2, 34, 3, 4, 5, 44])
        self.linkedlist.insert_at(22, -2)
        self.assertListEqual(linkedlist_to_array(self.linkedlist), [22, 23, 1, 45, 2, 34, 3, 4, 5, 44])


if __name__ == '__main__':
    unittest.main()
