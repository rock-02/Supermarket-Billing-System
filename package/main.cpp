#include <bits/stdc++.h>
#include "supermarket.h"
#include "errorHandler.h"
#include "Person.h"
#include "Customer.h"
#include "Cashier.h"
#include "Product.h"
#include "shoppingCart.h"
#include "admin.h"

using namespace std;

vector<Customer> customerList;
void menu(vector<Product> &products, Supermarket &supermarket, vector<pair<int, string>> feedbacks)
{
    int choice;
    string email;
    string password;
    cout << "\t\t\t\t______________________________________\n";
    cout << "\t\t\t\t                                      \n";
    cout << "\t\t\t\t          Supermarket Main Menu       \n";
    cout << "\t\t\t\t                                      \n";
    cout << "\t\t\t\t______________________________________\n";
    cout << "\t\t\t\t                                      \n";
    cout << "\t\t\t\t|  1) Administrator   |\n";
    cout << "\t\t\t\t|                     |\n";
    cout << "\t\t\t\t|  2) Buyer           |\n";
    cout << "\t\t\t\t|                     |\n";
    cout << "\t\t\t\t|  3) Exit            |\n";
    cout << "\t\t\t\t|                     |\n";
    cout << "\n\t\t\t Please select!";
    cin >> choice;

    switch (choice)
    {
    case 1:
        cout << "\t\t\t Please Login \n";
        cout << "\t\t\t Enter Email   \n";
        cin >> email;
        cout << "\t\t\t Password       \n";
        cin >> password;

        if (email == "admin@example.com" && password == "admin@123")
        {
            while (1)
            {
                cout << "\t\t\t\t______________________________________\n";
                cout << "\t\t\t\t          Supermarket                 \n";
                cout << "\t\t\t\t______________________________________\n";
                cout << "\t\t\t\t                                      \n";
                cout << "\t\t\t\t|  1) Create Product  |\n";
                cout << "\t\t\t\t|                     |\n";
                cout << "\t\t\t\t|  2) Modify Product  |\n";
                cout << "\t\t\t\t|                     |\n";
                cout << "\t\t\t\t|  3) Delete Product  |\n";
                cout << "\t\t\t\t|                     |\n";
                cout << "\t\t\t\t|  4) Product Stocks  |\n";
                cout << "\t\t\t\t|                     |\n";
                cout << "\t\t\t\t|  5) View Feedbacks  |\n";
                cout << "\t\t\t\t|                     |\n";
                cout << "\t\t\t\t|  6) Exit            |\n";
                cout << "\t\t\t\t|                     |\n";
                cout << "\n\t\t\t Please select!";
                int option;
                cin >> option;
                if (option == 1)
                {
                    admin::addProduct(products);
                }
                else if (option == 2)
                {
                    cout << "Enter Position to Modify the Product Details\n"
                         << endl;
                    for (int i = 0; i < products.size(); i++)
                    {
                        cout << i + 1 << " => " << products[i].name << endl;
                    }
                    int pos;
                    cin >> pos;
                    admin::modifyProductByIndex(products, pos - 1);
                }
                else if (option == 3)
                {
                    cout << "Enter Position to delete the Product\n"
                         << endl;
                    for (int i = 0; i < products.size(); i++)
                    {
                        cout << i + 1 << " => " << products[i].name << endl;
                    }
                    int pos;
                    cin >> pos;
                    admin::deleteProductByIndex(products, pos - 1);
                }
                else if (option == 4)
                {
                    admin::productDetailsAndStocks(products);
                }
                else if (option == 5)
                {
                    admin::viewFeedbacks(customerList, feedbacks);
                }
                else
                {
                    cout << "------Completed ----" << endl;
                    break;
                }
            }
        }
        else
        {
            cout << "Invalid email/password";
        }
        break;
    case 2:
    {
        int n;
        cout << "+--------------------------+" << endl;
        cout << "|        Customer          |" << endl;
        cout << "|        Details           |" << endl;
        cout << "+--------------------------+" << endl;
        string name, identifier, mb;
        cout << "Name : ";
        cin >> name;
        cout << endl;
        cout << "Identifier  : ";
        cin >> identifier;
        cout << endl;
        cout << "Contact Info(Mobile NUmber): ";
        cin >> mb;
        for (int idx = 0; idx < customerList.size(); idx++)
        {
            if ((customerList[idx].getIdentifier().compare(identifier)) == 0)
            {
                cout << "\t\t\t\t***************************************\n";
                cout << "\t\t\t\t*          Welcome Back               *\n";
                cout << "\t\t\t\t***************************************\n";
                cout << customerList[idx].getName() << endl;
                n = idx;
            }
        }

        customerList.push_back(Customer(identifier, name, mb));
        n = customerList.size() - 1;
        while (1)
        {
            cout << "\t\t\t\t______________________________________\n";
            cout << "\t\t\t\t          Supermarket                 \n";
            cout << "\t\t\t\t______________________________________\n";
            cout << "\t\t\t\t                                      \n";
            cout << "\t\t\t\t|  1) Buy/Add Product          |\n";
            cout << "\t\t\t\t|                              |\n";
            cout << "\t\t\t\t|  2) Delete Product From Cart |\n";
            cout << "\t\t\t\t|                              |\n";
            cout << "\t\t\t\t|  3) View Cart                |\n";
            cout << "\t\t\t\t|                              |\n";
            cout << "\t\t\t\t|  4) Update/Reduce Quantity   |\n";
            cout << "\t\t\t\t|                              |\n";
            cout << "\t\t\t\t|  5) Exit                     |\n";
            cout << "\t\t\t\t|                              |\n";
            cout << "\n\t\t\t Please select!";
            int option;
            cin >> option;
            if (option == 1)
            {
                customerList[n].BuyProduct(products);
            }
            else if (option == 2)
            {
                customerList[n].removeFromCart(products);
            }
            else if (option == 3)
            {
                customerList[n].getCart().displayCartItems();
            }
            else if (option == 4)
            {
                customerList[n].updateQuantity();
            }
            else
            {
                cout << "Thank You\n"
                     << endl;
                break;
            }
        }
        if (customerList[n].getCart().getItems().size() > 0)
        {
            Cashier *c = new Cashier("001", "Rohith", "86601-78452");
            int coupon;
            cout << "Enter 1 If you have coupon id or 0 to continue" << endl;
            cin >> coupon;
            int f = 0;
            if (coupon == 1)
            {
                cout << "Enter  Coupon Id To get Discount of 5% on totalPrice" << endl;
                string couponId;
                cin >> couponId;
                if (couponId.compare("sup123") == 0)
                {
                    f = 1;
                    Cashier::scanProduct(customerList[n]);
                    // c->scanProduct(customerList[n]);
                    Cashier::generateBillReceipt(supermarket, customerList[n], 0.95);
                    // c->generateBillReceipt(supermarket, customerList[n]);
                }
            }
            if (f == 0)
            {
                cout << "Invalid Coupon Id\n";
                Cashier::scanProduct(customerList[n]);
                // c->scanProduct(customerList[n]);1
                Cashier::generateBillReceipt(supermarket, customerList[n], 1);
            }

            cout << "\t\t\t\t|__________________________________________________|\n";
            cout << "\t\t\t\t|  HEY,                                            |\n";
            cout << "\t\t\t\t|      Do You Want to give Feedback                |\n";
            cout << "\t\t\t\t|  Feed Back Matters us To Improve Our Service.    |\n";
            cout << "\t\t\t\t|  1) Yes                                          |\n";
            cout << "\t\t\t\t|  2) No                                           |\n";
            cout << "\t\t\t\t|__________________________________________________|\n";
            cout << "\n\t\t\t Please select!";
            int feedback;
            cin >> feedback;
            if (feedback == 1)
            {
                string feed;
                cin >> feed;
                feedbacks.push_back(make_pair(n, feed));
            }
            else
            {
                cout << "\t\t\t\t**********************************\n";
                cout << "\t\t\t\t* Hope You Will Give Next Time,  *\n";
                cout << "\t\t\t\t*             ThanK You          *\n";
                cout << "\t\t\t\t*       Visit Again              *\n";
                cout << "\t\t\t\t**********************************\n";
            }
        }
        else
        {
            cout << "\t\t\t\t**********************************\n";
            cout << "\t\t\t\t* Hope You Will Buy Next Time,   *\n";
            cout << "\t\t\t\t*             ThanK You          *\n";
            cout << "\t\t\t\t*       Visit Again              *\n";
            cout << "\t\t\t\t**********************************\n";
        }
        break;
    }
    case 3:
    {
        exit(0);
    }
    default:
    {
        // cout << "Please select from the given options";
        errorHandler(404, "Please select from the given options").printError();
    }
    }
}

