/* Stack Test Function */

#include <stdio.h>
#include "stack.h"


int
main(void)
{
    STACK* pt = newStack(5);
    push(pt, 1);

    display(pt);
    printf("Size of Stack: %d\n", size(pt));

    int peek_value;
    int peek_return = peek(pt, &peek_value);
    if ( peek_return == 0)
        printf("Top element is %d\n", peek_value);
    else
        printf("Unable to get peek value. Error Code: %d\n", peek_return);
    
    int pop_value;
    int pop_return = pop(pt, &pop_value);
    if (pop_return == 0)
        printf("Popped value is %d\n", pop_value);
    else
        printf("Unable to get popped value. Error Code: %d\n", pop_return);

    
    int push_return = push(pt, 2);
    if (push_return == 0)
        printf("Successfully pushed to stack\n");
    else
        printf("Unable to push element.Error Code: %d\n", push_return);

    display(pt);
    printf("Size of Stack: %d\n", size(pt));
    return 0;
}
