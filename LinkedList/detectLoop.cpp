/**
 * Given a linked list, check if the linked list has loop or not. Below
 * diagram shows a linked list with loop a loop.
 *              1 -> 2 -> 3
 *                   ^    |
 *                   |    v
 *                   5 <- 4
 * url: https://www.geeksforgeeks.org/detect-loop-in-a-linked-list/
 * cmd: g++ detectLoop.cpp LinkedList/LinkedList.cpp -std=c++14
*/

#include <iostream>
#include "LinkedList/LinkedList.hpp"

bool detectLoop(LinkedList* ll);

int main()
{
    LinkedList ll;
    ll.insertEnd(1);
    ll.insertEnd(2);
    ll.insertEnd(3);
    ll.insertEnd(4);
    ll.insertEnd(5);

    // creating loop
    Node* head = ll.getHead();
    head->next->next->next->next->next = head->next;

    std::cout << detectLoop(&ll) << "\n";

    LinkedList ll1;
    ll1.insertEnd(1);
    ll1.insertEnd(2);
    ll1.insertEnd(3);
    std::cout << detectLoop(&ll1) << "\n";
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
bool detectLoop(LinkedList* ll)
{
    Node* head = ll->getHead();
    Node* slowPtr = head;
    Node* fastPtr = head;

    while (fastPtr != nullptr && fastPtr->next != nullptr) {
        fastPtr = fastPtr->next->next;
        slowPtr = slowPtr->next;
        if (fastPtr == slowPtr)
            return true;
    }
    return false;
}
