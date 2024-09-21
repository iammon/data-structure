#ifndef MYCLASS_HPP
#define MYCLASS_HPP

class BigramStack {
private:
    char stack[6][2]; // Array to hold up to 6 bigrams, each bigram is a pair of characters (char[2])
    int stackPointer; // Index to track the top of the stack, starts at -1 when empty

public:
    BigramStack(); // Constructor to initialize the stack and pointer
    int push(const char (&bigram)[2]); // Push function to add a bigram to the stack
    int pop(char (&bigram)[2]); // Pop function to remove a bigram from the stack
    int status(int &sp); // Status function to retrieve the current position of the stack pointer
    int display(); // Function to display the contents of the stack and the pointer value
};

#endif