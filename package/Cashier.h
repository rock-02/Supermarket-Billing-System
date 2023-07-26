#ifndef CASHIER_H
#define CASHIER_H

#include "Supermarket.h"
#include "Customer.h"
#include "Product.h"
#include <iostream>
#include <iomanip>

class Cashier : public Person
{
public:
    Cashier(const string &identifier, const string &name, const string &contactInfo)
        : Person(identifier, name, contactInfo) {}

    static void scanProduct(Customer c);
    static void generateBillReceipt(Supermarket &supermarket, Customer c, double dis);
};

#endif // CASHIER_H
