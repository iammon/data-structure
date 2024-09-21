#include "myClass.hpp"
#include <iostream>
#include <stdexcept> // For standard exceptions

// Constructor to initialize stackPointer to -1, indicating the stack is empty
BigramStack::BigramStack() {
    stackPointer = -1;
}
// Push function to add a bigram to the stack. It returns -1 if the stack is full (overflow).
int BigramStack::push(const char (&bigram)[2]) {
    if (stackPointer >= 5) { // Check if the stack is already full (overflow condition)
        throw std::overflow_error("Stack overflow! Cannot push more bigrams.");
    }
    stackPointer++; // Increment the stack pointer to the next position
    stack[stackPointer][0] = bigram[0]; // Assign the first character of the bigram
    stack[stackPointer][1] = bigram[1]; // Assign the second character of the bigram
    return 0; // Return 0 to indicate success
}

// Pop function to remove a bigram from the stack. It returns -1 if the stack is empty (underflow).
int BigramStack::pop(char (&bigram)[2]) {
    if (stackPointer < 0) { // Check if the stack is empty (underflow condition)
        throw std::underflow_error("Stack underflow! Cannot pop from an empty stack.");
    }
    // Combine 26&27!!! Pointer
    bigram[0] = stack[stackPointer][0]; // Get the first character of the bigram from the top
    bigram[1] = stack[stackPointer][1]; // Get the second character of the bigram from the top
    stackPointer--; // Decrement the stack pointer after popping
    return 0; // Return 0 to indicate success
}

// Status function to retrieve the current value of the stack pointer by reference
int BigramStack::status(int &sp) {
    sp = stackPointer; // Assign the current stack pointer to the reference variable
    return 0; // Return 0 to indicate success
}

// Display function to show the contents of the stack and the stack pointer's position
int BigramStack::display() {
    if (stackPointer == -1) {
        std::cout << "Stack is empty." << std::endl;
        return -1;
    }
    else {
        std::cout << "Stack contents: " << std::endl;
        for (int i = 0; i <= stackPointer; i++) {
            std::cout << "[" << stack[i][0] << stack[i][1] << "] "; // Display each bigram in the stack
        }
        std::cout << std::endl;
        std::cout << "Stack pointer is at index: " << stackPointer << std::endl; // Show stack pointer's position
        return 0;
    }
}