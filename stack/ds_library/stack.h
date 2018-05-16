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


#ifndef STACK_H
#define STACK_H


/* Stack Structure */
struct stack
{
    int maxsize;
    int top;
    int *items;
};

typedef struct stack STACK;

/* Stack ADT */
STACK* newStack(int);
int size(STACK*);
int push(STACK*, int);
int peek(STACK*, int*);
int pop(STACK*, int*);
void display(STACK*);

#endif
