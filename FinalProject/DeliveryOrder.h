#include <iostream> 
#include <string> 
#ifndef DELIVERYORDER_H
#define DELIVERYORDER_H

using namespace std;

class DeliveryOrder{
    private: 
    string name, date, phone;
    float miles;
    static int orderCount;
    const float taxRate= 0.09;
    const float deliveryRate= 1.5; 

    protected: 
   static float orderBalance;

public:
DeliveryOrder(string name,string date, string phone, float miles);

const void receipt(); 

float getTotalBalance() const; 

static int getOrderCount(); 

virtual float VIPdiscount() = 0; // Could fix because all have same pattern 


~DeliveryOrder();

};

#endif