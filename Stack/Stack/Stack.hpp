/**
 * Stack is a linear data structure which follows a particular order in
 * which the operations are performed. The order may be LIFO
 * (Last In First Out) or FILO (First In Last Out)
*/

#ifndef STACK_H
#define STACK_H

#define DEFAULT_CAPACITY 10

namespace Stack {

    /**
     * OverflowException is raised when you are trying to insert
     * element in completely filled stack.
     */
    class OverflowException : public std::exception {
        const char* what() const throw() {
            return "stack overflow exception";
        }
    };

    /**
     * UnderflowException is raised when you are trying to access
     * element from empty stack.
     */
    class UnderflowException : public std::exception {
        const char* what() const throw() {
            return "stack underflow exception";
        }
    };

    template <typename T>
    class Stack {
    private:
        T* items;
        int top;
        int capacity;

    public:
        Stack(int cap = DEFAULT_CAPACITY);
        ~Stack();

        int push(T item);
        T pop();
        T peek();

        int size();
        bool isEmpty();
        bool isFull();

        void display();
    };

    /**
     * Constructor
     * Create new stack items array in heap memory
     * @param cap maximum capacity of Stack
    */
    template <typename T>
    Stack<T>::Stack(int cap) {
        items = new int[cap];
        capacity = cap;
        top = -1;
    }

    /**
     * Destructor
     * delete stack items array from heap memory
    */
    template <typename T>
    Stack<T>::~Stack() {
        delete items;
    }

    /**
     * insert(push) an element to stack.
     * @param item to be inserted in stack
     * @return status code 0, if operation is successful.
     * @throws Stack::OverflowException if stack is full
     *      (item not inserted).
    */
    template <typename T>
    int Stack<T>::push(T item) {
        if (isFull())
            throw OverflowException();
        items[++top] = item;
        return 0;
    }

    /**
     * remove(pop) an integer element from stack.
     * @return popped value if operation is successful.
     * @throws Stack::UnderflowException if stack is empty
     *      (nothing to pop).
    */
    template <typename T>
    T Stack<T>::pop() {
        if (isEmpty())
            throw UnderflowException();
        T poppedValue = items[top--];
        return poppedValue;
    }

    /**
     * Peek top element in stack without removing it.
     * @return top item without removing it.
     * @throws UnderflowException exception if stack is empty
     *      (nothing to peek).
    */
    template <typename T>
    T Stack<T>::peek() {
        if (isEmpty())
            throw UnderflowException();
        T peakValue = items[top];
        return peakValue;
    }

    /**
     * Get current size of stack
     * @return total number of items currently present in stack
    */
    template <typename T>
    int Stack<T>::size() {
        return top + 1;
    }

    /**
     * Checks if the stack is empty
     * @return true if stack is empty, else false
    */
    template <typename T>
    bool Stack<T>::isEmpty() {
        return top == -1;
    }

    /**
     * Checks if the stack is full
     * @return true if stack is full, else false
    */
    template <typename T>
    bool Stack<T>::isFull() {
        return (top + 1) == capacity;
    }

    /**
     * Display all elements in the stack
    */
    template <typename T>
    void Stack<T>::display() {
        std::cout << "Stack: ";
        if (isEmpty())
            std::cout << "Empty\n";
        else {
            for (int i = 0; i <= top ; i++)
                std::cout << items[i] << " ";
            std::cout << "\n";
        }
    }
}

#endif