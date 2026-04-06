#include <iostream>
#include <string>

#include "store.h"

int main() {
    // What about if we read this from file?
    std::string items[] = {"Coke", "Donuts", "Coffee", "Bacon", "Milk"};
    float prices[] = {2.50, 1.00, 5.50, 7, 3.5};
    unsigned int productCount[sizeof(items)/sizeof(items[0])] = {0};
    float totalSold = 0.0f, totalTax = 0.0f;

    unsigned int menuOption;
    do {
        menuOption = Menu();

        if (menuOption == 1) {
            Sell(items, prices, productCount, sizeof(items)/sizeof(items[0]), totalSold, totalTax);
        }else if (menuOption == 2) {
            PrintSummary(items, productCount, sizeof(items)/sizeof(items[0]), totalSold, totalTax );
        }else if (menuOption == 3) {
            std::string filename;
            std::cout << "Store state in file: ";
            std::cin >> filename;
            SaveToFile(filename, items, productCount, sizeof(items)/sizeof(items[0]), totalSold, totalTax);
        }else if (menuOption == 4) {
            std::string filename;
            std::cout << "Store state in file: ";
            std::cin >> filename;
            LoadFromFile(filename, productCount, sizeof(items)/sizeof(items[0]), totalSold, totalTax);
        }else if (menuOption == 5) {
            std::cout << "Exit" << std::endl;
        }else {
            std::cerr << "Impossible" << std::endl;
        }
    }while (menuOption != 5);
}

