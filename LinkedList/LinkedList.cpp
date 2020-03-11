#include <iostream>
#include "LinkedList.hpp"

/**
 * Returns the number of node currently present in the linked list.
 * @return count of node, or 0 if the list is empty.
*/
int LinkedList::getLength() {
    Node* temp = head;
    int count = 0;
    while (temp) {
        count++;
        temp = temp->next;
    }
    return count;
}

/**
 * Returns the number of node currently present in the linked list.
 * It uses recursive approach.
 * @param node starting node from where counting is start.
 * @return count of node, or 0 if the list is empty.
*/
int LinkedList::getLengthRecursive(Node* node) {
    if (node == nullptr) return 0;
    return 1 + getLengthRecursive(node->next);
}

/**
 * Inserts new node with value 'data' at the start of linked list.
 * @param data new data element that needs to be added at the start
*/
void LinkedList::insertHead(int data) {
    Node* temp = new Node(data);
    temp->next = head;
    head = temp;
}

/**
 * Inserts new node with value 'data' at the end of linked list.
 * @param data new data element that needs to be append at the end
*/
void LinkedList::insertEnd(int data) {
    Node* newNode = new Node(data);
    Node* temp = head;
    if (temp == nullptr) {
        head = newNode;
        return;
    }
    while(temp->next != nullptr) {
        temp = temp->next;
    }
    temp->next = newNode;
}

/**
 * Insert new node with value 'data' at given position in linked list.
 * @param data new data element that needs to be added at given position.
 * @param position position where new node will enter.
 *      Position is 1-based.
*/
void LinkedList::insertAt(int data, int position) {
    int linkedlist_len = getLength();
    if (position <= 1) {
        insertHead(data);
        return;
    } else if (position >= linkedlist_len) {
        insertEnd(data);
        return;
    } else {
        Node* newNode = new Node(data);
        Node* previous = head;
        Node* current = head;
        for (int i = 1; i < position; i++) {
            previous = current;
            current = current->next;
        }
        previous->next = newNode;
        newNode->next = current;
    }
}

/**
 * Delete head node from linked list
 * @return removedData value of deleted node
*/
int LinkedList::deleteHead() {
    if (head == nullptr) return -1;
    Node* temp = head;
    int removedData = temp->data;
    head = head->next;
    delete temp;
    return removedData;
}

/**
 * Delete end node from linked list
 * @return removedData value of deleted node
*/
int LinkedList::deleteEnd() {
    if (head == nullptr) return -1;
    Node* current = head;
    if (head->next == nullptr) head = nullptr;
    else {
        Node* previous = head;
        while (current->next != nullptr) {
            previous = current;
            current = current->next;
        }
        previous->next = nullptr;
    }
    int removedData = current->data;
    delete current;
    return removedData;
}

/**
 * Delete node present at given position from linked list
 * @param position position at which node needs to be deleted.
 *      Position is 1-based.
 * @return removedData value of deleted node
*/
int LinkedList::deleteAt(int position) {
    int ll_length = getLength();
    if (position < 1 || position > ll_length)
        return -1;

    if (position == 1)
        return deleteHead();
    else if (position == ll_length)
        return deleteEnd();
    else {
        Node* previous = head;
        Node* current = head;
        for (int i = 1; i < position; i++) {
            previous = current;
            current = current->next;
        }
        int removedData = current->data;
        previous->next = current->next;
        current->next = nullptr;
        delete current;
        return removedData;
    }
}

/**
 * Delete first occurance of node from linked list with value 'key'
 * @param key node value that needs to be deleted
 * @return removedData value of deleted node
*/
int LinkedList::deleteKey(int key) {
    return deleteAt(indexOf(key));
}

/**
 * Deletes entire linked list. Cleans up the memory.
 * head node pointer is pointing to null.
*/
void LinkedList::deleteList() {
    Node* current = head;
    Node* next = nullptr;
    while (current != nullptr) {
        next = current->next;
        delete current;
        current = next;
    }
    head = nullptr;
}

/**
 * Get node value present at given position in the linked list
 * @param position position at which node value is needed. Position is 1-based.
 * @return node value at position
*/
int LinkedList::dataAt(int position) {
    int ll_length = getLength();
    if (position < 1 || position > ll_length)
        return -1;

    Node* current = head;
    for (int i = 1; i < position; i++)
        current = current->next;

    return current->data;
}

/**
 * Returns index of node in linked list with node value 'key'.
 * Returns -1, if the key is not present.
 * @param count index of node with value 'key'
*/
int LinkedList::indexOf(int key) {
    Node* node = head;
    int count = 1;
    while (node != nullptr) {
        if (node->data == key)
            return count;
        node = node->next;
        count++;
    }
    return -1;
}

/**
 * Reverse the original linked list using iterative approach.
*/
void LinkedList::Reverse() {
    Node* previous = nullptr;
    Node* following = nullptr;
    Node* current = head;

    while (current != nullptr) {
        following = current->next;
        current->next = previous;
        previous = current;
        current = following;
    }
    head = previous;
}

/**
 * Reverse the original linked list using recursive approach.
*/
void LinkedList::ReverseRecursive(Node* node) {
    if (node == nullptr)
        return;
    if (node->next == nullptr) {
        head = node;
        return;
    }
    ReverseRecursive(node->next);
    Node* prev = node->next;
    prev->next = node;
    node->next = nullptr;
}

/**
 * printList simply prints the node value from head to end.
*/
void LinkedList::printList() {
    Node* temp = head;
    while (temp) {
        std::cout << " -> " << temp->data;
        temp = temp->next;
    }
    std::cout << std::endl;
}

/**
 * printListRecursive simply prints the node value from head to end.
 * It uses recursive approach.
*/
void LinkedList::printListRecursive(Node* node) {
    if (node == nullptr) return;
    std::cout << " -> " << node->data;
    printListRecursive(node->next);
}

/**
 * printReverseListRecursive simply prints the node value in reverse order,
 * from tail to head. It uses recursive approach.
*/
void LinkedList::printReverseListRecursive(Node* node) {
    if (node == nullptr) return;
    printReverseListRecursive(node->next);
    std::cout << " -> " << node->data;
}
