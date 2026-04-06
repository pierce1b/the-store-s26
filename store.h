//
// Created by Arias Arevalo, Carlos on 4/1/26.
//

#ifndef THE_STORE_S26_STORE_H
#define THE_STORE_S26_STORE_H

#include <string>

unsigned int Menu();
void Sell(const std::string items[], const float prices[], unsigned int productCount[],
    size_t size, float& totalSold, float& totalTax);
void PrintSummary(const std::string items[], unsigned int productCount[],
    size_t size, float totalSold, float totalTax);
void SaveToFile(const std::string& filename, const std::string items[], unsigned int productCount[],
    size_t size, float totalSold, float totalTax);
void LoadFromFile(const std::string& filename, unsigned int productCount[], size_t size, float& totalSold, float& totalTax);



#endif //THE_STORE_S26_STORE_H