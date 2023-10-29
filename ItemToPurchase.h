#ifndef ITEM_TO_PURCHASE_H
#define ITEM_TO_PURCHASE_H

#include <string>
using namespace std;

class ItemToPurchase {
   public:
   ItemToPurchase();
   ItemToPurchase(string name, string description, int price, int quant);
   void SetDescription(string descp);
   string GetDescription() const;
   void PrintItemCost();
   void PrintItemDescription();
   void SetName(string name);
   string GetName() const;
   void SetPrice(int price);
   int GetPrice() const;
   void SetQuantity(int quant);
   int GetQuantity() const;
   
   private:
   string itemName;
   int itemPrice;
   int itemQuantity;
   string itemDescription;
   
};
/* Type your code here */

#endif
