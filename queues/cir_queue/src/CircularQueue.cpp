#include "CircularQueue.hpp"
#include <iostream>

// Constructor to initialize queue properties
CircularQueue::CircularQueue(int size) : front(-1), rear(-1), maxSize(size), currentSize(0) {
    queue.resize(size);  // Resize the vector to the desired size
}

// Enqueue function to add a new element at the rear of the queue
bool CircularQueue::enqueue(const std::string& bigram) {
    if (isFull()) {
        return false;  // Queue is full, cannot add more elements
    }

    // If queue is empty, set both front and rear to 0
    if (front == -1) {
        front = 0;
    }

    // Move rear circularly using modulo operator
    rear = (rear + 1) % maxSize;
    queue[rear] = bigram;
    currentSize++;  // Increase the size of the queue
    return true;
}

// Dequeue function to remove an element from the front of the queue
std::string CircularQueue::dequeue() {
    if (isEmpty()) {
        return "Queue is empty";  // Queue is empty, no elements to remove
    }

    std::string dequeuedBigram = queue[front];
    front = (front + 1) % maxSize;
    currentSize--;  // Decrease the size of the queue

    // If queue becomes empty, reset front and rear
    if (currentSize == 0) {
        front = -1;
        rear = -1;
    }

    return dequeuedBigram;
}

// Function to check if the queue is empty
bool CircularQueue::isEmpty() const {
    return currentSize == 0;
}

// Function to check if the queue is full
bool CircularQueue::isFull() const {
    return currentSize == maxSize;
}

// Function to return the current size of the queue
int CircularQueue::size() const {
    return currentSize;
}

// Function to display all elements in the queue
std::vector<std::string> CircularQueue::displayQueue() const {
    std::vector<std::string> elements;
    if (!isEmpty()) {
        int i = front;
        do {
            elements.push_back(queue[i]);
            i = (i + 1) % maxSize;
        } while (i != (rear + 1) % maxSize);  // Traverse circularly until we reach the rear
    }
    return elements;
}
