/**
 * Stack is a linear data structure which follows a particular order in
 * which the operations are performed. The order may be LIFO
 * (Last In First Out) or FILO (First In Last Out)
*/

#ifndef STACK_H
#define STACK_H

#define DEFAULT_CAPACITY 10

/* StackOverflow Exception is raised when stack is overflow */
namespace Stack {

    class OverflowException : public std::exception {
        const char* what() const throw() {
            return "stack overflow exception";
        }
    };

    /* StackUnderflow Exception is raised when stack is underflow */
    class UnderflowException : public std::exception {
        const char* what() const throw() {
            return "stack underflow exception";
        }
    };


    class Stack {
    private:
        int* items;
        int top;
        int capacity;

    public:
        Stack(int cap = DEFAULT_CAPACITY);
        ~Stack();

        int push(int item);
        int pop();
        int peek();

        int size();
        bool isEmpty();
        bool isFull();

        void display();
    };
}
#endif
