/**
 * @file Items.cpp
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
 *                          - two item are the same if their name and price are same; qantity is not required to be the same!
 *              - Input: >>
 *              - Output: <<
 * 
 */

#include "Items.h"
#include <iostream>
#include <string>

/** Define a default constructor*/
Items::Items()
{
    name = "";
    price = 0;
    quantity = 0;

}

/**
* Constructor
* @param n new name of item
* @param p new price of item
* @param q new quantity of item
* @pre none
* @post Items initialized
*/

Items::Items(std::string n, double p, int q)
{
    name = n;
    price = p;
    quantity = q;
}

/**
* set name of the item
* @param n to new name of item
* @pre none
* @post item name updated
*/
void Items::setName(std::string n)
{
    name = n;
}

/**
* set price of the item
* @param p to new price 
* @pre none 
* @post price updated
*/
void Items::setPrice(double p)
{
    price = p;
}

/**
* set quantity of the item
* @param q to new quantity
* @pre none
* @post quantity updated
*/
void Items::setQuantity(int q)
{
    quantity = q;
}

/**
* return the name of the item
* @return item name
*/
std::string Items::getName() const
{
    return name;

}

/**
* returns the price of item 
* @return item price
*/
double Items::getPrice() const
{
    return price;
}

/**
* returns the quantity of item 
* @return quantity number
*/
int Items::getQuantity() const
{
    return quantity;
}

/**
* Equality operator 
* Two items are the same if their name and price are the same
* quantity is not required to be same 
* @param other the item being compared
* @return true if name and price are equal, otherwise false
 */
bool Items::operator==(const Items& other) const
{
    return(name == other.name && price == other.price);
}

/**
* Input operator 
* Reads the item name, price and quantity from an input stream
* @return the input stream
*/

std::istream& operator>>(std::istream& in, Items& item)
{
    in >> item.name >> item.price >> item.quantity;
    return in;
}

/***
* Output operator 
* Prints the item name, price, and qantity to an output stream
* @return the output stream 
*/
#include <iomanip>   // 🔥 REQUIRED

std::ostream& operator<<(std::ostream& out, const Items& item)
{
    out << std::left << std::setw(18) << item.getName()
        << std::left << std::setw(1) << "$"
        << std::left << std::setw(17) << std::fixed << std::setprecision(2) << item.getPrice()
        << std::left << std::setw(10) << item.getQuantity();

    return out;
}