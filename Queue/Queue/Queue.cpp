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
    front = -1;
    rear = -1;
}

Queue::~Queue() {
    delete items;
}

bool Queue::isFull() {
    int nextRear = rear % capacity;
    return nextRear = front;
}

bool Queue::isEmpty() {
    return rear == -1 && front == -1;
}

int Queue::enqueue(int element) {
    if (isEmpty()) {
        front = 0;
        rear = 0;
        items[rear] = element;
    } else if (isFull()) {
        return QUEUE_FULL;
    } else {
        rear = (rear + 1) % capacity;
        items[rear] = element;
    }
    return 0;
}

int Queue::dequeue() {
    if (isFull()) {
        return QUEUE_EMPTY;
    }
    int removedValue = items[front];
    if (front == rear) {
        front = -1;
        rear = -1;
    } else {
        front = (front + 1) % capacity;
    }
    return removedValue;
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
