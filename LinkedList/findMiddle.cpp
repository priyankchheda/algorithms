/**
 * Given a singly linked list, find middle of the linked list.
 * For example, if given linked list is 1 -> 2 -> 3 -> 4 -> 5,
 * then output should be 3.
 *
 * If there are even nodes, then there would be two middle nodes, we need to
 * print second middle element. For example, if given linked list is
 * 1 -> 2 -> 3 -> 4 -> 5 -> 6, then output should be 4.
 *
 * URL: https://www.geeksforgeeks.org/write-a-c-function-to-print-the-\
 *      middle-of-the-linked-list/
 * cmd: g++ findMiddle.cpp LinkedList/LinkedList.cpp -Wall -std=c++14
*/

#include <iostream>
#include "LinkedList/LinkedList.hpp"

int findMiddle_UsingLength(LinkedList* ll);
int findMiddle_UsingTwoPointer(LinkedList* ll);
int findMiddle_UsingOddIncrement(LinkedList* ll);

int main()
{
    LinkedList empty_ll;

    LinkedList odd_ll;
    odd_ll.insertEnd(1);
    odd_ll.insertEnd(2);
    odd_ll.insertEnd(3);
    odd_ll.insertEnd(4);
    odd_ll.insertEnd(5);

    LinkedList even_ll;
    even_ll.insertEnd(1);
    even_ll.insertEnd(2);
    even_ll.insertEnd(3);
    even_ll.insertEnd(4);
    even_ll.insertEnd(5);
    even_ll.insertEnd(6);

    // Using Length Method
    std::cout << findMiddle_UsingLength(&empty_ll) << " "; // -1
    std::cout << findMiddle_UsingLength(&odd_ll) << " "; // 3
    std::cout << findMiddle_UsingLength(&even_ll) << "\n"; // 4

    // Using Two Pointer Method
    std::cout << findMiddle_UsingTwoPointer(&empty_ll) << " "; // -1
    std::cout << findMiddle_UsingTwoPointer(&odd_ll) << " "; // 3
    std::cout << findMiddle_UsingTwoPointer(&even_ll) << "\n"; // 4

    // Using Odd Increment Method
    std::cout << findMiddle_UsingOddIncrement(&empty_ll) << " "; // -1
    std::cout << findMiddle_UsingOddIncrement(&odd_ll) << " "; // 3
    std::cout << findMiddle_UsingOddIncrement(&even_ll) << "\n"; // 4
}

/**
 * Find the length of linked list using getLength method.
 * Now traverse the list till count/2 and return node value at count/2.
 * Time complexity: O(n) where n is the length of linked list.
 *
 * @param ll linked list object pointer.
 * @return middle node value
*/
int findMiddle_UsingLength(LinkedList* ll)
{
    Node* node = ll->getHead();
    int len = ll->getLength();
    int middle = len / 2;

    if (node == nullptr) return -1;

    for (int i = 0; i < middle; i++)
        node = node->next;

    return node->data;
}

/**
 * Traverse linked list using two pointers. Move one pointer by one and other
 * by two. When fast pointer reaches end slow pointer reach middle of the
 * linked list.
 *
 * @param ll linked list object pointer.
 * @return middle node value
*/
int findMiddle_UsingTwoPointer(LinkedList* ll)
{
    Node* head = ll->getHead();
    Node* fast = head;
    Node* slow = head;

    if (slow == nullptr) return -1;

    while (fast != nullptr && fast->next != nullptr) {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow->data;
}

/**
 * Initialize mid element as head and initialize a counter as zero. Traverse
 * the list from head, while traversing increment the counter and change mid
 * to mid->next whenever the counter is odd. So the mid will move only half
 * of the total length of the list.
 *
 * @param ll linked list object pointer.
 * @return middle node value
*/
int findMiddle_UsingOddIncrement(LinkedList* ll)
{
    Node* node = ll->getHead();
    if (node == nullptr)
        return -1;

    Node* mid = node;
    int counter = 0;
    while(node) {
        if (counter % 2 != 0)
            mid = mid->next;
        node = node->next;
        counter++;
    }
    return mid->data;
}

