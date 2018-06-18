/* Stack Test Function */

#include <stdio.h>
#include "stack.h"


void display (STACK *pt);


/* Main Function */
int
main()
{
    STACK *pt = create_stack(5, sizeof(float), NULL);
    printf("Size of Stack: %d\n", size(pt));
    display(pt);
    
    float element = 1.45;
    push(pt, (void*)&element);
    
    element = 5.76;
    push(pt, (void*)&element);
    printf("Size of Stack: %d\n", size(pt));
    display(pt);

    float peek_value;
    int peek_return = peek(pt, (void*)&peek_value);
    if ( peek_return == 0)
        printf("Top element is %.2f\n", peek_value);
    else
        printf("Unable to get peek value. Error Code: %d\n", peek_return);
    
    float pop_value;
    int pop_return = pop(pt, (void*)&pop_value);
    if (pop_return == 0)
        printf("Popped value is %.2f\n", pop_value);
    else
        printf("Unable to get popped value. Error Code: %d\n", pop_return);
    display(pt);

    element = 78.12;
    int push_return = push(pt, (void*)&element);
    if (push_return == 0)
        printf("Successfully pushed to stack\n");
    else
        printf("Unable to push element.Error Code: %d\n", push_return);

    display(pt);
    printf("Size of Stack: %d\n", size(pt));

    destroy_stack(pt);
    return 0;
}


/**
 * Display Stack Element
 * @param pt Stack pointer
 */
void
display(STACK *pt)
{
    printf("Stack: ");
    if (is_empty(pt))
    {
        printf("Empty\n");
        return;
    }
    for (size_t i = 0; i <= pt->top; i++)
        printf("%.2f ", *(float*)(pt->items + (i * sizeof(float))));
    printf("\n");
}

