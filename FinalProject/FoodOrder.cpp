#include <iostream> 
#include <string> 
#include "DeliveryOrder.h"
#include "DeliveryOrder.cpp"
#include "FoodOrder.h"
#include "InvalidInput.cpp"

using namespace std;

FoodOrder::FoodOrder(string name,string date, string phone, float miles, string restaurantName) : DeliveryOrder(name, date, phone, miles){ 
    this -> restaurantName = restaurantName;
    foodCount = 0; 
}

void const FoodOrder::receipt(){
            DeliveryOrder::receipt();
            cout<<"\tOrdered Meal: "<<foodCount<<endl;
        }

void FoodOrder::addFood(string foodName){
    int foodPrice = 0; 

    foodCount++;

     try{
        if(foodName == "Thick Cauliflower Steaks"){
            foodPrice += 15;
        }
        else if(foodName == "Rack of Lamb"){
            foodPrice += 38;
        }
        else if(foodName == "Organic Scottish Salmon"){
            foodPrice += 23;
        }
        else if(foodName == "Grilled Lobster Risotto"){
            foodPrice += 46;
        }

        else{
            throw InvalidInput(foodName);
            foodCount -= 1;
            foodPrice = 0;
        }
    }
    catch(InvalidInput &r){
        r.reason();
    }

    if(foodPrice > 0){
        orderBalance += foodPrice;
    }

}

void FoodOrder::addFood(string foodName, bool soup, int sideAmount){
    int foodPrice = 0; 

    foodCount++;

    try{
        if(foodName == "Thick Cauliflower Steaks"){
            foodPrice += 15;
        }
        else if(foodName == "Rack of Lamb"){
            foodPrice += 38;
        }
        else if(foodName == "Organic Scottish Salmon"){
            foodPrice += 23;
        }
        else if(foodName == "Grilled Lobster Risotto"){
            foodPrice += 46;
        }

        else{
            throw InvalidInput(foodName);
        }
    }
    catch(InvalidInput &r){
        foodCount--;
        r.reason();
    }

    if(foodPrice>0)
    {
        if(soup==true)
        {
            orderBalance += foodPrice + 5 + (sideAmount * 6);
        }

        else{
            orderBalance += foodPrice + (sideAmount +6);
        }
    }
}

float FoodOrder::VIPdiscount()
{
    if (foodCount > 10)
    {
        return 0.85;
    }
    else if (foodCount >5 ) {
        return 0.9;
    }
    else if (foodCount > 2)
    {
        return 0.95;
    }
    else if (foodCount <=2)
    {
        return 1;
    }
    else{
        return 0;
    }
}

FoodOrder::~FoodOrder(){
    cout<<"FoodOrder.\n";
}

int FoodOrder::foodCount=0; 

