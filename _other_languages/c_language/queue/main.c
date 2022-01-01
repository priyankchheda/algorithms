/* Queue Test Function */

#include <stdio.h>
#include "queue.h"


int
main(void)
{
    QUEUE* pt = newQueue(5);

    int ret = -1;
    ret = enqueue(pt, 1);
    if (ret == 0)
        printf("Successfully inserted to Queue\n");
    else
        printf("Unable to insert element. Error Code: %d\n", ret);

    display(pt);

    int removed_value;
    ret = dequeue(pt, &removed_value);
    if (ret == 0)
        printf("Removed Element is %d\n", removed_value);
    else
        printf("Unable to remove element. Error Code: %d\n", ret);

    display(pt);

    ret = dequeue(pt, &removed_value);
    if (ret == 0)
        printf("Removed Element is %d\n", removed_value);
    else
        printf("Unable to remove element. Error Code: %d\n", ret);

    display(pt);
}
