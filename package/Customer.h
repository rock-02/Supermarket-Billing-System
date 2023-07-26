#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <iostream>
#include <vector>
#include <string>
#include "Person.h"
#include "ShoppingCart.h"
#include "Product.h"

using namespace std;

class Customer : public Person
{
    ShoppingCart cart;

public:
    Customer(const string &identifier, const string &name, const string &contactInfo)
        : Person(identifier, name, contactInfo) {}

    ShoppingCart &getCart()
    {
        return cart;
    }

    string getIdentifier()
    {
        return this->identifier;
    }
    string getContactInfo()
    {
        return this->contactInfo;
    }

    string getName()
    {
        return this->identifier;
    }

    void BuyProduct(vector<Product> &products);

    void removeFromCart(vector<Product> &products);

    void updateQuantity();
};

#endif // CUSTOMER_H
