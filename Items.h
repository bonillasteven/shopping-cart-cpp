/**
 * @file Items.h
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
 * */

#ifndef ITEMS_H
#define ITEMS_H


#include <iostream> 
#include <string>

/** @class Items */
class Items
{
    private:
    
        /**
         * stores the name of item
         * @pre none
         * @post initialize name
         */
        std::string name = "";

        /**
         * price of item
         * @pre none
         * @post initialize price
         */
        double price = 0;

        /**
         * quantity of item
         * @pre none
         * @post initialize quantity
         */
        int quantity = 0;

    public:

        /** Define a default constructor*/
        Items();

        /**
         * Constructor
         * @param n new name of item
         * @param p new price of item
         * @param q new quantity of item
         * @pre none
         * @post Items initialized 
         */
        Items(std::string n, double p, int q);


        /**
         * set name of the item
         * @param n to new name of item
         * @pre none
         * @post item name updated
         */
        void setName(std::string n);

        /**
         * set price of the item
         * @param p to new price 
         * @pre none 
         * @post price updated
         */
        void setPrice(double p);

        /**
         * set quantity of the item
         * @param q to new quantity
         * @pre none
         * @post quantity updated
         */
        void setQuantity(int q);

        /**
         * return the name of the item
         * @return item name
         */
        std::string getName() const;

        /**
         * returns the price of item 
         * @return item price
         */
        double getPrice() const;

        /**
         * returns the quantity of item 
         * @return quantity number
         */
        int getQuantity() const;

        /**
         * Equaltiy operator 
         * Two items are the same if their name and price are the same
         * quantity is not required to be same 
         * @param other the item being compared
         * @return true if name and price are equal, otherwise false
         */
        bool operator==(const Items& other) const;

        /**
         * Input operator 
         * Reads the item name, price and quantity from an input stream
         * @return the input stream
         */

        friend std::istream& operator>>(std::istream& in, Items& item);

        /***
         * Output operator 
         * Prints the item name, price, and qantity to an output stream
         * @return the output stream 
         */

        friend std::ostream& operator<<(std::ostream& out, const Items& item);
        
};
#include "Items.cpp"
#endif

