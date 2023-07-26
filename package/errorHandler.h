#ifndef ERRORHANDLER_H
#define ERRORHANDLER_H

#include <iostream>
#include <string>

using namespace std;

class errorHandler
{
protected:
    int id;
    string msg;

public:
    errorHandler(int id, string msg)
    {
        this->id = id;
        this->msg = msg;
    }

    void printError()
    {
        cout << "Error Status-Code : " << this->id << endl;
        cout << "Error-Message: " << this->msg << endl;
    }
};

#endif // ERRORHANDLER_H
