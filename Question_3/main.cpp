#include <iostream>
using namespace std;
#include "queue.h"

int main() {

   Queue<int> q;
  
  // Add elements to the queue
  q.push(5);
  q.push(3);
  q.push(8);
  q.push(1);
  q.push(7);

  cout << "Original queue: ";
  q.display();

  // Sort the queue
  q.sort();

  cout << "Sorted queue: ";
  q.display();
  
    return 0;
}
