#ifndef PRODUCT_H
#define PRODUCT_H

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

class Product
{
public:
    string identifier;
    string name;
    double price;
    int quantity;

public:
    Product(const string &identifier, const string &name, double price, int quantity)
        : identifier(identifier), name(name), price(price), quantity(quantity) {}

    void displayDetails(bool displayHeader = false) const
    {
        if (displayHeader)
        {
            cout << "+---------------+----------------+-----------------+------------+\n";
            cout << "|" << setw(15) << "Product Name"
                 << "|" << setw(15) << "Identifier"
                 << "|" << setw(15) << "Price ($)"
                 << "|" << setw(12) << "Quantity"
                 << "|\n";
            cout << "+---------------+----------------+-----------------+------------+\n";
        }
        cout << "|" << setw(15) << name << "|" << setw(15) << identifier << "|" << setw(15) << price << "|" << setw(12) << quantity << "|\n";
        cout << "+---------------+----------------+-----------------+------------+\n";
    }

    void setName(const string &newName)
    {
        name = newName;
    }

    void setPrice(double newPrice)
    {
        price = newPrice;
    }

    void setIdentifier(const string &newIdentifier)
    {
        identifier = newIdentifier;
    }

    void setQuantity(int newQuantity)
    {
        quantity = newQuantity;
    }
};

void ProductDeails(const vector<Product> &products);

#endif // PRODUCT_H
