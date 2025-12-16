#include <iostream> 
#include <string> 
#include "DeliveryOrder.h"
#ifndef BOBAORDER_H
#define BOBAORDER_H

using namespace std;

class BobaOrder: public DeliveryOrder
{
    private: 
        string shopName; 
        static int drinksCount;
    public: 
     BobaOrder(string name,string date, string phone, float miles, string shopName);
    
    const void receipt(); 

    float VIPdiscount();

    void addDrink(string, bool , int );
    void addDrink(string);

    ~BobaOrder(); 


};

#endif 