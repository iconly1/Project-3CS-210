#include "GroceryTracker.h"
#include "GroceryTracker.cpp"
// Define variable
const std::string INPUT_FILE = "CS210_Project_Three_Input_File.txt";
const std::string OUTPUT_FILE = "frequency.dat";
void displayMenu() {
    std::cout << "\nCorner Grocer Item Tracker\n";
    std::cout << "1. Find Item Frequency\n";
    std::cout << "2. Print All Items and Frequencies\n";
    std::cout << "3. Print Histogram of Item Frequencies\n";
    std::cout << "4. Exit\n";
    std::cout << "Enter your choice: ";
}

int main() {
    GroceryTracker tracker;
    int choice;
    std::string item;


    while (true) {
        displayMenu();
        std::cin >> choice;
        switch (choice) {
        case 1:
            std::cout << "Enter item name: ";
            std::cin >> item;
            tracker.findItemFrequency(item);
            break;
        case 2:
            tracker.printAllFrequencies();
            break;
        case 3:
            tracker.printHistogram();
            break;
        case 4:
            std::cout << "Exiting program...\n";
            return 0;
        default:
            std::cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
