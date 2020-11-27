/*
 * Queue (C implementation)
 * Author: Priyank Chheda
 *         E: p.chheda29@gmail.com
 *         W: https://github.com/x899
 *

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


#define QUEUE_FULL -1
#define QUEUE_EMPTY -2

/* Queue Structure */
struct queue
{
    int maxsize;
    int front;
    int rear;
    int *items;
};

typedef struct queue QUEUE;

/* Queue ADT */
QUEUE* newQueue(int);
int enqueue(QUEUE*, int);
int dequeue(QUEUE*, int*);
void display(QUEUE*);

#endif
