/**
 * Reverse a Queue
 * Input:  Q = [10, 20, 30, 40, 50, 60, 70, 80, 90, 100]
 * Output: Q = [100, 90, 80, 70, 60, 50, 40, 30, 20, 10]
 *
 * Input:  [1, 2, 3, 4, 5]
 * Output: [5, 4, 3, 2, 1]
*/

#include <iostream>
#include "../Stack/Stack/Stack.hpp"
#include "Queue/Queue.hpp"

/**
 * Reversing a queue using stack.
 * @param queue reference to queue object
*/
void ReverseQueue(Queue::Queue<int> &queue)
{
    Stack::Stack<int> stack;
    while (!queue.isEmpty())
        stack.push(queue.dequeue());
    while (!stack.isEmpty())
        queue.enqueue(stack.pop());
}

/**
 * Reversing a queue using recursive approach
 * @param queue reference to queue object
*/
void ReverseQueueRecursive(Queue::Queue<int> &queue)
{
    if (queue.isEmpty())
        return;
    int data = queue.dequeue();
    ReverseQueueRecursive(queue);
    queue.enqueue(data);
}

/* Main Driver Function */
int main()
{
    Queue::Queue<int> queue;
    queue.enqueue(1);
    queue.enqueue(2);
    queue.enqueue(3);
    queue.enqueue(4);
    queue.enqueue(5);

    std::cout << "Original ";
    queue.display();

    ReverseQueue(queue);

    std::cout << "Reversed ";
    queue.display();

    ReverseQueueRecursive(queue);

    std::cout << "Recursive ";
    queue.display();
    return 0;
}