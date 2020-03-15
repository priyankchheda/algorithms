#include <iostream>
#include "Queue.hpp"

int main()
{
    Queue q(5);
    q.display();
    q.enqueue(1);
    q.display();
    q.enqueue(2);
    q.display();
    q.enqueue(3);
    q.display();
    q.enqueue(4);
    q.display();
    q.enqueue(5);
    q.display();
    q.enqueue(6);
    q.display();
    q.enqueue(7);
    q.display();
    return 0;
}
