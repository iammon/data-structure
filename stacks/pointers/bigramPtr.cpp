#include "bigramPtr.hpp" // Include the header file from the include directory
#include <iostream>
#include <stdexcept> // For exception handling

// Constructor: Initialize stack pointer and stackPtr to point to the base of the array
BigramStack::BigramStack() {
    stackPointer = -1; // Start with an empty stack
    stackPtr = stack;  // Initialize the pointer to the first element of the stack
}

// Push function using pointer arithmetic
int BigramStack::push(const char (&bigram)[2]) {
    if (stackPointer >= 5) { // Overflow check
        throw std::overflow_error("Stack overflow! Cannot push more bigrams.");
    }
    stackPointer++;
    stackPtr = stack + stackPointer; // Move the pointer to the next available position
    (*stackPtr)[0] = bigram[0]; // Assign the first character of the bigram
    (*stackPtr)[1] = bigram[1]; // Assign the second character of the bigram
    return 0; // Success
}

// Pop function using pointer arithmetic
int BigramStack::pop(char (&bigram)[2]) {
    if (stackPointer < 0) { // Underflow check
        throw std::underflow_error("Stack underflow! Cannot pop from an empty stack.");
    }
    stackPtr = stack + stackPointer; // Set the pointer to the current top of the stack
    bigram[0] = (*stackPtr)[0]; // Copy the first character of the bigram
    bigram[1] = (*stackPtr)[1]; // Copy the second character of the bigram
    stackPointer--; // Move the stack pointer back
    return 0; // Success
}

// Status function to get the current position of the stack pointer
int BigramStack::status(int &sp) {
    sp = stackPointer;
    return 0; // Success
}

// Display function to show all elements of the stack using pointer arithmetic
int BigramStack::display() {
    std::cout << "Stack contents: " << std::endl;
    for (int i = 0; i <= stackPointer; i++) {
        char (*currentPtr)[2] = stack + i; // Move the pointer to the ith element
        std::cout << "[" << (*currentPtr)[0] << (*currentPtr)[1] << "] "; // Display the bigram
    }
    std::cout << std::endl;
    std::cout << "Stack pointer is at index: " << stackPointer << std::endl;
    return 0;
}