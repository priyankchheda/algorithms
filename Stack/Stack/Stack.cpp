#include <iostream>
#include "Stack.hpp"

/**
 * Constructor
 * Create new stack items array in heap memory
 * @param cap maximum capacity of Stack
*/
Stack::Stack::Stack(int cap) {
    items = new int[cap];
    capacity = cap;
    top = -1;
}

/**
 * Destructor
 * delete stack items array from heap memory
*/
Stack::Stack::~Stack() {
    delete items;
}

/**
 * Get current size of stack
 * @return total number of items currently present in stack
*/
int Stack::Stack::size() {
    return top + 1;
}

/**
 * Checks if the stack is empty
 * @return true if stack is empty, else false
*/
bool Stack::Stack::isEmpty() {
    return top == -1;
}

/**
 * Checks if the stack is full
 * @return true if stack is full, else false
*/
bool Stack::Stack::isFull() {
    return (top + 1) == capacity;
}

/**
 * insert(push) an integer element to stack.
 * @param item to be inserted in stack
 * @return status code 0, if operation is successful.
 * @throws Stack::Exception::Overflow exception if stack is full
 *      (item not inserted).
*/
int Stack::Stack::push(int item) {
    if (isFull())
        throw OverflowException();
    items[++top] = item;
    return 0;
}

/**
 * remove(pop) an integer element from stack.
 * @return popped value if operation is successful.
 * @throws UnderflowException exception if stack is empty (nothing to pop).
*/
int Stack::Stack::pop() {
    if (Stack::isEmpty())
        throw UnderflowException();
    int poppedValue = items[top--];
    return poppedValue;
}

/**
 * Peek top element in stack without removing it.
 * @return top item without removing it.
 * @throws UnderflowException exception if stack is empty (nothing to peek).
*/
int Stack::Stack::peek() {
    if (Stack::isEmpty())
        throw UnderflowException();
    int peakValue = items[top];
    return peakValue;
}

/**
 * Display all elements in the stack
*/
void Stack::Stack::display() {
    std::cout << "Stack: ";
    if (Stack::isEmpty())
        std::cout << "Empty\n";
    else {
        for (int i = 0; i <= top ; i++)
            std::cout << items[i] << " ";
        std::cout << "\n";
    }
}
