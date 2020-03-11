/**
 * Given a Linked List and a number n, write a function the returns the value
 * at the n'th node from the end of the linked list.
 *
 * For example, if the input is below list and n = 3, then output is "B"
 *      A -> B -> C -> D -> NULL
 *
 * URL: https://www.geeksforgeeks.org/nth-node-from-the-end-of-a-linked-list/
*/

#include <iostream>
#include "LinkedList/LinkedList.hpp"

int getNthFromEnd_UsingLengthMethod(LinkedList* ll, int position);
int getNthFromEnd_UsingTwoPointerMethod(LinkedList* ll, int position);

int main() {
    LinkedList ll;
    ll.insertEnd(20);
    ll.insertEnd(4);
    ll.insertEnd(45);
    ll.insertEnd(32);
    ll.insertEnd(67);

    // Using length Method
    std::cout << getNthFromEnd_UsingLengthMethod(&ll, 4) << "\n"; // 4
    std::cout << getNthFromEnd_UsingLengthMethod(&ll, 5) << "\n"; // 20
    std::cout << getNthFromEnd_UsingLengthMethod(&ll, 1) << "\n"; // 67
    std::cout << getNthFromEnd_UsingLengthMethod(&ll, 7) << "\n"; // -1
    std::cout << getNthFromEnd_UsingLengthMethod(&ll, 0) << "\n"; // -1
    std::cout << getNthFromEnd_UsingLengthMethod(&ll, -1) << "\n"; // -1

    // Using two pointer method
    std::cout << getNthFromEnd_UsingTwoPointerMethod(&ll, 4) << "\n"; // 4
    std::cout << getNthFromEnd_UsingTwoPointerMethod(&ll, 5) << "\n"; // 20
    std::cout << getNthFromEnd_UsingTwoPointerMethod(&ll, 1) << "\n"; // 67
    std::cout << getNthFromEnd_UsingTwoPointerMethod(&ll, 7) << "\n"; // -1
    std::cout << getNthFromEnd_UsingTwoPointerMethod(&ll, 0) << "\n"; // -1
    std::cout << getNthFromEnd_UsingTwoPointerMethod(&ll, -1) << "\n"; // -1
    return 0;
}

/**
 * calculates the length of linked list and then print (length - position)th
 * node from the beginning of the linked list.
 * Returns -1 if position is greater than linked list current length or
 * less than zero.
 * Time complexity: O(n) where n is the length of linked list.
 *
 * @param ll linked list object pointer.
 * @param position position from end. Position is 1-based.
 * @return nth node's value from end.
*/
int getNthFromEnd_UsingLengthMethod(LinkedList* ll, int position) {
    int length = ll->getLength();
    if (position >= length + 1 || position <= 0)
        return -1;

    int positionFromStart = length - position;
    Node* node = ll->getHead();
    for (int i = 0; i < positionFromStart; i++)
        node = node->next;
    return node->data;
}

/**
 * Maintain two pointers - reference and main pointer. Initialize both of them
 * to head. Move reference pointer to n nodes from head. Now move both pointers
 * one by one until the reference pointer reaches the end. Now the main pointer
 * will point to nth node from the end.
 * Returns -1 if position is greater than linked list current length or
 * less than zero.
 * Time complexity: O(n) where n is the length of linked list.
 *
 * @param ll linked list object pointer.
 * @param position position from end. Position is 1-based.
 * @return nth node's value from end.
*/
int getNthFromEnd_UsingTwoPointerMethod(LinkedList* ll, int position) {
    int length = ll->getLength();
    Node* head = ll->getHead();
    if (position >= length + 1 || position <= 0)
        return -1;
    Node* mainptr = head;
    Node* refptr = head;
    for (int i = 1; i < position; i++) {
        refptr = refptr->next;
    }
    while (refptr->next != nullptr) {
        mainptr = mainptr->next;
        refptr = refptr->next;
    }
    return mainptr->data;
}