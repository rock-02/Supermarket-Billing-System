#include "Cashier.h"
#include "Customer.h"
#include "ShoppingCart.h"
#include "supermarket.h"
#include <iomanip>

void Cashier::scanProduct(Customer c)
{
    vector<Product> Items = c.getCart().getItems();
    for (int i = 0; i < Items.size(); i++)
    {
        cout << "Product scanned: " << Items[i].name << endl;
    }
}

void Cashier::generateBillReceipt(Supermarket &supermarket, Customer c, double dis)
{
    ShoppingCart cart = c.getCart();
    cout << "=============================================================================================================" << endl;
    cout << "                                            Bill Receipt                                                     " << endl;
    cout << "=============================================================================================================" << endl;

    // Customer Details
    cout << "Customer Name: " << c.getName() << endl;
    cout << "Contact Info: " << c.getContactInfo() << endl;

    cout << "-------------------------------------------------------------------------------------------------------------" << endl;
    cout << left << setw(30) << "Product Name" << setw(15) << "Quantity" << setw(15) << "Price" << setw(15) << "Total" << endl;
    cout << "-------------------------------------------------------------------------------------------------------------" << endl;

    double totalCost = 0.0;
    for (int i = 0; i < cart.getItems().size(); i++)
    {
        double productTotal = cart.getItems()[i].price * cart.getItems()[i].quantity;
        totalCost += productTotal;
        cout << left << setw(30) << cart.getItems()[i].name << setw(15) << cart.getItems()[i].quantity
             << setw(15) << "$" << fixed << setprecision(2) << cart.getItems()[i].price
             << setw(15) << "$" << fixed << setprecision(2) << productTotal << endl;
    }

    cout << "-------------------------------------------------------------------------------------------------------------" << endl;
    cout << right << setw(60) << "Total Cost:" << setw(15) << "$" << fixed << setprecision(2) << totalCost * (1 - dis) << endl;
    cout << "=============================================================================================================" << endl;

    // Supermarket Details
    cout << "Supermarket Name: " << supermarket.getName() << endl;
    cout << "Address: " << supermarket.getAddress() << endl;
    cout << "Contact Info: " << supermarket.getContactInfo() << endl;
    cout << "=============================================================================================================" << endl;
}
