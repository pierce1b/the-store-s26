#include <iostream>
#include <string>
#include <iomanip>
unsigned int Menu();

void Sell(const std::string items[], const float prices[], unsigned int productCount[], size_t size);


int main() {

    std::string items[] = {"Coke", "Donuts", "Coffee", "Bacon", "Milk"};
    float prices[] = {2.50, 1.00, 5.50, 7, 3.5};
    unsigned int productCount[sizeof(items)/sizeof(items[0])] = {0};
    unsigned int menuOption;
    do {
        menuOption = Menu();

        if (menuOption == 1) {
            Sell(items, prices, productCount, sizeof(items)/sizeof(items[0]));
        }else if (menuOption == 2) {
            //PrintSummary();
        }else if (menuOption == 3) {
            //SaveToFile();
        }else if (menuOption == 4) {
            //LoadFromFile();
        }else if (menuOption == 5) {
            std::cout << "Exit" << std::endl;
        }else {
            std::cerr << "Impossible" << std::endl;
        }
    }while (menuOption != 5);
}


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

void Sell(const std::string items[], const float prices[], unsigned int productCount[], size_t size){
    std::cout << "Select the product: " << std::endl;
    bool found = false;
    std::string item;
    unsigned int itemNumber;
    while (!found) {
        for (size_t i = 0; i < size; i++) {
            std::cout << std::left << std::setw(10) << items[i]
                      << std::setprecision(2) << std::fixed << std::setw(7) << prices[i] << std::endl;
        }
        std::getline(std::cin, item);
        itemNumber = -1;
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
    unsigned int count;
    std::cout << "How many: ";
    std::cin >> count;

    std::cout << "You want " << item << " " << count << " of them" << std::endl;
    float subTotal = count * prices[itemNumber];
    float tax = subTotal * 0.1f;
    float total = subTotal + tax;
    productCount[itemNumber] += count;

    std::cout << "Sub Total: " << subTotal << std::endl;
    std::cout << "Tax:       " << tax << std::endl;
    std::cout << "Total:     " << total << std::endl;

}
