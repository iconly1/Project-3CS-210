#include "GroceryTracker.h"
#include <cctype>
class GroceryTracker {
private:
    std::map<std::string, int> itemFrequencies;

    void loadItemFrequencies() {
        std::ifstream inputFile(INPUT_FILE);
        std::string item;

        while (inputFile >> item) {
	        ++itemFrequencies[toupper(item)];

        }
        inputFile.close();

        // Backup data to file
        std::ofstream outputFile(OUTPUT_FILE);
        for (const auto& pair : itemFrequencies) {
            outputFile << pair.first << " " << pair.second << "\n";
        }
        outputFile.close();
    }

public:
    GroceryTracker() {
        loadItemFrequencies();
    }

    void findItemFrequency(const std::string& item) {
        auto search = itemFrequencies.find(item);
        if (search != itemFrequencies.end()) {
            std::cout << item << " was purchased " << search->second << " times.\n";
        }
        else {
            std::cout << item << " was not found in the records.\n";
        }
    }

    void printAllFrequencies() {
        for (const auto& pair : itemFrequencies) {
            std::cout << pair.first << ": " << pair.second << "\n";
        }
    }

    void printHistogram() {
        for (const auto& pair : itemFrequencies) {
            std::cout << std::setw(10) << std::left << pair.first << " "
                << std::string(pair.second, '*') << "\n";
        }
    }
};
