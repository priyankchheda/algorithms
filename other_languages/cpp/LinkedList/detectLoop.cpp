/**
 * Given a linked list, check if the linked list has loop or not. Below
 * diagram shows a linked list with loop a loop.
 *              1 -> 2 -> 3
 *                   ^    |
 *                   |    v
 *                   5 <- 4
 * url: https://www.geeksforgeeks.org/detect-loop-in-a-linked-list/
 * cmd: g++ -Wall -std=c++14 detectLoop.cpp
*/

#include <iostream>
#include "LinkedList/LinkedList.hpp"

bool detectLoop(LinkedList::LinkedList<float>* ll);

int main()
{
    LinkedList::LinkedList<float> ll;
    ll.insertEnd(1.1f);
    ll.insertEnd(2.2f);
    ll.insertEnd(3.3f);
    ll.insertEnd(4.4f);
    ll.insertEnd(5.5f);

    // creating loop
    LinkedList::Node<float>* head = ll.getHead();
    head->next->next->next->next->next = head->next;

    if (detectLoop(&ll))
        std::cout << "cycle detected\n";
    else std::cout << "cycle not detected\n";

    LinkedList::LinkedList<float> ll1;
    ll1.insertEnd(1.2f);
    ll1.insertEnd(2.3f);
    ll1.insertEnd(3.4f);

    if (detectLoop(&ll1))
        std::cout << "cycle detected\n";
    else std::cout << "cycle not detected\n";
    return 0;
}

/**
 * Floyd's Cycle-Finding Algorithm:
 * Traverse linked list using two pointers. Move one pointer (slowPtr) by
 * one node and another pointer (fastPtr) by two nodes.
 * If these pointers meet at the same node then there is a loop.
 * If pointers do not meet then linked list doesn't have a loop.
 *
 * @param ll pointer to linked list
 * @return true if loop is present, else false.
*/
bool detectLoop(LinkedList::LinkedList<float>* ll)
{
    LinkedList::Node<float>* head = ll->getHead();
    LinkedList::Node<float>* slowPtr = head;
    LinkedList::Node<float>* fastPtr = head;

    while (fastPtr != nullptr && fastPtr->next != nullptr) {
        fastPtr = fastPtr->next->next;
        slowPtr = slowPtr->next;
        if (fastPtr == slowPtr)
            return true;
    }
    return false;
}
