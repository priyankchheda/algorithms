/**
 * Minimum number of bracket reversals needed to make an expression balanced
 * Given an expression with only '}' and '{'. The expression may not be
 * balanced. Find minimum number of bracket reversals to make the expression
 * balanced.
 * URL: https://www.geeksforgeeks.org/minimum-number-of-bracket-reversals-
 *      needed-to-make-an-expression-balanced/
 * CMD: g++ -Wall -std=c++14 bracketReversals.cpp
*/

#include <iostream>
#include "Stack/Stack.hpp"

/* function declarations */
int countMinReversals(std::string expression);

/* main driver function */
int main()
{
    std::string expression = "}{{}}{{{";
    std::cout << countMinReversals(expression) << "\n";
    return 0;
}

int countMinReversals(std::string expression)
{
    int len = expression.length();

    // length of expression must be even to make it balanced by using reversals.
    if (len % 2) return -1;

    // After this loop, stack contains unbalanced part of expression, i.e.,
    //expression of theform "}}..}{{..{"
    Stack::Stack<char> stack;
    for (char c: expression) {
        if (c == '}' && !stack.isEmpty()) {
            if (stack.peek()=='{')
                stack.pop();
            else stack.push(c);
        } else stack.push(c);
    }

    // Length of the reduced expression
    // red_len = (m+n)
    int red_len = stack.size();

    // count opening brackets at the end of stack
    int n = 0;
    while (!stack.isEmpty() && stack.peek() == '{') {
        stack.pop();
        n++;
    }

    // return ceil(m/2) + ceil(n/2) which is actually equal to (m+n)/2 + n%2
    // when m+n is even.
    return (red_len / 2 + n % 2);
}