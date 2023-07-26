#ifndef PERSON_H
#define PERSON_H

#include <string>

using namespace std;

class Person
{
protected:
    string identifier;
    string name;
    string contactInfo;

public:
    Person(const string &identifier, const string &name, const string &contactInfo)
        : identifier(identifier), name(name), contactInfo(contactInfo) {}

   
};

#endif // PERSON_H
