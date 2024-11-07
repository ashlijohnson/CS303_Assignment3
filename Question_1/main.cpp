#include <iostream>
using namespace std;
#include "queue.h"

int main() {
    Queue<int> q;

    // a) Push 10 integer values into the queue
    for (int i = 1; i <= 10; ++i) {
        q.push(i);
    }

    // b) Display all elements in the queue
    cout << "Elements in the queue: ";
    q.display();

    // c) Move the front element to the rear and display again
    q.move_to_rear();

    cout << "Queue after move_to_rear: ";
    q.display();

    return 0;
}
