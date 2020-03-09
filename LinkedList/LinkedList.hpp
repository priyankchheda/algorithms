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

    /* Insertion Method */
    void insertHead(int data);
    void insertEnd(int data);
    void insertAt(int data, int position);

    /* Deletion Method */
    int deleteHead();
    int deleteEnd();
    int deleteAt(int position);

    /* Misc Method */
    void printLinkedList();
};

#endif
