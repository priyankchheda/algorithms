/**
 * Given a queue with random elements, we need to sort it. We are not allowed
 * to use extra space. The operations allowed on queue are:
 * enqueue(): Adds an item to rear of queue
 * dequeue(): Removes an item from front of queue.
 * isEmpty(): Checks if a queue is empty.
 *
 * URL: https://www.geeksforgeeks.org/sorting-queue-without-extra-space/
 * CMD: g++ -Wall -std=c++14 SortQueueWithoutExtraSpace.cpp
*/
#include <iostream>
#include <limits>
#include "Queue/Queue.hpp"

/* Function Declarations */
int getMinIndex(Queue::Queue<int>& queue, int sortedIndex);
void insertMinToRear(Queue::Queue<int>& queue, int minIndex);
void sortQueue(Queue::Queue<int>& queue);

/* Main Operational Function */
int main()
{
    Queue::Queue<int> queue;
    queue.enqueue(11);
    queue.enqueue(5);
    queue.enqueue(4);
    queue.enqueue(21);

    std::cout << "Original ";
    queue.display();

    sortQueue(queue);

    std::cout << "Sorted ";
    queue.display();

    return 0;
}

void sortQueue(Queue::Queue<int>& queue)
{
    int n = queue.size();
    for (int i = 1; i <= n; i++) {
        int minIndex = getMinIndex(queue, i);
        insertMinToRear(queue, minIndex);
    }
}

int getMinIndex(Queue::Queue<int>& queue, int sortedIndex)
{
    int minValue = INT_MAX;
    int minIndex = -1;
    int n = queue.size();

    for (int i = 0; i < n; i++) {
        int value = queue.dequeue();
        if (value <= minValue && i <= (n-sortedIndex)) {
            minValue = value;
            minIndex = i;
        }
        queue.enqueue(value);
    }
    return minIndex;
}

void insertMinToRear(Queue::Queue<int>& queue, int minIndex)
{
    int n = queue.size();
    int minValue;
    for (int i = 0; i < n; i++) {
        int value = queue.dequeue();
        if (i == minIndex)
            minValue = value;
        else
            queue.enqueue(value);
    }
    queue.enqueue(minValue);
}
