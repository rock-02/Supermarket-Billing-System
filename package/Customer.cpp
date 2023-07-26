#include "Customer.h"
#include "Product.h"
#include "errorHandler.h"

void Customer::BuyProduct(vector<Product> &products)
{
    ProductDeails(products);
    cout << "\t\t\t\t| Enter Index And Required Quantity Of Product  |\n";
    int pidx;
    cin >> pidx;
    int q;
    cin >> q;
    if (q < 0)
    {
        cout << "Quantity Should be More than 0" << endl;
        return;
    }
    this->cart.addProduct(products, pidx, q);
}

void Customer::removeFromCart(vector<Product> &products)
{
    ProductDeails(this->cart.getItems());
    cout << "\t\t\t\t| Enter Index Product  |\n";
    int pidx;
    cin >> pidx;
    if (pidx < 0 || pidx >= this->cart.getItems().size())
    {
        errorHandler(404, "Invalid Index").printError();
        return;
    }
    this->cart.removeProduct(this->cart.getItems()[pidx]);
}

void Customer::updateQuantity()
{
    cout << "\t\t\t\t| Enter Index And  Quantity Of Product to update in cart  |\n";
    int pidx;
    cin >> pidx;
    int q;
    cin >> q;
    if (q < 0)
    {
        errorHandler(404, "Quantity Should be More than 0").printError();
        return;
    }
    this->cart.updateQuantity(pidx, q);
}
