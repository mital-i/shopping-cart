#include <iostream>
using namespace std;
#include "ShoppingCart.h"
#include "ItemToPurchase.h"
#include <cstring>

ShoppingCart::ShoppingCart() {
   customerName = "none";
   currentDate = "January 1, 2016";
   cartItems = {};
}
ShoppingCart::ShoppingCart(string name, string date) {
   customerName = name;
   currentDate = date;
   cartItems = {};
}

string ShoppingCart::GetCustomerName() const {
   return customerName;
}

string ShoppingCart::GetDate() const {
   return currentDate;
}

void ShoppingCart::AddItem(ItemToPurchase item) {
   cartItems.push_back(item);
}

void ShoppingCart::RemoveItem(string name) {
   int index = -1;
   int s = cartItems.size();
   for (int i = 0; i < s; i++) {
      if (cartItems.at(i).GetName() == name) {
         cartItems.erase(cartItems.begin()+i);
      }
   }
   if(index==-1) {
      cout << "Item not found in cart. Nothing removed." << endl;
   }
   cout << endl;
}

void ShoppingCart::ModifyItem(ItemToPurchase item) {
   int s = cartItems.size();
   for(int i = 0; i < s; i++) {
      if (cartItems.at(i).GetName() == item.GetName()) {
         cartItems.at(i).SetQuantity(item.GetQuantity());
         
      }
   }
}

int ShoppingCart::GetNumItemsInCart() const {
   int total = 0;
   int s = cartItems.size();
   for (int i = 0; i < s; i++) {
      total+=(cartItems.at(i).GetQuantity());
   }
   return total;
}

int ShoppingCart::GetCostOfCart() const {
   int total = 0;
   int s = cartItems.size();
   for (int i = 0; i < s; i++) {
      total+=(cartItems.at(i).GetPrice()*cartItems.at(i).GetQuantity());
   }
   return total;
}

void ShoppingCart::PrintTotal() {
   int total = 0;
   int s = cartItems.size();
   for (int i = 0; i < s; i++) {
      total+=cartItems.at(i).GetPrice();
   }
   
   cout << customerName << "'s Shopping Cart - " << currentDate << endl;
   cout << "Number of Items: " << GetNumItemsInCart() << endl << endl;
   for (int i = 0; i < s; i++) {
      cartItems.at(i).PrintItemCost();
   }
   if(total==0) {
      cout << "SHOPPING CART IS EMPTY" << endl;
   }
   cout << endl;
   cout << "Total: $" << GetCostOfCart() << endl << endl;
}

void ShoppingCart::PrintDescriptions() {
   int s = cartItems.size();
   cout << customerName << "'s Shopping Cart - " << currentDate << endl << endl;
   //cout << "Number of items: " << GetNumItemsInCart() << endl << endl;
   cout<< "Item Descriptions" << endl;
   for (int i = 0; i < s; i++) {
      cartItems.at(i).PrintItemDescription();
   }
   cout << endl;
}
