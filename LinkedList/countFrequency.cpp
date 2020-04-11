/**
 * Given a singly linked list and a key, count number of occurances of given
 * key in linked list. For example, if given linked list is
 * 1 -> 2 -> 1 -> 2 -> 1 -> 3 -> 1 and given key is 1, then output
 * should be 4.
 *
 * url: https://www.geeksforgeeks.org/write-a-function-that-counts-the-\
 *      number-of-times-a-given-int-occurs-in-a-linked-list/
 * cmd: g++ -Wall -std=c++14 countFrequency.cpp
*/

#include <iostream>
#include "LinkedList/LinkedList.hpp"

int countFrequency(LinkedList::LinkedList<char>* ll, char key);
int countFrequencyRecursion(LinkedList::Node<char>* node, char key);

int main()
{
    LinkedList::LinkedList<char> ll;
    ll.insertEnd('a');
    ll.insertEnd('b');
    ll.insertEnd('a');
    ll.insertEnd('b');
    ll.insertEnd('a');
    ll.insertEnd('c');
    ll.insertEnd('a');

    std::cout << countFrequency(&ll, 'a') << "\n";
    std::cout << countFrequencyRecursion(ll.getHead(), 'a') << "\n";
    return 0;
}

/**
 * Tranversing through the linked list and count the occurance of key.
 * Using non-recursive approach.
 * @param ll pointer to linked list
 * @param key key integer who frequency we need
 * @return key count frequency
*/
int countFrequency(LinkedList::LinkedList<char>* ll, char key)
{
    LinkedList::Node<char>* temp = ll->getHead();
    int count = 0;
    while (temp) {
        if (temp->data == key)
            count++;
        temp = temp->next;
    }
    return count;
}

/**
 * Tranversing through the linked list and count the occurance of key.
 * Using non-recursive approach.
 * @param node pointer to linked list node
 * @param key key integer who frequency we need
 * @return key count frequency
*/
int countFrequencyRecursion(LinkedList::Node<char>* node, char key)
{
    if (node == nullptr)
        return 0;
    if (node->data == key)
        return 1 + countFrequencyRecursion(node->next, key);
    return countFrequencyRecursion(node->next, key);
}