int main()
{
    vector<pair<int, string>> feedbacks;
    // Create a supermarket
    Supermarket supermarket("My Supermarket", "123 Main Street", "contact@supermarket.com");
    // Display supermarket details
    supermarket.displayDetails();

    // Create a vector of products
    vector<Product> products;
    vector<string> names = {
        "Apple", "Banana", "Orange", "Grapes", "Mango", "Watermelon", "Pineapple",
        "Strawberry", "Blueberry", "Cherry", "Peach", "Pear", "Kiwi", "Plum", "Lemon",
        "Lime", "Raspberry", "Blackberry", "Cranberry", "Apricot", "Pomegranate",
        "Avocado", "Coconut", "Guava", "Passionfruit", "Dragonfruit", "Melon",
        "Fig", "Papaya", "Lychee", "Rambutan", "Durian", "Persimmon", "Mangosteen",
        "Starfruit", "Tangerine", "Kiwifruit", "Cantaloupe", "Honeydew", "Nectarine",
        "Redcurrant", "Quince", "Clementine", "Gooseberry", "Date", "Plantain",
        "Carambola", "Feijoa", "Boysenberry", "Loganberry", "Miracle fruit", "Mulberry",
        "Feijoa", "Elderberry", "Salak", "Sapote", "Tomato", "Pawpaw", "Jujube",
        "Kumquat", "Loquat", "Chayote", "Breadfruit", "Kiwano", "Cupuaçu", "Pitaya",
        "Açaí", "Jackfruit", "Ackee", "Bael", "Salmonberry", "Jabuticaba", "Longan",
        "Black sapote", "Cranberry", "Surinam cherry", "Yuzu", "Custard apple",
        "Melinjo", "Mamoncillo", "Mangaba", "Akee", "Pulasan", "Marang", "Chempedak",
        "Soursop", "Mamey sapote", "Tamarillo", "Strawberry guava", "Cupuaçu",
        "Kwai muk", "Kiwano", "Kiwifruit", "Kerson fruit", "Breadnut", "Bignay",
        "Bergeronnette", "Canistel", "Cempedak", "Cupuaçu", "Curuba", "Gac",
        "Imbe", "Kepel fruit", "Kiwifruit", "Kiwano", "Pepino", "Pitahaya",
        "Tomatillo", "Wampee", "Water apple", "Mangosteen", "Tamarillo",
        "Lingonberry", "Roselle", "Cranberry", "Currant", "Elderberry"};

    // srand(time(0));
    int namesIndex = 0;
    for (int i = 1; i <= 100; ++i)
    {
        // Generate a unique identifier for each product
        stringstream ss;
        ss << setw(3) << setfill('0') << i;
        string identifier = "PROD" + ss.str();

        // Get the name from the list and increment the index
        string name = names[namesIndex++];
        if (namesIndex == names.size())
            namesIndex = 0;

        // Random price and quantity for demonstration
        double price = 10.0 + (rand() % 1000) / 100.0;
        int quantity = rand() % 50 + 1;

        // Create the product and add it to the vector
        products.push_back(Product(identifier, name, price, quantity));
    }
    while (1)
    {
        menu(products, supermarket, feedbacks);
    }
    return 0;
}
