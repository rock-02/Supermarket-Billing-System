#pragma once
#include "Person.h"
#include "Product.h"
#include "Customer.h"
#include <vector>
#include <iostream>

using namespace std;

class admin : public Person
{
public:
    static void addProduct(vector<Product> &products);
    static void deleteProductByIndex(vector<Product> &products, int index);
    static void modifyProductByIndex(vector<Product> &products, int index);
    static void productDetailsAndStocks(vector<Product> &products);
    static void viewFeedbacks(vector<Customer> &customerList, vector<pair<int, string>> &feedbacks);
};
