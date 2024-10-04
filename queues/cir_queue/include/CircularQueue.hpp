#ifndef CIRCULARQUEUE_HPP
#define CIRCULARQUEUE_HPP

#include <vector>
#include <string>

class CircularQueue {
private:
    std::vector<std::string> queue;  // Vector to store queue elements (bigrams or strings)
    int front;                       // Points to the front of the queue
    int rear;                        // Points to the rear of the queue
    int maxSize;                     // Maximum size of the queue
    int currentSize;                 // Current number of elements in the queue

public:
    // Constructor to initialize the queue with a given size
    CircularQueue(int size);

    // Enqueue function to add an element to the rear
    bool enqueue(const std::string& bigram);

    // Dequeue function to remove an element from the front
    std::string dequeue();

    // Function to check if the queue is empty
    bool isEmpty() const;

    // Function to check if the queue is full
    bool isFull() const;

    // Function to get the current size of the queue
    int size() const;

    // Function to display all elements in the queue
    std::vector<std::string> displayQueue() const;
};

#endif

