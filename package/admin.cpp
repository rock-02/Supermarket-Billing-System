
#include "admin.h"
#include "errorHandler.h"
#include <iostream>
#include <stdexcept>

using namespace std;

void admin::addProduct(vector<Product> &products)
{
    // ... (the rest of the implementation remains the same)
    cout << "\t\t\t\t|  1) Enter Product Details   |\n";
    cout << "\t\t\t\t|                             |\n";
    cout << "\t\t\t\t|  * Id(3charcter)            |\n";
    cout << "\t\t\t\t|                             |\n";
    cout << "\t\t\t\t|  * Price                    |\n";
    cout << "\t\t\t\t|                             |\n";
    cout << "\t\t\t\t|  * Name                     |\n";
    cout << "\t\t\t\t|                             |\n";
    cout << "\t\t\t\t|  * Quantity                 |\n";
    cout << "\t\t\t\t|                             |\n";
    try
    {
        string identifier;
        cin >> identifier;
        double price;
        cin >> price;
        string name;
        cin.ignore();
        getline(cin, name);
        int quantity;
        cin >> quantity;
        if (price <= 0 || quantity <= 0)
        {
            throw runtime_error("Quantity and Price cannot be negative or zero.");
        }
        Product p(identifier, name, price, quantity);
        products.push_back(p);
        cout << "Product Created Successfully" << endl;
    }
    catch (const exception &e)
    {
        cerr << "Error: " << e.what() << endl;
    }
}

void admin::deleteProductByIndex(vector<Product> &products, int index)
{
    // ... (the rest of the implementation remains the same)
    if (index >= 0 && index < products.size())
    {
        products.erase(products.begin() + index);
        cout << "Product at index " << index << " deleted successfully.\n";
    }
    else
    {
        cout << "Invalid index. Cannot delete product.\n";
    }
}

void admin::modifyProductByIndex(vector<Product> &products, int index)
{
    // ... (the rest of the implementation remains the same)
    if (index >= 0 && index < products.size())
    {
        cout << "Enter the updated details for the product (or enter 10 to stop updating):\n";

        while (true)
        {
            int updateChoice;
            cout << "1. Name" << endl;
            cout << "2. Price" << endl;
            cout << "3. Identifier" << endl;
            cout << "4. Quantity" << endl;
            cout << "10. Stop updating" << endl;

            cout << "Enter your choice: ";
            cin >> updateChoice;

            if (updateChoice == 10)
            {
                cout << "Product updating completed.\n";
                break;
            }

            switch (updateChoice)
            {
            case 1:
            {
                string newName;
                cout << "Enter new name: ";
                cin.ignore();
                getline(cin, newName);
                products[index].setName(newName);
                break;
            }
            case 2:
            {
                double newPrice;
                cout << "Enter new price: $";
                cin >> newPrice;
                if (newPrice <= 0)
                {
                    errorHandler(500, "Price Should Be Greater Than 0").printError();
                }
                else
                {
                    products[index].setPrice(newPrice);
                }
                break;
            }
            case 3:
            {
                string newIdentifier;
                cout << "Enter new identifier: ";
                cin.ignore();
                getline(cin, newIdentifier);
                products[index].setIdentifier(newIdentifier);
                break;
            }
            case 4:
            {
                int newQuantity;
                cout << "Enter new quantity: ";
                cin >> newQuantity;
                products[index].setQuantity(newQuantity);
                break;
            }
            default:
                cout << "Invalid choice. Please try again.\n";
            }
        }
    }
    else
    {
        cout << "Invalid index. Cannot modify product.\n";
    }
}

void admin::productDetailsAndStocks(vector<Product> &products)
{
    // ... (the rest of the implementation remains the same)
    cout << "\t\t\t\t ______________________________________ \n";
    cout << "\t\t\t\t|                                      |\n";
    cout << "\t\t\t\t|          Our Products                |\n";
    cout << "\t\t\t\t|______________________________________|\n";
    bool displayHeader = true;
    for (const auto &product : products)
    {
        product.displayDetails(displayHeader);
        displayHeader = false;
    }
}

void admin::viewFeedbacks(vector<Customer> &customerList, vector<pair<int, string>> &feedbacks)
{
    // ... (the rest of the implementation remains the same)
    if (feedbacks.size() <= 0)
    {
        cout << "No user Given Feedback\n";
        return;
    }
    for (int i = 0; i < feedbacks.size(); i++)
    {
        cout << "Name :" << customerList[feedbacks[i].first].getName() << endl;
        cout << "Feedback :" << feedbacks[i].second << endl;
    }
}
