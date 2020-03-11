#ifndef LINKEDLIST_H
#define LINKEDLIST_H

struct Node {
    int data;
    Node* next;

    Node(int _data) { data = _data; next = nullptr; }
};

class LinkedList {
private:
    Node* head;

public:
    LinkedList() { head = nullptr; }
    Node* getHead() { return head; }
    int getLength();
    int getLengthRecursive(Node* node);

    /* Insertion Method */
    void insertHead(int data);
    void insertEnd(int data);
    void insertAt(int data, int position);

    /* Deletion Method */
    int deleteHead();
    int deleteEnd();
    int deleteAt(int position);
    int deleteKey(int key);
    void deleteList();

    /* Data */
    int dataAt(int position);
    int indexOf(int key);

    /* Recursive Method */
    void Reverse();
    void ReverseRecursive(Node* node);

    /* Print Method */
    void printList();
    void printListRecursive(Node* node);
    void printReverseListRecursive(Node* node);
};

#endif
