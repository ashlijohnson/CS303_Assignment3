// Queue.cpp
#include "queue.h"

// Constructor
template <typename T>
Queue<T>::Queue() : frontNode(nullptr), rearNode(nullptr), count(0) {}

// Destructor to free up memory
template <typename T>
Queue<T>::~Queue() {
    while (!empty()) {
        pop();
    }
}

// Push an element to the rear of the queue
template <typename T>
void Queue<T>::push(const T& value) {
    Node* newNode = new Node(value);
    if (empty()) {
        frontNode = rearNode = newNode;
    } else {
        rearNode->next = newNode;
        rearNode = newNode;
    }
    count++;
}

// Pop an element from the front of the queue
template <typename T>
void Queue<T>::pop() {
    if (empty()) return;
    Node* temp = frontNode;
    frontNode = frontNode->next;
    delete temp;
    count--;
    if (count == 0) rearNode = nullptr; 
}

// Get the front element of the queue
template <typename T>
T Queue<T>::front() const {
    if (!empty()) {
        return frontNode->data;
    }
    throw out_of_range("Queue is empty");
}

// Return the size of the queue
template <typename T>
int Queue<T>::size() const {
    return count;
}

// Check if the queue is empty
template <typename T>
bool Queue<T>::empty() const {
    return count == 0;
}

// Move the front element to the rear of the queue
template <typename T>
void Queue<T>::move_to_rear() {
    if (size() <= 1) return; 

    T frontVal = front();
    pop();            
    push(frontVal);    
}

// Display all elements in the queue using front, pop, push
template <typename T>
void Queue<T>::display() {
    Queue<T> tempQueue;  

    // Use a loop to pop each element from the original queue, display it,
    // and immediately push it into the temporary queue
    while (!empty()) {
        T frontElement = front();   
        cout << frontElement << " "; 
        pop();                      
        tempQueue.push(frontElement); 
    }
    cout << endl;

    // Restore the original queue by pushing elements back from tempQueue
    while (!tempQueue.empty()) {
        push(tempQueue.front());
        tempQueue.pop();
    }
}
// Sort the queue using insertion sort
template <typename T>
void Queue<T>::sort() {
    if (empty() || size() == 1) return;

    Queue<T> sortedQueue; 

    while (!empty()) {
        T currElement = front();
        pop();

        // Insert currElement in sorted order into sortedQueue
        int sortedSize = sortedQueue.size();
        bool inserted = false;

        for (int i = 0; i < sortedSize; ++i) {
            T sortedFront = sortedQueue.front();
            sortedQueue.pop();

            if (!inserted && currElement < sortedFront) {
                sortedQueue.push(currElement);
                inserted = true;
            }

            sortedQueue.push(sortedFront);
        }

        // If the element is larger than all elements in sortedQueue, push it to the end
        if (!inserted) {
            sortedQueue.push(currElement);
        }
    }

    // Move elements back to the original queue
    while (!sortedQueue.empty()) {
        push(sortedQueue.front());
        sortedQueue.pop();
    }
}


// Explicit instantiation for integer queue
template class Queue<int>;
