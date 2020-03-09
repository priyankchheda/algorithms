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
    void insertHead(int data);
    void insertEnd(int data);
    void insertAt(int data, int position);
    int getLength();
    void printLinkedList();
};

#endif
