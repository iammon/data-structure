#ifndef BIGRAMPTR_HPP
#define BIGRAMPTR_HPP

class BigramStack {
private:
    char stack[6][2]; // Array to hold up to 6 bigrams
    char (*stackPtr)[2]; // Pointer to traverse the stack
    int stackPointer; // Used to track the top of the stack

public:
    BigramStack(); // Constructor to initialize the stack
    int push(const char (&bigram)[2]); // Push function
    int pop(char (&bigram)[2]); // Pop function
    int status(int &sp); // Status function to return the stack pointer
    int display(); // Display function to show contents of the stack
};

#endif