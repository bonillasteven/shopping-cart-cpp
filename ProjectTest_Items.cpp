/**
 * @file ProjectTest_Items
 * @author Steven A. Bonilla
 * @author starID: zf5681nx
 * Instructor: Jie Meichsner
 * @date 03/19/2026
 * @brief Requirements:
 *      - Declare three data members: name of item, unit price of item, and quantity of item
 *     - Define a default constructor 
 *     - Define a constructor that initializes all three data members by the parameters 
 *          - Define set and get functions for each data member 
 *          - Define the following operators:
 *              - Equal to: ==:
 *                          - two item are the same if their name and price are same; quanitity is not required to be same!
 *              - Input: >>
 *              - Output: <<
 * 
 */

#include "Items.h"
#include <iostream>

int main()
{
    Items items1;
    Items items2;

    std::cout << "Enter item1 (name price quantity): " << std::endl;
    std::cin >> items1;

    std::cout << "Enter item2 (name price quantity): " << std::endl;
    std::cin >> items2;

    std::cout << "Items1: " << items1 << std::endl;
    std::cout << "Items2: " << items2 << std::endl; 
    
    return 0;


}