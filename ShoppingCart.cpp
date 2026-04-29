/**
 * @file ShoppingCart.cpp
 * @author Steven A. Bonilla
 * @author starID: zf5681nx 
 * Instructor: Jie Meichsner 
 * @date 03/19/2026
 * @brief Requirements:
 *          - Design the shopping cart as a derived class from the Bag class using public inheritance as follow:
 *          - class ShoppingCart:  public Bag<Item> 
 *          - where teh Bag class is the one provided in lectures and the textbook.
 *          - You don't need to create it
 *          - Declare total price as data member
 *          - Define a default constructor 
 *          - Define member function to get the total price
 *          - Override the bass class methods: add, remove, and clear
 */


#include "ShoppingCart.h"
#include <iostream>

/**
* Initializes the shopping cart with a total price of 0
* */
ShoppingCart::ShoppingCart()
{
    totalPrice = 0;
}

/**
* @return double the Total Price
* */
double ShoppingCart::getTotalPrice() const
{
    return totalPrice;
}

/**
* @brief Adds an item to the shopping cart.
* 
* Overrides the Bag add function and updates the total price.
* 
* @param newItem The item to be added.
* @return true if the item was successfully added.
* @return false otherwise.
*/
bool ShoppingCart::add(const Items& newItem)
{
    // Call the base class (Bag) add function to store the item
    bool success = Bag<Items>::add(newItem);
    
    // If the item was successfully added to the bag
    if(success)
    {
        //updates total price
        //price of item * quantity of item
        totalPrice += newItem.getPrice() * newItem.getQuantity();
    }

    // return whether the item was successfully added  
    return 0;
}


/**
* @brief Removes an item from the shopping cart.
* 
* Overrides the Bag remove function and updates the total price.
* 
* @param anItem The item to be removed.
* @return true if the item was successfully removed.
* @return false if the item was not found.
*/
bool ShoppingCart::remove(const Items& anItem)
{
    // Call the base class (Bag) add function to store the item
    bool success = Bag<Items>::remove(anItem);

    //if the item was successfully removed to the bag
    if(success)
    {
        //updates total price
        // price of item * quantity of item
        totalPrice -= anItem.getPrice() * anItem.getQuantity();
    }

    // return whether the item was successfully remoove
    return success;
}

/**
* @brief Clears all items from the shopping cart.
* 
* Overrides the Bag clear function and resets the total price to 0.
*/
void ShoppingCart::clear()
{
    Bag<Items>::clear();

    totalPrice = 0;
}

