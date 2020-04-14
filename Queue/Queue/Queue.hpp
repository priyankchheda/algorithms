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

namespace Queue
{

/**
 * OverflowException is raised when you are trying to insert
 * element in completely filled queue.
 */
class OverflowException : public std::exception
{
    const char *what() const throw()
    {
        return "queue overflow exception";
    }
};

/**
 * UnderflowException is raised when you are trying to access
 * element from empty queue.
 */
class UnderflowException : public std::exception
{
    const char *what() const throw()
    {
        return "queue underflow exception";
    }
};

template <typename T>
class Queue
{
private:
    T *items;
    int front;
    int rear;
    int capacity;
    int item_count;

public:
    Queue(int cap = DEFAULT_CAPACITY);
    ~Queue();

    int enqueue(T item);
    T dequeue();
    T peek();

    int size();
    bool isEmpty();
    bool isFull();

    void display();
};

/**
 * Constructor
 * Create new Queue items array in heap memory
 * @param cap maximum capacity of Queue
*/
template <typename T>
Queue<T>::Queue(int cap)
{
    items = new int[cap];
    capacity = cap;
    front = 0;
    rear = -1;
    item_count = 0;
}

/**
 * Destructor
 * delete queue items array from heap memory
*/
template <typename T>
Queue<T>::~Queue()
{
    delete items;
}

/**
 * enqueue(push) an element to queue.
 * @param item to be enqueued in queue
 * @return status code 0, if operation is successful.
 * @throw Queue::OverflowException if queue is full
 *      (item not enqueued).
*/
template <typename T>
int Queue<T>::enqueue(T element)
{
    if (isFull())
        throw OverflowException();

    rear = (rear + 1) % capacity;
    items[rear] = element;
    item_count++;
    return 0;
}

/**
 * dequeue(pop) an element from queue.
 * @return dequeued value if operation is successful.
 * @throw Queue::UnderflowException if queue is empty
 *      (nothing to pop).
*/
template <typename T>
T Queue<T>::dequeue()
{
    if (isEmpty())
        throw UnderflowException();

    int removedvalue = items[front];
    front = (front + 1) % capacity;
    item_count--;
    return removedvalue;
}

/**
 * Peek top element in queue without removing it.
 * @return top item without removing it.
 * @throw Queue::UnderflowException exception if queue is empty
 *      (nothing to peek).
*/
template <typename T>
T Queue<T>::peek()
{
    if (isEmpty())
        throw UnderflowException();

    return items[front];
}

/**
 * Get current size of queue
 * @return total number of items currently present in queue
*/
template <typename T>
int Queue<T>::size()
{
    return item_count;
}

/**
 * Checks if the queue is full
 * @return true if queue is full, else false
*/
template <typename T>
bool Queue<T>::isFull()
{
    return size() == capacity;
}

/**
 * Checks if the queue is empty
 * @return true if queue is empty, else false
*/
template <typename T>
bool Queue<T>::isEmpty()
{
    return size() == 0;
}

/**
 * Display all elements in the queue
*/
template <typename T>
void Queue<T>::display()
{
    std::cout << "Queue: ";
    if (!isEmpty())
    {
        int temp = front;
        while (temp != rear)
        {
            std::cout << items[temp] << " ";
            temp = (temp + 1) % capacity;
        }
        std::cout << items[temp] << "\n";
    }
    else
        std::cout << "Empty\n";
}
} // namespace Queue

#endif
