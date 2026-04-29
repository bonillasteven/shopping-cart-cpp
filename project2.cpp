/**
* @file project2.cpp
* @author Steven A. Bonilla
* @author starID: zf5681nx 
* Instructor: Jie Meichsner
* @date 03/19/2026
* @brief  
* Requirements 
    Write and document the class in header and implementation files, and compile it separately from the client program.
    Add the implementation of ShoppingCart class at the end of the header file “ShoppingCart.h” as follows:
    #include “ShoppingCart.cpp”

    (before the line #endif) 

    **This is required to run your program correctly on GitHub.


    Testing
    Design your test data to test ALL operations provided in the ShoppingCart:

    Add
    Remove ( two cases: in the cart and  not in the cart)
    Change quantity (two cases: in the cart and not in the cart). If in the cart, validate the quantity.
*/


#include <iostream>
#include "ShoppingCart.h"
#include <vector>


int main()
{
    ShoppingCart cart;
    Items item;
    char choice = 'y';
    char modify = 'y';
    int option;


    // prints information
    std::cout << "Welcome to Steven SHOPPING CENTER." << std::endl;
    std::cout << "Enter the item you selected as the following order: " << std::endl;
    std::cout << "name unitPrice quantity" << std::endl;
    std::cout << "(Name can not contain any space. Otherwise errors happen!)" << std::endl;

    // while user enter y or Y they will add item in carts
    while(choice == 'y' || choice == 'Y')
    {
        std::cout << "--> ";
        std::cin >> item;
        cart.add(item);

        std::cout << "Want to continue y/n--> ";
        std::cin >> choice;

    }
    
    //prints information 
    std::cout << "Here is your updated order:" << std::endl;
    std::cout << "--------------------------------------------------" << std::endl;
    std::cout << "You have ordered the following items:" << std::endl;
    std::cout << "Name              Unit_Price        Quantity" << std::endl;
    
    //all added items are stored in the cart
    std::vector<Items> items = cart.toVector();

    for(const auto& i : items)
    {
        std::cout << i << std::endl;        // prints all items in cart
    }
    
    std::cout << std::endl;                 // skips a line
    std::cout << "The total charge is $" << cart.getTotalPrice() << std::endl;      //prints total

    std::cout << "--------------------------------------------------" << std::endl;
    std::cout << std::endl;




    // prints if user want to modify the order
    std::cout << "Want to modify your order? y/n--> ";
    
    // stores answer
    std::cin >> modify;

    //while user enters y or Y, let user to modify the list in the cart
    while(modify == 'y' || modify == 'Y')
    {
        std::cout << "What do you want?" << std::endl;
        std::cout << "Enter 1: add\t 2: remove\t 3: change quantity" << std::endl;
        std::cin >> option;         //stores answer 


        Items temp; // stores an modification to this varaible without effecting what is already stored

        if(option == 1)         // add more items to cart
        {
            
            std::cout << "Enter the item to addd as following order: " << std::endl;
            std::cout << "name unitPrice quantity" << std::endl;
            std::cout << "-->";
            std::cin >> temp;
            cart.add(temp);
            
            std::cout << "The item has been add" << std::endl;
        }

        else if(option == 2)        //remove any items in cart
        {
            std::cout << "Enter the item to remove as the following order:" << std::endl;
            std::cout << "name unitPrice quantity" << std::endl;
            std::cin >> temp;

            // if items is in cart, remove item
            if(cart.remove(temp))
            {
                std::cout << "The item has been removed" << std::endl;
            }
            //if item is not in cart, informs user
            else
            {
                std::cout << "No such item in your shopping cart!" << std::endl;
            }
        }


        // let user update the quantity 
        else if(option == 3)
        {
            std::cout << "Enter the item to change as the following order:" << std::endl;
            std::cout << "name unitPrice quantity" << std::endl;
            std::cin >> temp;
            
            //make sure what is in currectly 
            std::vector<Items> items = cart.toVector();
            //assume item is not in cart
            bool found = false;


            for(const auto& i : items)
            {
                if(i == temp)
                {
                    // if item is in cart updates the quantity 
                    found = true;
                    
                    int NewQuantity;
                    std::cout << "Enter a new quantity --> ";
                    std::cin >> NewQuantity;

                    while(NewQuantity < 0)          // if input is less than 0, informs the user typo
                    {
                        std::cout << NewQuantity << " is not a valid input. ";
                        std::cout << "Enter a new quantity --> ";
                        std::cin >> NewQuantity;
                    }

                    cart.remove(i);

                    //updats information 
                    Items updated(i.getName(), i.getPrice(), NewQuantity);
                    cart.add(updated);

                    std::cout << "The quantity has been modified" << std::endl;
                
                    break;
                }
            }

            if(!found)
            {
                std::cout << "No such item is in your shopping cart!";
            }
        }

        //loop keeps going till user enters n or N
        std::cout <<"\nWant to modify your order? y/n--> " << std::endl;
        std::cin >> modify;
        

    }

    std::cout << "Here is your updated order:" << std::endl;
    std::cout << "--------------------------------------------------" << std::endl;
    std::cout << "You have ordered the following items:" << std::endl;
    std::cout << "Name          Unit_Price          Quantity" << std::endl;
    
    // gets final update on the cart
    std::vector<Items> finalItems = cart.toVector();

    for(const auto& i : finalItems)
    {
        std::cout << i << std::endl;
    }

    std::cout << "The total charge is $" << cart.getTotalPrice() << std::endl;
    
    std::cout << "Thanks for shopping in Steven SHOPPING CENTER." << std::endl;
    std::cout << "--------------------------------------------------" << std::endl;

    return 0;
}