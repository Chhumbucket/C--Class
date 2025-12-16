#include <iostream> 
#include <string> 
#include "DeliveryOrder.h"

using namespace std;



DeliveryOrder::DeliveryOrder(string name, string date, string phone, float miles){
    this -> name = name; 
    this -> date = date; 
    this -> phone = phone; 
    this -> miles = miles;
    orderBalance = 0; 
    orderCount++; 
}

void const DeliveryOrder::receipt(){
cout << "Order Detail:" << "\n";
cout << "\tName: " << name << "\n";
cout << "\tDate: " << date << "\n";
cout << "\tPhone: " << phone << "\n";
cout << "\tOrder Balance: $" << orderBalance << endl;
}

float DeliveryOrder::getTotalBalance() const{
    return (orderBalance*(1+taxRate)+miles*deliveryRate);
}

int DeliveryOrder::getOrderCount(){
    return orderCount;
}

DeliveryOrder::~DeliveryOrder(){
    cout << "DeliveryOrder destroyed.\n";
}


int DeliveryOrder::orderCount=0;