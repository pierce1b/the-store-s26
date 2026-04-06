//
// Created by Arias Arevalo, Carlos on 4/1/26.
//

#include "store.h"

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

unsigned int Menu() {
    unsigned int menuOption;
    do {
        std::cout << "Welcome to The Store" << std::endl;
        std::cout << "1. Sell to Customer" << std::endl;
        std::cout << "2. View Summary" << std::endl;
        std::cout << "3. Save Store State" << std::endl;
        std::cout << "4. Load Store State" << std::endl;
        std::cout << "5. Exit" << std::endl;
        std::cin >> menuOption;
        if (std::cin.fail()) {
            std::cin.clear();
            std::cin.ignore(255, '\n');
            std::cerr << "You have failed me for the last time" << std::endl;
            continue;
        }
        std::cin.clear();
        std::cin.ignore(255, '\n');
        if (menuOption <= 0 || menuOption > 5) {
            std::cerr << "Please input 1 - 5" << std::endl;
        }

    }while (menuOption <=0 || menuOption > 5);
    return menuOption;
}

void Sell(const std::string items[], const float prices[], unsigned int productCount[],
    size_t size, float& totalSold, float& totalTax){
    bool finish = false;
    float tax, total;
    float subTotal = 0;
    do {
        std::cout << "Select the product: " << std::endl;
        bool found = false;
        std::string item;
        unsigned int itemNumber;
        while (!found) {
            for (size_t i = 0; i < size; i++) {
                std::cout << std::left << std::setw(10) << items[i]
                          << std::setprecision(2) << std::fixed << std::setw(7) << prices[i] << std::endl;
            }
            std::getline(std::cin, item); // '\n'
            itemNumber = -1;
            if (item == "exit") {
                finish = true;
                break;
            }

            for (size_t i = 0; i < size; i++) {
                if (item == items[i]) {
                    itemNumber = i;
                    found = true;
                }
            }
            if (!found) {
                std::cerr << "Select a product from the list" << std::endl;
            }
        }
        if (!finish) {
            unsigned int count;
            std::cout << "How many: ";
            std::cin >> count;
            std::cin.ignore();

            std::cout << "You want " << item << " " << count << " of them" << std::endl;
            subTotal += count * prices[itemNumber];
            productCount[itemNumber] += count;
        }

    }while (!finish);
    tax = subTotal * 0.1f;
    total = subTotal + tax;
    totalSold += total;
    totalTax += tax;

    std::cout << "Sub Total: " << subTotal << std::endl;
    std::cout << "Tax:       " << tax << std::endl;
    std::cout << "Total:     " << total << std::endl;

}
void PrintSummary(const std::string items[], unsigned int productCount[],
    size_t size, float totalSold, float totalTax) {

    for (size_t i=0; i<size; i++) {
        std::cout << items[i] << " " << productCount[i] << std::endl;
    }
    std::cout << "Total Sold: " << totalSold << std::endl;
    std::cout << "Total Tax: " << totalTax << std::endl;

}
void SaveToFile(const std::string& filename, const std::string items[], unsigned int productCount[],
    size_t size, float totalSold, float totalTax) {

    std::ofstream output(filename);
    if (output.fail()) {
        std::cerr << "Unable to open file " << filename << std::endl;
        return;
    }
    for (size_t i = 0; i < size; ++i) {
        output << productCount[i] << " " << items[i] << std::endl;
    }
    output << totalSold << std::endl << totalTax << std::endl;
    output.close();
}

void LoadFromFile(const std::string& filename, unsigned int productCount[], size_t size, float& totalSold, float& totalTax) {

    std::ifstream input(filename);
    if (input.fail()) {
        std::cerr << "Unable to open file " << filename << std::endl;
        return;
    }
    std::string dummy;
    unsigned int count;
    for (size_t i=0; i<size;i++) {
        input >> count;
        productCount[i] = count;
        input >> dummy;
    }
    input >> totalSold;
    input >> totalTax;
    input.close();
}
