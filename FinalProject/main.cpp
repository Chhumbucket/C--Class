#include <iostream>
#include <string>
#include <iomanip>
#include <cmath>
#include <fstream>
#include "InvalidInput.cpp"
#include "BobaOrder.h"
#include "FoodOrder.h"
#include "DeliveryOrder.h"
#include "AccountOrder.h"

using namespace std;

float applyDiscount(DeliveryOrder *d, Account &a);

float applyDiscount(DeliveryOrder *d, Account &a)
{
    if (a.getStatus() == "Owner")
    {
        return (d->getTotalBalance() * 0.1);
    }
    else if (a.getStatus() == "VIP")
    {
        return (d->getTotalBalance() * d->VIPdiscount());
    }
    else
    {
        return (d->getTotalBalance());
    }
}

int main()
{
    const Account Stuart("Stuart", "Owner");

    // VIP account created
    Account Kevin("Kevin", "VIP");

    // Regular Account created
    Account Bob("Bob");

    cout << fixed << setprecision(2); // sets the output of everything to 2 decimal places

    // Kevin's order
    cout << "Kevin placing order.\n";
    BobaOrder d1("Kevin", "11/20/2022", "123-456-0000", 10.40, "M Tea");
    d1.addDrink("Green Tea Latte");
    d1.addDrink("Brown Sugar Boba Milk", false, 1);
    d1.addDrink("Brown Sugar Boba Milk", false, 2);
    d1.addDrink("Iron Goddess"); // should return an exception
    d1.receipt();
    cout << "Balance: $" << d1.getTotalBalance() << endl; // we pass d1 and Kevin objects into function below
    cout << "Discounted Balance: $" << applyDiscount(&d1, Kevin) << "\n"
         << endl; // we pass d1 and Kevin objects into function below

    return 0;
}
