#ifndef SUPERMARKET_H
#define SUPERMARKET_H

#include <string>

using namespace std;

class Supermarket
{
    string name;
    string address;
    string contactInfo;

public:
    Supermarket(const string &name, const string &address, const string &contactInfo);

    void displayDetails() const;
    string getName() const;
    string getAddress() const;
    string getContactInfo() const;
};

#endif // SUPERMARKET_H
