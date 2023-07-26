#include "Supermarket.h"
#include <iostream>

using namespace std;

Supermarket::Supermarket(const string &name, const string &address, const string &contactInfo)
    : name(name), address(address), contactInfo(contactInfo)
{
}

void Supermarket::displayDetails() const
{
    cout << "Supermarket Name: " << name << endl;
    cout << "Address: " << address << endl;
    cout << "Contact Info: " << contactInfo << endl;
}

string Supermarket::getName() const
{
    return name;
}

string Supermarket::getAddress() const
{
    return address;
}

string Supermarket::getContactInfo() const
{
    return contactInfo;
}
