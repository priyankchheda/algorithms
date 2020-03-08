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


#ifndef STACK_H
#define STACK_H

#define STACK_FULL -1
#define STACK_EMPTY -2


typedef int (*freeFunction)(void*);

/* Stack Structure */
struct stack
{
    size_t maxsize;
    size_t elem_size;
    int top;
    void *items;
    freeFunction freeFunc;
};

typedef struct stack STACK;

/* Stack ADT */
STACK* create_stack(int capacity, size_t elem_size, freeFunction freeFunc);
int size(STACK *pt);
int is_full(STACK *pt);
int is_empty(STACK *pt);
int push(STACK *pt, void *element);
int peek(STACK *pt, void *result);
int pop(STACK *pt, void *result);
void destroy_stack(STACK *pt);

#endif
