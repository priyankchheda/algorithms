/**
 * Check for balanced parentheses in an expression
 * CMD: g++ -std=c++14 -Wall balancedParanthesis.cpp
 */

#include <iostream>
#include "Stack/Stack.hpp"

bool areParanthesisBalanced(std::string);

/* main driver function */
int main()
{
    std::string exp = "{a*(a+b)} + [4+5]";
    bool result = areParanthesisBalanced(exp);
    if (result) std::cout << "balanced\n";
    else std::cout << "not balanced\n";
    return 0;
}

/**
 * check if the paranthesis in given expression exp is balanced or not.
 * @param exp expression to be checked.
 * @returns true if balance, else false
*/
bool areParanthesisBalanced(std::string exp)
{
    Stack::Stack<char> stack(10);
    int expLen = exp.length();

    for (int i = 0; i < expLen; i++) {
        // if character is any of the opening braces, push it to stack
        if (exp[i] == '(' || exp[i] == '{' || exp[i] == '[') {
            try {
                stack.push(exp[i]);
            } catch (Stack::OverflowException &e) {
                std::cout << "Stack Overflow Exception.\n";
                std::cout << "Can't do anything. Rerun with more stack space\n";
                throw;
            }

        // if character is any of the closing braces and peek of stack is
        // corresponding opening braces, pop the opening brace from stack
        // ignore every other character
        } else if (exp[i] == ')' || exp[i] == '}' || exp[i] == ']') {
            try {
                if ((exp[i] == ')' && stack.peek() == '(') ||
                    (exp[i] == '}' && stack.peek() == '{') ||
                    (exp[i] == ']' && stack.peek() == '['))
                    stack.pop();
                else return false;
            } catch (Stack::UnderflowException &e) {
                std::cout << "underflow exception thrown\n";
                return false;
            }
        }
    }

    // after parsing all the characters in exp, expression is unbalanced
    // if stack is not empty.
    if (!stack.isEmpty())
        return false;
    return true;
}