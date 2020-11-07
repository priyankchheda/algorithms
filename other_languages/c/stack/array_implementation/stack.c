/*
 * Stack (C implementation)
 * Author: Priyank Chheda
 *         E: p.chheda29@gmail.com
 *         W: https://github.com/x899
 *
 * Stack is a linear data structure which follows a particular order in which
 * the operations are performed. The order may be LIFO(Last In First Out) or
 * FILO(First In Last Out).
 */

#include <stdio.h>
#include <stdlib.h>
#include "stack.h"


/**
 * Create New Stack with heap memory
 * @param capacity Initial capacity of Stack
 * @return pointer to newly created stack
 */
STACK* newStack(int capacity)
{
    STACK* pt = (STACK*)malloc(sizeof(STACK));

    pt->maxsize = capacity;
    pt->top = -1;
    pt->items = (int*)malloc(sizeof(int) * capacity);

    return pt;
}


/**
 * Get current size of stack
 * @param pt Stack pointer
 * @return total number of element in stack
 */
int size(STACK *pt)
{
    return pt->top + 1;
}


/**
 * Check if the stack is Full
 * @param pt Stack pointer
 * @return true if stack is full else false
 */
static int isFull(STACK *pt)
{
    return (pt->top + 1) == pt->maxsize;
}


/**
 * Check if the stack is empty
 * @param pt Stack pointer
 * @return true if stack is empty else false
 */
static int isEmpty(STACK *pt)
{
    return pt->top == -1;
}


/**
 * push an integer element to stack
 * @param pt Stack pointer
 * @param element element to be inserted to stack
 * @return status code
 */
int push(STACK *pt, int element)
{
    if (isFull(pt))
        return STACK_FULL;

    pt->items[++pt->top] = element;
    return 0;
}


/**
 * peek top element from stack
 * @param pt Stack pointer
 * @param result pointer to store peek element
 * @return status code
 */
int peek(STACK *pt, int* result)
{
    if (isEmpty(pt))
        return STACK_EMPTY;

    *result = pt->items[pt->top];
    return 0;
}


/**
 * pop top element from stack
 * @param pt Stack pointer
 * @param popped_value pointer to store popped integer
 * @return status code
 */
int pop(STACK *pt, int* popped_value)
{
    if (isEmpty(pt))
        return STACK_EMPTY;

    *popped_value = pt->items[pt->top];
    pt->top--;
    return 0;
}


/**
 * Display all elements in an array
 * @param pt Stack pointer
 */
void display(STACK *pt)
{
    printf("Stack: ");
    if (isEmpty(pt))
    {
        printf("Empty\n");
        return;
    }
    for (int i = 0; i <= pt->top; i++)
        printf("%d ", pt->items[i]);
    printf("\n");
}

