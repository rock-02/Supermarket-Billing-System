#include "Product.h"

void ProductDeails(const vector<Product> &products)
{
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
