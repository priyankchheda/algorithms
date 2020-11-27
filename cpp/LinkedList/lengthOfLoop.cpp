/**
 * Write a function detectAndCountLoop() that checks whether a given Linked
 * List contains loop and if loop is present then returns count of nodes in
 * loop. For example, loop is present in below linked list and length of loop
 * is 4. If loop is not present, then function should return 0.
 *              1 -> 2 -> 3
 *                   ^    |
 *                   |    v
 *                   5 <- 4
 * url: https://www.geeksforgeeks.org/find-length-of-loop-in-linked-list/
 * cmd: g++ -Wall -std=c++14 lengthOfLoop.cpp
*/

#include <iostream>
#include "LinkedList/LinkedList.hpp"

int detectAndCountLoop(LinkedList::Node<int>* head);

int main()
{
    LinkedList::LinkedList<int> ll;
    ll.insertEnd(1);
    ll.insertEnd(2);
    ll.insertEnd(3);
    ll.insertEnd(4);
    ll.insertEnd(5);

    // creating loop
    LinkedList::Node<int>* head = ll.getHead();
    head->next->next->next->next->next = head->next;

    std::cout << detectAndCountLoop(head) << "\n";

    LinkedList::LinkedList<int> ll1;
    ll1.insertEnd(1);
    ll1.insertEnd(2);
    ll1.insertEnd(3);
    head = ll1.getHead();
    std::cout << detectAndCountLoop(head) << "\n";

    return 0;
}

/**
 * We know that Floyd’s Cycle detection algorithm terminates when fast and
 * slow pointers meet at a common point. We also know that this common point
 * is one of the loop nodes (2 or 3 or 4 or 5 in the above diagram). We store
 * the address of this common point in a pointer variable say ptr. Then we
 * initialize a counter with 1 and start from the common point and keeps on
 * visiting next node and increasing the counter till we again reach the
 * common point(ptr). At that point, the value of the counter will be equal
 * to the length of the loop.
 *
 * @param head node pointer linked list's head
 * @return length of loop
*/
int detectAndCountLoop(LinkedList::Node<int>* head)
{
    LinkedList::Node<int>* slowPtr = head;
    LinkedList::Node<int>* fastPtr = head;
    while (fastPtr != nullptr && fastPtr->next != nullptr) {
        fastPtr = fastPtr->next->next;
        slowPtr = slowPtr->next;
        if (slowPtr == fastPtr)
            break;
    }

    if (fastPtr == nullptr || fastPtr->next == nullptr)
        return 0;

    int counter = 1;
    LinkedList::Node<int>* temp = slowPtr->next;
    while(temp != slowPtr) {
        temp = temp->next;
        counter++;
    }
    return counter;
}
