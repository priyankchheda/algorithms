#include <iostream>
#include "Queue.hpp"

/**
 * Constructor
 * Create new Queue items array in heap memory
 * @param cap maximum capacity of Queue
*/
Queue::Queue(int cap) {
    items = new int[cap];
    capacity = cap;
    front = 0;
    rear = -1;
    item_count = 0;
}

Queue::~Queue() {
    delete items;
}

int Queue::size() {
    return item_count;
}

bool Queue::isFull() {
    return size() == capacity;
}

bool Queue::isEmpty() {
    return size() == 0;
}

int Queue::enqueue(int element) {
    if (isFull()) {
        return QUEUE_FULL;
    }
    rear = (rear + 1) % capacity;
    items[rear] = element;
    item_count++;
    return 0;
}

int Queue::dequeue() {
    if (isEmpty()) {
        return QUEUE_EMPTY;
    }
    int removedvalue = items[front];
    front = (front + 1) % capacity;
    item_count--;
    return removedvalue;
}

int Queue::peek() {
    if (isEmpty()) {
        return QUEUE_EMPTY;
    }
    return items[front];
}

void Queue::display() {
    std::cout << "Queue: ";
    if (!isEmpty()) {
        int temp = front;
        while (temp != rear) {
            std::cout << items[temp] << " ";
            temp = (temp + 1) % capacity;
        }
        std::cout << items[temp] << "\n";
    } else std::cout << "Empty\n";
}
