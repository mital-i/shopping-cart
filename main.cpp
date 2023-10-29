#include <iostream>
#include <iomanip>
using namespace std;

#include "ShoppingCart.h"

void PrintMenu() {
   
   cout << "MENU" << endl;
   cout << "a - Add item to cart" << endl;
   cout << "d - Remove item from cart" << endl;
   cout << "c - Change item quantity" << endl;
   cout << "i - Output items' descriptions" << endl;
   cout << "o - Output shopping cart" << endl;
   cout << "q - Quit" << endl << endl;
   
}

void ExecuteMenu(char option, ShoppingCart& theCart) {
   if(option=='a') {
      string name;
      string description;
      int price;
      int quantity;
      cin.ignore();
      cout << "ADD ITEM TO CART" << endl;
      cout << "Enter the item name:" << endl;
      getline(cin, name);
      cout << "Enter the item description:" << endl;
      getline(cin, description);
      cout << "Enter the item price:" << endl;
      cin >> price;
      cout << "Enter the item quantity:" << endl << endl;
      cin >> quantity;
      ItemToPurchase newItem(name, description, price, quantity);
      theCart.AddItem(newItem);
   } else if(option=='d') {
      cin.ignore();
      string name;
      cout << "REMOVE ITEM FROM CART" << endl;
      cout << "Enter name of item to remove:" << endl;
      getline(cin, name);
      theCart.RemoveItem(name);
   } else if(option=='c') {
      cin.ignore();
      string name;
      int newQuant;
      ItemToPurchase newItem;
      cout << "CHANGE ITEM QUANTITY" << endl;
      cout << "Enter the item name:" << endl;
      getline(cin, name);
      cout << "Enter the new quantity:" << endl;
      cin >> newQuant;
      newItem.SetName(name);
      newItem.SetQuantity(newQuant);
      theCart.ModifyItem(newItem);
      cout << endl;
      
   } else if(option=='i') {
      cout << "OUTPUT ITEMS' DESCRIPTIONS" << endl;
      theCart.PrintDescriptions();
   } else if(option=='o') {
      cout << "OUTPUT SHOPPING CART" << endl;
      theCart.PrintTotal();
   }
   
}

int main() {
   string customerName;
   string date;
   cout << "Enter customer's name:" << endl;
   getline(cin, customerName);
   cout << "Enter today's date:" << endl << endl;
   getline(cin, date);
   
   char option = ' ';
   ShoppingCart theCart(customerName, date);
   cout << "Customer name: " << customerName << endl;
   cout << "Today's date: " << date << endl << endl;
   PrintMenu();
   while (option!='q') {
      cout << "Choose an option:" << endl;
      cin >> option;
      if(option=='a' || option=='d' || option=='c' || option=='i' || option=='o') {
         ExecuteMenu(option, theCart);
         PrintMenu();
      }
   }
   /* Type your code here */
   
   return 0;
}
