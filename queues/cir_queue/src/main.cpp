#include "CircularQueue.hpp"
#include <iostream>

void displayMenu() {
    std::cout << "----- Circular Queue Menu -----\n";
    std::cout << "1. Enqueue (Add element)\n";
    std::cout << "2. Dequeue (Remove element)\n";
    std::cout << "3. Display Queue\n";
    std::cout << "4. Check if Queue is Full\n";
    std::cout << "5. Check if Queue is Empty\n";
    std::cout << "6. Exit\n";
    std::cout << "Choose an option: ";
}

int main() {
    int size;
    std::cout << "Enter the maximum size of the queue: ";
    std::cin >> size;

    CircularQueue queue(size);  // Create a CircularQueue object with the user-defined size
    int choice;
    std::string bigram;

    do {
        displayMenu();  // Display menu options
        std::cin >> choice;

        switch (choice) {
        case 1:  // Enqueue
            std::cout << "Enter a bigram (2 characters): ";
            std::cin >> bigram;
            if (queue.enqueue(bigram)) {
                std::cout << "Enqueued successfully.\n";
            } else {
                std::cout << "Queue is full. Could not enqueue.\n";
            }
            break;

        case 2:  // Dequeue
            bigram = queue.dequeue();
            if (bigram == "Queue is empty") {
                std::cout << "Queue is empty. Could not dequeue.\n";
            } else {
                std::cout << "Dequeued: " << bigram << "\n";
            }
            break;

        case 3:  // Display Queue
            {
                std::vector<std::string> elements = queue.displayQueue();
                if (elements.empty()) {
                    std::cout << "Queue is empty.\n";
                } else {
                    std::cout << "Queue elements: ";
                    for (const auto& elem : elements) {
                        std::cout << elem << " ";
                    }
                    std::cout << "\n";
                }
            }
            break;

        case 4:  // Check if queue is full
            if (queue.isFull()) {
                std::cout << "The queue is full.\n";
            } else {
                std::cout << "The queue is not full.\n";
            }
            break;

        case 5:  // Check if queue is empty
            if (queue.isEmpty()) {
                std::cout << "The queue is empty.\n";
            } else {
                std::cout << "The queue is not empty.\n";
            }
            break;

        case 6:  // Exit
            std::cout << "Exiting program...\n";
            break;

        default:
            std::cout << "Invalid option. Please try again.\n";
        }
    } while (choice != 6);  // Loop until the user chooses to exit

    return 0;
}
