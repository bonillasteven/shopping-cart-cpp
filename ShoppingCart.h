/**
 * @file ShoppingCart.h'
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

 #ifndef SHOPPING_CART_H
 #define SHOPPING_CART_H
 
 #include "Items.h"
 #include "Bag.h"


   /** @class ShoppingCart: public Bag<Items> */
   /** 
   * @brief A shopping cart that stores Items using the Bag ADT.
   * 
   * This class extends the Bag class to manage shopping items
   * and keeps track of the total price of all items in the cart.
   */
class ShoppingCart: public Bag<Items>
 {
   private:
   
     /** 
     * @brief A shopping cart that stores Items using the Bag ADT.
     * 
     * This class extends the Bag class to manage shopping items
     * and keeps track of the total price of all items in the cart.
     */
     /**
     * Stores the total price of all items in the cart
     * */
      double totalPrice;

   public:
      /**
      * Initializes the shopping cart with a total price of 0
      * */
      ShoppingCart();
      
      /**
      * @return double the Total Price
      * */
      double getTotalPrice() const;

     /**
     * @brief Adds an item to the shopping cart.
     * 
     * Overrides the Bag add function and updates the total price.
     * 
     * @param newItem The item to be added.
     * @return true if the item was successfully added.
     * @return false otherwise.
     */
      bool add(const Items& newItem);

     /**
     * @brief Removes an item from the shopping cart.
     * 
     * Overrides the Bag remove function and updates the total price.
     * 
     * @param anItem The item to be removed.
     * @return true if the item was successfully removed.
     * @return false if the item was not found.
     */
      bool remove(const Items& anItem);

     /**
     * @brief Clears all items from the shopping cart.
     * 
     * Overrides the Bag clear function and resets the total price to 0.
     */
      void clear();
 };

 #include "ShoppingCart.cpp"
 #endif