#include <iostream>
#include "bigramPtr.hpp" // Include the header from the include directory
#include <stdexcept> // For exception handling

int main() {
    BigramStack stack; // Create a stack object
    char bigram[2]; // Variable to store bigrams for pop/push operations
    int sp; // Variable to hold the stack pointer for the status function
    int option; // Variable to record user choice

    do {
        // Display menu options
        std::cout << "What operation do you want to perform? Enter option number." << std::endl;
        std::cout << "1. Push" << std::endl;
        std::cout << "2. Pop" << std::endl;
        std::cout << "3. Status" << std::endl;
        std::cout << "4. Display" << std::endl;
        std::cout << "0. Exit" << std::endl;

        std::cin >> option;

        try {
            switch (option) {
                case 1: // Push operation
                    std::cout << "Please enter a bigram to push." << std::endl;
                    std::cin >> bigram[0] >> bigram[1];
                    stack.push(bigram); // May throw an overflow error
                    std::cout << "Bigram: [" << bigram[0] << bigram[1] << "] has been pushed into the stack." << std::endl;
                    break;

                case 2: // Pop operation
                    stack.pop(bigram); // May throw an underflow error
                    std::cout << "Bigram: [" << bigram[0] << bigram[1] << "] has been popped out of the stack." << std::endl;
                    break;

                case 3: // Status operation
                    stack.status(sp);
                    std::cout << "Stack pointer is at index: " << sp << std::endl;
                    break;

                case 4: // Display operation
                    stack.display();
                    break;

                case 0: // Exit
                    std::cout << "Exiting..." << std::endl;
                    break;

                default: // Invalid input
                    std::cout << "Invalid option. Please try again." << std::endl;
                    break;
            }
        } catch (const std::overflow_error &e) {
            std::cout << "Error: " << e.what() << std::endl;
        } catch (const std::underflow_error &e) {
            std::cout << "Error: " << e.what() << std::endl;
        }
    } while (option != 0); // Continue looping until user enters 0 to exit

    return 0;
}