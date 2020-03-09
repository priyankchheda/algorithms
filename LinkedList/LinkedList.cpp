#include <iostream>
#include "LinkedList.hpp"

int LinkedList::getLength() {
    Node* temp = head;
    int count = 0;
    while (temp) {
        count++;
        temp = temp->next;
    }
    return count;
}

void LinkedList::insertHead(int data) {
    Node* temp = new Node(data);
    temp->next = head;
    head = temp;
}

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

void LinkedList::printLinkedList() {
    Node* temp = head;
    while (temp) {
        std::cout << " -> " << temp->data;
        temp = temp->next;
    }
    std::cout << std::endl;
}

int LinkedList::deleteHead() {
    if (head == nullptr) return -1;
    Node* temp = head;
    int removedData = temp->data;
    head = head->next;
    delete temp;
    return removedData;
}

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
