#include <iostream>
#include <string>
#include "DeliveryOrder.h"
#include "DeliveryOrder.cpp"
#include "BobaOrder.h"
#include "InvalidInput.cpp"

using namespace std;

BobaOrder::BobaOrder(string name, string date, string phone, float miles, string shopName) : DeliveryOrder(name, date, phone, miles)
{
    this->shopName = shopName;
    drinksCount = 0;
}

void const BobaOrder::receipt()
{
    DeliveryOrder::receipt();
    cout << "\tOrdered Drinks: " << drinksCount << endl;
}

void BobaOrder::addDrink(string drinkName, bool boba, int count)
{
    float drinkPrice = 0.00;
    try
    {

        if (drinkName == "Green Tea Latte")
        {
            drinkPrice += 5.80;
        }

        else if (drinkName == "Brown Sugar Boba Milk")
        {
            drinkPrice += 7.8;
        }
        else if (drinkName == "Brown Sugar Pearl Milk")
        {
            drinkPrice += 9.80;
        }
        else
        {
            throw InvalidInput(drinkName);
        }
    }
    catch (InvalidInput &r)
    {
        r.reason();
        cout << "Not serving requested drinks. Drink order ignored. \n\n";
        count -= 1;
    }

    if (boba == true)
    {
        orderBalance += (drinkPrice + 1.5) * count;
    }
    else
    {
        orderBalance += (drinkPrice)*count;
    }

    drinksCount += count;
}

void BobaOrder::addDrink(string drinkName)
{
    float drinkPrice = 0.00;
    try
    {

        if (drinkName == "Green Tea Latte")
        {
            drinkPrice += 5.80;
        }

        else if (drinkName == "Brown Sugar Boba Milk")
        {
            drinkPrice += 7.8;
        }
        else if (drinkName == "Brown Sugar Pearl Milk")
        {
            drinkPrice += 9.80;
        }
        else
        {
            throw InvalidInput(drinkName);
        }
    }
    catch (InvalidInput &r)
    {
        r.reason();
        cout << "Not serving requested drinks. Drink order ignored. \n\n";
        drinksCount -= 1;
    }

    if (drinkPrice > 0)
    {
        orderBalance += (drinkPrice + 1.5);
    }

    drinksCount += 1;
}

float BobaOrder::VIPdiscount()
{
    if (drinksCount > 10)
    {
        return 0.85;
    }
    else if (drinksCount > 5)
    {
        return 0.9;
    }
    else if (drinksCount > 2)
    {
        return 0.95;
    }
    else if (drinksCount <= 2)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

BobaOrder::~BobaOrder()
{
    cout << "BobaOrder.\n";
}

int BobaOrder::drinksCount = 0;
