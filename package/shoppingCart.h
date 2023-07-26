#ifndef SHOPPINGCART_H
#define SHOPPINGCART_H

#include "Product.h" // Include the Product class or forward declare it if already included in another header

#include <vector>
#include <iostream>

class ShoppingCart
{
    std::vector<Product> items;

public:
    void addProduct(std::vector<Product> &products, int pidx, int quantity);
    void displayCartItems() const;
    void removeProduct(const Product &product);
    void updateQuantity(int pidx, int nq);
    const std::vector<Product> &getItems() const;
};

#endif // SHOPPINGCART_H
