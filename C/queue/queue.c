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


#include <stdio.h>
#include <stdlib.h>
#include "queue.h"


/**
 * Create new Queue with heap memory
 * @param capacity Initial capacity of Queue
 * @return pointer tp newly created queue
 */
QUEUE*
newQueue(int capacity)
{
    QUEUE* pt = (QUEUE*)malloc(sizeof(QUEUE));

    pt->maxsize = capacity;
    pt->front = -1;
    pt->rear = -1;
    pt->items = (int*)malloc(sizeof(int) * capacity);

    return pt;
}


/**
 * Check if the queue is full or not
 * @param pt Queue pointer
 * @return true if queue is full else false
 */
static int
isFull(QUEUE* pt)
{
    int next_rear = (pt->rear) % pt->maxsize;
    return next_rear == pt->front;
}


/**
 * Check if the queue is empty or not
 * @param pt Queue pointer
 * @return true if queue is empty else false
 */
static int
isEmpty(QUEUE* pt)
{
    return pt->rear == -1 && pt->front == -1;
}


/**
 * insert new item to queue
 * @param pt Queue pointer
 * @param element element to be inserted to queue
 * @return status code
 */
 int
 enqueue(QUEUE* pt, int element)
{
    if (isEmpty(pt))
    {
        pt->front = 0;
        pt->rear = 0;
        pt->items[pt->rear] = element;
    }
    else if (isFull(pt))
    {
        return QUEUE_FULL;
    }
    else
    {
        pt->rear = (pt->rear + 1) % pt->maxsize;
        pt->items[pt->rear] = element;
    }
    return 0;
}


/**
 * remove last items from queue
 * @param pt Queue pointer
 * @param removed_value pointer to store removed element
 * @return status code
 */
int
dequeue(QUEUE* pt, int* removed_value)
{
    if (isEmpty(pt))
        return QUEUE_EMPTY;
    else if (pt->front == pt->rear)
    {
        *removed_value = pt->items[pt->front];
        pt->front = -1;
        pt->rear = -1;
    }
    else
    {
        *removed_value = pt->items[pt->front];
        pt->front = (pt->front + 1) % pt->maxsize;
    }
    return 0;
}


/**
 * Display all elements in an array
 * @param pt Queue pointer
 */
void
display(QUEUE* pt)
{
    printf("Queue: ");
    if (!isEmpty(pt))
    {
        int temp = pt->front;
        while (temp != pt->rear)
        {
            printf("%d\t", pt->items[temp]);
            temp = (temp + 1) % pt->maxsize;
        }
        printf("%d\n", pt->items[temp]);
    }
    else
        printf("No elements\n");
}
