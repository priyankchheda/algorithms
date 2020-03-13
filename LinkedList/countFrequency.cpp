/**
 * Given a singly linked list and a key, count number of occurances of given
 * key in linked list. For example, if given linked list is
 * 1 -> 2 -> 1 -> 2 -> 1 -> 3 -> 1 and given key is 1, then output
 * should be 4.
 *
 * url: https://www.geeksforgeeks.org/write-a-function-that-counts-the-\
 *      number-of-times-a-given-int-occurs-in-a-linked-list/
 * cmd: g++ countFrequency.cpp LinkedList/LinkedList.cpp -std=c++14
*/

#include <iostream>
#include "LinkedList/LinkedList.hpp"

int countFrequency(LinkedList* ll, int key);
int countFrequencyRecursion(Node* node, int key);

int main()
{
    LinkedList ll;
    ll.insertEnd(1);
    ll.insertEnd(2);
    ll.insertEnd(1);
    ll.insertEnd(2);
    ll.insertEnd(1);
    ll.insertEnd(3);
    ll.insertEnd(1);

    std::cout << countFrequency(&ll, 1) << "\n";
    std::cout << countFrequencyRecursion(ll.getHead(), 1) << "\n";
    return 0;
}

/**
 * Tranversing through the linked list and count the occurance of key.
 * Using non-recursive approach.
 * @param ll pointer to linked list
 * @param key key integer who frequency we need
 * @return key count frequency
*/
int countFrequency(LinkedList* ll, int key)
{
    Node* temp = ll->getHead();
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
int countFrequencyRecursion(Node* node, int key)
{
    if (node == nullptr)
        return 0;
    if (node->data == key)
        return 1 + countFrequencyRecursion(node->next, key);
    return countFrequencyRecursion(node->next, key);
}
