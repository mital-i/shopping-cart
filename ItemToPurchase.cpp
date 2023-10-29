#include <iostream>
using namespace std;

#include "ItemToPurchase.h"

/* Type your code here */
ItemToPurchase::ItemToPurchase(string name, string description, int price, int quant) {
   itemName = name;
   itemDescription = description;
   itemPrice = price;
   itemQuantity = quant;
}

ItemToPurchase::ItemToPurchase() {
   itemName = "";
   itemPrice = 0;
   itemQuantity = 0;
   itemDescription = "";
}

void ItemToPurchase::SetDescription(string descp) {
   itemDescription = descp;
}

string ItemToPurchase::GetDescription() const{
   return itemDescription;
}

void ItemToPurchase::PrintItemCost() {
   cout << itemName << " " << itemQuantity << " @ $" << itemPrice << " = $" << itemQuantity*itemPrice << endl;
}

void ItemToPurchase::PrintItemDescription() {
   cout << itemName << ": " << itemDescription << endl;
}

void ItemToPurchase::SetName(string name) {
   itemName = name;
}

string ItemToPurchase::GetName() const {
   return itemName;
}

void ItemToPurchase::SetPrice(int price) {
   itemPrice = price;
}

int ItemToPurchase::GetPrice() const {
   return itemPrice;
}

void ItemToPurchase::SetQuantity(int quant) {
   itemQuantity = quant;
}

int ItemToPurchase::GetQuantity() const {
   return itemQuantity;
}
