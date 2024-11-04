#include <iostream>
#include <map>
#include <fstream>
#include <iomanip>

int main() {
    // Step 2: Initialize Variables
    std::map<std::string, float> items = {
        {"Apple", 1.50},
        {"Banana", 0.75},
        {"Milk", 2.00},
        {"Bread", 1.25},
        {"Eggs", 3.00}
    };

    float total_cost = 0.0;
    float discount = 0.0;
    int numberOfItems;
    std::string userName;

    // Step 3: Welcome message and user name input
    std::cout << "Welcome to the Shopping Cart Program!\n";
    std::cout << "Please enter your name: ";
    std::getline(std::cin, userName);

    // Display available items
    std::cout << "Available items for selection:\n";
    for (const auto &item : items) {
        std::cout << "- " << item.first << ": $" << item.second << "\n";
    }

    // Step 4: Input Number of Items
    do {
        std::cout << "Enter the number of different items you want to purchase: ";
        std::cin >> numberOfItems;
        if (numberOfItems < 1) {
            std::cout << "Error: Please enter a valid number of items.\n";
        }
    } while (numberOfItems < 1);

    // Step 5: Loop Through Each Item
    for (int i = 0; i < numberOfItems; ++i) {
        std::string selectedItem;
        int quantity;

        // Step 5a: Input Item Selection
        do {
            std::cout << "Select an item by name: ";
            std::cin >> selectedItem;
            if (items.find(selectedItem) == items.end()) {
                std::cout << "Error: Item not found. Please select a valid item.\n";
            }
        } while (items.find(selectedItem) == items.end());

        // Step 5b: Input Quantity
        do {
            std::cout << "Enter the quantity for " << selectedItem << ": ";
            std::cin >> quantity;
            if (quantity <= 0) {
                std::cout << "Error: Please enter a positive integer for quantity.\n";
            }
        } while (quantity <= 0);

        // Step 5c: Calculate Cost for Current Item
        float itemCost = items[selectedItem] * quantity;
        total_cost += itemCost;
    }

    // Step 6: Calculate Total Cost
    if (total_cost > 100) {
        discount = total_cost * 0.05;
        total_cost -= discount;
    }

    // Step 7: Display Final Bill
    std::cout << "Final Bill:\n";
    std::cout << "Total Cost: $" << std::fixed << std::setprecision(2) << total_cost << "\n";
    if (discount > 0) {
        std::cout << "Discount Applied: $" << discount << "\n";
    }

    // Step 8: Write Final Output to a Text File
    std::ofstream file("bill.txt");
    if (file.is_open()) {
        file << "Customer Name: " << userName << "\n";
        file << "Total Cost: $" << std::fixed << std::setprecision(2) << total_cost << "\n";
        if (discount > 0) {
            file << "Discount Applied: $" << discount << "\n";
        }
        file.close();
    } else {
        std::cerr << "Error: Unable to write to file.\n";
    }

    return 0;
}
