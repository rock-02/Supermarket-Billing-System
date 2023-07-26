#include "ShoppingCart.h"
#include "errorHandler.h" // Include the errorHandler class or forward declare it if already included in another header

void ShoppingCart::addProduct(std::vector<Product> &products, int pidx, int quantity)
{
    if (pidx >= products.size())
    {
        errorHandler(404, "Product NOT Found").printError();
    }
    else
    {
        if (products[pidx].quantity < quantity)
        {
            errorHandler(400, "Shortage of Items").printError();
        }
        else
        {
            products[pidx].quantity -= quantity;
            items.push_back(Product(products[pidx].identifier, products[pidx].name, products[pidx].price, quantity));
        }
    }
}

void ShoppingCart::displayCartItems() const
{
    if (items.empty())
    {
        std::cout << "The shopping cart is empty." << std::endl;
        return;
    }
    std::cout << " _______________________________________________________________________________________________________________________\n";
    std::cout << "|                                            Cart Items                                                                 |\n";
    std::cout << "|_______________________________________________________________________________________________________________________|\n";
    double sum = 0;
    std::cout << "Shopping Cart Items:" << std::endl;
    for (const auto &product : items)
    {
        sum += product.quantity * product.price;
        std::cout << "Product Name: " << product.name << ",   Quantity: " << product.quantity << ",  Price : " << product.price << ",  Total Cost: " << product.quantity * product.price << std::endl;
    }
    std::cout << " _______________________________________________________________________________________________________________________\n";
    std::cout << "|                                               Total Cost : " << sum << "                                                  |\n";
    std::cout << "|_______________________________________________________________________________________________________________________|\n";
}

void ShoppingCart::removeProduct(const Product &product)
{
    for (auto it = items.begin(); it != items.end(); ++it)
    {
        if (it->identifier == product.identifier)
        {
            items.erase(it);
            break;
        }
    }
}

void ShoppingCart::updateQuantity(int pidx, int nq)
{
    if (pidx >= items.size())
    {
        std::cout << "Product not found in your cart!" << std::endl;
    }
    else
    {
        items[pidx].quantity = nq;
    }
}

const std::vector<Product> &ShoppingCart::getItems() const
{
    return items;
}
