// CircularQueue.cpp
// Source file containing the implementation of the CircularQueue class
#include "CircularQueue.hpp"
#include <iostream>

using namespace std;

// Constructor: initializes the circular queue with the given capacity
// Sets front and rear to -1 indicating the queue is empty
CircularQueue::CircularQueue(int c) {
    capacity = c;               // Set the capacity of the queue
    queue = new int[capacity];   // Dynamically allocate memory for the queue array
    front = rear = -1;           // Initialize front and rear to -1, meaning empty queue
    size = 0;                    // Initially, the size of the queue is 0
}

// Destructor: releases the dynamically allocated memory for the queue
CircularQueue::~CircularQueue() {
    delete[] queue;  // Free the dynamically allocated array
}

// Enqueue: inserts an element into the rear of the queue
// Returns true if successful, false if the queue is full
bool CircularQueue::enqueue(int data) {
    // Check if the queue is full
    if ((rear + 1) % capacity == front) {
        cout << "Queue is full!" << endl;
        return false;  // Return false if the queue is full
    }

    // If the queue is empty, set front to 0 (first element inserted)
    if (front == -1) front = 0;

    // Move rear to the next position in a circular manner
    rear = (rear + 1) % capacity;

    // Insert the new element at the rear position
    queue[rear] = data;

    // Increase the size of the queue
    size++;
    return true;  // Return true if enqueue was successful
}

// Dequeue: removes an element from the front of the queue
// Returns true if successful, false if the queue is empty
bool CircularQueue::dequeue() {
    // Check if the queue is empty
    if (front == -1) {
        cout << "Queue is empty!" << endl;
        return false;  // Return false if the queue is empty
    }

    // Print the dequeued element (optional)
    cout << "Dequeued: " << queue[front] << endl;

    // If the queue becomes empty after this dequeue operation
    if (front == rear) {
        front = rear = -1;  // Reset front and rear to -1 indicating an empty queue
    } else {
        // Move front to the next position in a circular manner
        front = (front + 1) % capacity;
    }

    // Decrease the size of the queue
    size--;
    return true;  // Return true if dequeue was successful
}

// isEmpty: checks if the queue is empty
bool CircularQueue::isEmpty() const {
    return front == -1;  // Queue is empty if front is -1
}

// isFull: checks if the queue is full
bool CircularQueue::isFull() const {
    return (rear + 1) % capacity == front;  // Queue is full if rear+1 equals front in a circular manner
}

// Display: prints the elements of the queue from front to rear
void CircularQueue::display() const {
    // Check if the queue is empty
    if (front == -1) {
        cout << "Queue is empty!" << endl;
        return;
    }

    // Print the elements in a circular manner
    cout << "Queue elements: ";
    for (int i = front; i != rear; i = (i + 1) % capacity) {
        cout << queue[i] << " ";  // Print each element from front to rear
    }
    cout << queue[rear] << endl;  // Print the last element at rear
}
