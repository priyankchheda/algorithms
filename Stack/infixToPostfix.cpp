/**
 * Infix to postfix conversion
 * CMD: g++ -std=c++14 -Wall infixToPostfix.cpp
 */

#include <iostream>
#include "Stack/Stack.hpp"

int precedence(char c);
std::string infixToPostfix(std::string infix);

/* main driver function */
int main()
{
    std::string exp = "a+b*(c^d-e)^(f+g*h)-i";
    std::string postfix = infixToPostfix(exp);
    std::cout << postfix << std::endl;
    return 0;
}

/**
 * precedence returns precedence value of an operator
 * @param c operator whose precedence value is needed
 * @returns precedence value of operator c
 */
int precedence(char c)
{
    if (c == '^')
        return 3;
    else if (c == '*' || c == '/')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}

/**
 * infixToPostfix converts infix expression into postfix expression
 * @param infix infix expression that needs to be converted
 * @returns postfix expression
 */
std::string infixToPostfix(std::string infix)
{
    Stack::Stack<char> stack;
    std::string postfix;
    int infixLen = infix.length();

    for (int i = 0; i < infixLen; i++) {

        // if character is an operand (alphabet)
        if ((infix[i] >= 'a' && infix[i] <= 'z') ||
            (infix[i] >= 'A' && infix[i] <= 'Z')) {
            postfix += infix[i];
        }

        //if character is opening bracket
        else if (infix[i] == '(') {
            stack.push(infix[i]);
        }

        //if character is closing bracket
        else if (infix[i] == ')') {
            while (!stack.isEmpty() && stack.peek() != '(')
                postfix += stack.pop();
            if (stack.peek() == '(')
                stack.pop();
        }

        // if character is an operator
        else {
            while (!stack.isEmpty() &&
                precedence(infix[i]) <= precedence(stack.peek())) {
                postfix += stack.pop();
            }
            stack.push(infix[i]);
        }
    }

    // pop and append everything to postfix string till stack is empty
    while (!stack.isEmpty())
        postfix += stack.pop();

    return postfix;
}
