#include <iostream>
#include <string>
#include "DeliveryOrder.h"
#ifndef ACCOUNTORDER_H
#define ACCOUNTORDER_H

class Account
{
private:
        string username, status;

public:
        //        constructor
        Account(string username, string status);

        Account(string);

        //        getter function for Status
        string getStatus() const;

        //        destructor
        ~Account();
};

#endif