/**
 * Like Stack, Queue is a linear structure which follows a particular order
 * in which the operations are performed. The order is First In First Out
 * (FIFO). A good example of queue is any queue of consumers for a resource
 * where the consumer that came first is served first.
 *
 * The difference between stacks and queues is in removing. In a stack we
 * remove the item the most recently added; in a queue, we remove the item
 * the least recently added.
*/

#ifndef QUEUE_H
#define QUEUE_H

#define DEFAULT_CAPACITY 10
#define QUEUE_FULL -1
#define QUEUE_EMPTY -2

class Queue {
private:
    int* items;
    int front;
    int rear;
    int capacity;

public:
    Queue(int cap = DEFAULT_CAPACITY);
    ~Queue();

    int enqueue(int item);
    int dequeue();

    int size();
    bool isEmpty();
    bool isFull();

    void display();
};

#endif
