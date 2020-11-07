/*
Tracking current Maximum Element in a stack
Given a Stack, keep track of the maximum value in it.

- Create an auxiliary stack, say ‘maxStack’ to keep the track of maximum element
- Push the first element to both dataStack and the maxStack.
- Now from the second element, push the element to the main stack. Compare the element with the top element of the track stack, if the current element is greater than top of maxStack then push the current element to maxStack otherwise push the top element of maxStack again into it.
- If we pop an element from the main stack, then pop an element from the maxStack as well.
- Now to compute the maximum of the main stack at any point, we can simply print the top element of Track stack.

CMD: g++ -std=c++14 -Wall trackingCurrentMax.cpp
*/

#include <iostream>
#include "Stack/Stack.hpp"

class StackWithMax {
private:
    Stack::Stack<int> dataStack;
    Stack::Stack<int> maxStack; // storing the max element in auxiliary stack
public:
    void push(int item) {
        dataStack.push(item);
        if (!maxStack.isEmpty()) {
            if (item >= maxStack.peek())
                maxStack.push(item);
            else maxStack.push(maxStack.peek());
        } else maxStack.push(item);
    }

    int pop() {
        maxStack.pop();
        return dataStack.pop();
    }

    int getMax() { return maxStack.peek(); }

    // methods which are same as original stack methods
    int peek() { return dataStack.peek(); }
    int size() { return dataStack.size(); }
    bool isEmpty() { return dataStack.isEmpty(); }
    bool isFull() { return dataStack.isFull(); }
    void display() { dataStack.display(); }
};

int main() {
    StackWithMax s;
    s.push(20);
    std::cout << s.getMax() << std::endl;
    s.push(10);
    std::cout << s.getMax() << std::endl;
    s.push(50);
    std::cout << s.getMax() << std::endl;
    s.pop();
    std::cout << s.getMax() << std::endl;
    return 0;
}