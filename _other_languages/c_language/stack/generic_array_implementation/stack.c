/*
 * Generic Stack (C implementation)
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
#include <string.h>
#include "stack.h"


/**
 * Create New Stack with heap memory
 * @param capacity Initial capacity of Stack
 * @param elem_size size of each element
 * @param freeFunc function to free elements in stack
 * @return pointer to newly created stack
 */
STACK*
create_stack(int capacity, size_t elem_size, freeFunction freeFunc)
{
    STACK* pt = (STACK*)malloc(sizeof(STACK));
    pt->maxsize = capacity;
    pt->top = -1;
    pt->elem_size = elem_size;
    pt->items = malloc(elem_size * capacity);
    pt->freeFunc = freeFunc;

    return pt;
}


/**
 * Destroy Stack by freeing heap memory
 * @param pt Stack pointer
 */
void
destroy_stack(STACK *pt)
{
    if (pt->freeFunc != NULL)
    {
        for (int i = 0; i <= pt->top; i++)
        {
            pt->freeFunc(pt->items + (i * pt->elem_size));
        }
    }

    free(pt->items);
    free(pt);
}


/**
 * Get current size of stack
 * @param pt Stack pointer
 * @return total number of element in stack
 */
int
size(STACK *pt)
{
    return pt->top + 1;
}


/**
 * Check if the stack is Full
 * @param pt Stack pointer
 * @return true if stack is full else false
 */
int
is_full(STACK *pt)
{
    return (pt->top + 1) == pt->maxsize;
}


/**
 * Check if the stack is empty
 * @param pt Stack pointer
 * @return true if stack is empty else false
 */
int
is_empty(STACK *pt)
{
    return pt->top == -1;
}


/**
 * push an integer element to stack
 * @param pt Stack pointer
 * @param element element to be inserted to stack
 * @return status code
 */
int
push(STACK *pt, void* element)
{
    if(is_full(pt))
        return STACK_FULL;

    ++pt->top;
    memcpy( pt->items + (pt->top * pt->elem_size),
            element,
            pt->elem_size);
    return 0;
}


/**
 * peek top element from stack
 * @param pt Stack pointer
 * @param result pointer to store peek element
 * @return status code
 */
int
peek(STACK *pt, void *result)
{
    if (is_empty(pt))
        return STACK_EMPTY;

    memcpy( result,
            pt->items + (pt->top * pt->elem_size),
            pt->elem_size);
    return 0;
}


/**
 * pop top element from stack
 * @param pt Stack pointer
 * @param popped_value pointer to store popped integer
 * @return status code
 */
int
pop(STACK *pt, void* result)
{
    if (is_empty(pt))
        return STACK_EMPTY;

    memcpy( result,
            pt->items + (pt->top * pt->elem_size),
            pt->elem_size);
    pt->top--;
    return 0;
}
