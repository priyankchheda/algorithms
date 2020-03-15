#include <iostream>
#include "Stack.hpp"

/**
 * Constructor
 * Create new stack items array in heap memory
 * @param cap maximum capacity of Stack
*/
Stack::Stack(int cap) {
    items = new int[cap];
    capacity = cap;
    top = -1;
}

/**
 * Destructor
 * delete stack items array from heap memory
*/
Stack::~Stack() {
    delete items;
}

/**
 * Get current size of stack
 * @return total number of items currently present in stack
*/
int Stack::size() {
    return top + 1;
}

/**
 * Checks if the stack is empty
 * @return true if stack is empty, else false
*/
bool Stack::isEmpty() {
    return top == -1;
}

/**
 * Checks if the stack is full
 * @return true if stack is full, else false
*/
bool Stack::isFull() {
    return (top + 1) == capacity;
}

/**
 * insert(push) an integer element to stack.
 * @param item to be inserted in stack
 * @return status code 0, if operation is successful.
 *      -1, if stack is full (item not inserted).
*/
int Stack::push(int item) {
    if (isFull())
        return STACK_FULL;
    items[++top] = item;
    return 0;
}

/**
 * remove(pop) an integer element from stack.
 * @return popped value if operation is successful.
 *      -2, if stack is empty (nothing to pop).
*/
int Stack::pop() {
    if (isEmpty())
        return STACK_EMPTY;
    int poppedValue = items[top--];
    return poppedValue;
}

/**
 * Peek top element in stack without removing it.
 * @return top item without removing it.
*/
int Stack::peek() {
    if (isEmpty())
        return STACK_EMPTY;
    int peakValue = items[top];
    return peakValue;
}

/**
 * Display all elements in the stack
*/
void Stack::display() {
    std::cout << "Stack: ";
    if (isEmpty())
        std::cout << "Empty\n";
    else {
        for (int i = 0; i <= top ; i++)
            std::cout << items[i] << " ";
        std::cout << "\n";
    }
}
