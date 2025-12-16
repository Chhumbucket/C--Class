#include <iostream>
#include <string>
#include "DeliveryOrder.h"
#include "DeliveryOrder.cpp"
#include "AccountOrder.h"

//        constructor

Account::Account(string name)
{
    username = name;
    status = "Regular";
}

Account::Account(string name, string statusin)
{
    username = name;
    status = statusin;
}

//        getter function for Status
string Account::getStatus() const
{
    return status;
}

//        destructor
Account::~Account()
{
    cout << "Account removed.\n";
}
