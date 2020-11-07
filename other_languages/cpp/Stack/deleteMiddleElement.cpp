/**
 * Delete middle element of a stack without using any additional
 * data structure.
 * URL: https://www.geeksforgeeks.org/delete-middle-element-stack/
 * CMD: g++ -std=c++14 -Wall deleteMiddleElement.cpp
*/

#include <iostream>
#include "Stack/Stack.hpp"

/* function declarations */
void deleteMiddle(Stack::Stack<int> &stack, int n, int curr=0);

/* main driver function */
int main()
{
    Stack::Stack<int> stack;
    for (int i = 1; i < 11; i++)
        stack.push(i);

    stack.display();
    deleteMiddle(stack, stack.size());
    std::cout << "after deleting middle element\n";
    stack.display();
}

void deleteMiddle(Stack::Stack<int> &stack, int n, int curr)
{
    // if stack is empty or all items are traversed
    if (stack.isEmpty() || curr == n)
        return;

    // remove current item
    int x = stack.pop();

    // remove other items
    deleteMiddle(stack, n, curr+1);

    // put all items back except middle
    if (curr != n/2)
        stack.push(x);
}
