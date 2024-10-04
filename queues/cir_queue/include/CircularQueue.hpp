// CircularQueue.hpp
// Header file for the CircularQueue class
#ifndef CIRCULARQUEUE_HPP
#define CIRCULARQUEUE_HPP

class CircularQueue {
private:
    int* queue;  // Pointer to the array that holds queue elements
    int front;   // Index of the front element (dequeue position)
    int rear;    // Index of the rear element (enqueue position)
    int size;    // Current size of the queue (number of elements)
    int capacity; // Maximum capacity of the queue

public:
    // Constructor to initialize the queue with a given capacity
    CircularQueue(int c);

    // Destructor to clean up dynamically allocated memory
    ~CircularQueue();

    // Function to insert an element into the queue (enqueue operation)
    bool enqueue(int data);

    // Function to remove an element from the queue (dequeue operation)
    bool dequeue();

    // Function to check if the queue is empty
    bool isEmpty() const;

    // Function to check if the queue is full
    bool isFull() const;

    // Function to display all elements in the queue
    bool display() const;
};

#endif // CIRCULARQUEUE_HPP
