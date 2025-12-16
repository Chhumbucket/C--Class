#include <iostream> 
#include <string> 
#include "DeliveryOrder.h"
#ifndef FOODORDER_H
#define FOODORDER_H

using namespace std; 

class FoodOrder: public DeliveryOrder
{
    private: 
        string restaurantName; 
        static int foodCount;
    public: 
     FoodOrder(string name,string date, string phone, float miles, string restaurantName);
    
    const void receipt(); 

    float VIPdiscount();

    void addFood(string foodName, bool, int);
    void addFood(string);

    ~FoodOrder(); 


};

#endif