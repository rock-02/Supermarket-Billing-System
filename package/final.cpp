#include <bits/stdc++.h>
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
class Person
{
protected:
    string identifier;
    string name;
    string contactInfo;

public:
    Person(const string &identifier, const string &name, const string &contactInfo)
        : identifier(identifier), name(name), contactInfo(contactInfo) {}

    string getName() const
    {
        return name;
    }
};

class Supermarket
{
    string name;
    string address;
    string contactInfo;

public:
    Supermarket(const string &name, const string &address, const string &contactInfo)
        : name(name), address(address), contactInfo(contactInfo) {}

    void displayDetails() const
    {
        cout << "Supermarket Name: " << name << endl;
        cout << "Address: " << address << endl;
        cout << "Contact Info: " << contactInfo << endl;
    }

    string getName() const
    {
        return name;
    }

    string getAddress() const
    {
        return address;
    }

    string getContactInfo() const
    {
        return contactInfo;
    }
};

class Product
{
public:
    string identifier;
    string name;
    double price;
    int quantity;

public:
    Product(const string &identifier, const string &name, double price, int quantity)
        : identifier(identifier), name(name), price(price), quantity(quantity) {}

    void displayDetails(bool displayHeader = false) const
    {
        if (displayHeader)
        {
            cout << "+---------------+----------------+-----------------+------------+\n";
            cout << "|" << setw(15) << "Product Name"
                 << "|" << setw(15) << "Identifier"
                 << "|" << setw(15) << "Price ($)"
                 << "|" << setw(12) << "Quantity"
                 << "|\n";
            cout << "+---------------+----------------+-----------------+------------+\n";
        }
        cout << "|" << setw(15) << name << "|" << setw(15) << identifier << "|" << setw(15) << price << "|" << setw(12) << quantity << "|\n";
        cout << "+---------------+----------------+-----------------+------------+\n";
    }

    void setName(const string &newName)
    {
        name = newName;
    }

    void setPrice(double newPrice)
    {
        price = newPrice;
    }

    void setIdentifier(const string &newIdentifier)
    {
        identifier = newIdentifier;
    }

    void setQuantity(int newQuantity)
    {
        quantity = newQuantity;
    }
};
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
class ShoppingCart
{
    vector<Product> items;

public:
    void addProduct(vector<Product> &products, int pidx, int quantity)
    {
        if (pidx >= products.size())
            // cout << "Product not found!" << endl;
            errorHandler(404, "Product NOT Found").printError();
        else
        {
            if (products[pidx].quantity < quantity)
            {
                // cout << "Shortage of Items" << endl;
                errorHandler(400, "Shortage of Items").printError();
            }
            else
            {
                products[pidx].quantity -= quantity;
                items.push_back(*(new Product(products[pidx].identifier, products[pidx].name, products[pidx].price, quantity)));
            }
        }
    }

    void displayCartItems() const
    {
        if (items.empty())
        {
            cout << "The shopping cart is empty." << endl;
            // errorHandler(403,"The Shooping Cart IS Empty").printError();
            return;
        }
        cout << " _______________________________________________________________________________________________________________________\n";
        cout << "|                                            Cart Items                                                                 |\n";
        cout << "|_______________________________________________________________________________________________________________________|\n";
        double sum = 0;
        cout << "Shopping Cart Items:" << endl;
        for (const auto &product : items)
        {
            sum += product.quantity * product.price;
            cout << "Product Name: " << product.name << ",   Quantity: " << product.quantity << ",  Price : " << product.price << ",  Total Cost: " << product.quantity * product.price << endl;
        }
        cout << " _______________________________________________________________________________________________________________________\n";
        cout << "|                                               Total Cost : " << sum << "                                                  |\n";
        cout << "|_______________________________________________________________________________________________________________________|\n";
    }

    void removeProduct(const Product &product)
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
    void updateQuantity(int pidx, int nq)
    {
        if (pidx >= this->items.size())
            cout << "Product not found In Your Cart!" << endl;
        else
        {
            this->items[pidx].quantity = nq;
        }
    }

    const vector<Product> &getItems() const
    {
        return items;
    }
};

class Customer : public Person
{
    ShoppingCart cart;

public:
    Customer(const string &identifier, const string &name, const string &contactInfo)
        : Person(identifier, name, contactInfo) {}

    ShoppingCart &getCart()
    {
        return cart;
    }
    string getIdentifier()
    {
        return this->identifier;
    }
    string getName()
    {
        return this->identifier;
    }
    void BuyProduct(vector<Product> &products)
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
    string getContactInfor()
    {
        return this->contactInfo;
    }
    void removeFromCart(vector<Product> &products)
    {
        ProductDeails(this->cart.getItems());
        cout << "\t\t\t\t| Enter Index Product  |\n";
        int pidx;
        cin >> pidx;
        if (pidx < 0 || pidx >= this->cart.getItems().size())
        {
            // cout << "Invalid Pidx" << endl;
            errorHandler(404, "Inavlid Index").printError();
            return;
        }
        this->cart.removeProduct(this->cart.getItems()[pidx]);
    }
    void updateQuantinty()
    {
        cout << "\t\t\t\t| Enter Index And  Quantity Of Product to update in cart  |\n";
        int pidx;
        cin >> pidx;
        int q;
        cin >> q;
        if (q < 0)
        {
            // cout << "Quantity Should be More than 0" << endl;
            errorHandler(404, "Quantity Should be More than 0").printError();
            return;
        }
        this->cart.updateQuantity(pidx, q);
    }
};

class Cashier : public Person
{
public:
    Cashier(const string &identifier, const string &name, const string &contactInfo)
        : Person(identifier, name, contactInfo) {}

    static void scanProduct(Customer c)
    {
        vector<Product> Items = c.getCart().getItems();
        for (int i = 0; i < Items.size(); i++)
        {
            cout << "Product scanned: " << Items[i].name << endl;
        }
    }

    static void generateBillReceipt(Supermarket &supermarket, Customer c, double dis)
    {
        ShoppingCart cart = c.getCart();
        cout << "=============================================================================================================" << endl;
        cout << "                                            Bill Receipt                                                     " << endl;
        cout << "=============================================================================================================" << endl;

        // Customer Details
        cout << "Customer Name: " << c.getName() << endl;
        cout << "Contact Info: " << c.getContactInfor() << endl;

        cout << "-------------------------------------------------------------------------------------------------------------" << endl;
        cout << left << setw(30) << "Product Name" << setw(15) << "Quantity" << setw(15) << "Price" << setw(15) << "Total" << endl;
        cout << "-------------------------------------------------------------------------------------------------------------" << endl;
        // const auto &product : cart.getItems()
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
        cout << right << setw(60) << "Total Cost:" << setw(15) << "$" << fixed << setprecision(2) << totalCost * (dis) << endl;
        cout << "=============================================================================================================" << endl;

        // Supermarket Details
        cout << "Supermarket Name: " << supermarket.getName() << endl;
        cout << "Address: " << supermarket.getAddress() << endl;
        cout << "Contact Info: " << supermarket.getContactInfo() << endl;
        cout << "=============================================================================================================" << endl;
    }
};

class admin
{
public:
    static void addProduct(vector<Product> &products)
    {
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
            cin >> name;
            int quantity;
            cin >> quantity;
            if (price < 0 || quantity < 0)
            {
                throw("while Quantity and Price Cannot be negative or 0\nTry Again");
                return;
            }
            Product *p = new Product(identifier, name, price, quantity);
            products.push_back(*p);
            cout << "Product Created Successfully" << endl;
        }
        catch (const char *e)
        {
            std::cerr << e << '\n';
        }
    }

    static void deleteProductByIndex(vector<Product> &products, int index)
    {
        if (index >= 0 && index < products.size())
        {
            vector<Product>::iterator it = products.begin() + index;
            products.erase(it);
            cout << "Product at index " << index << " deleted successfully.\n";
        }
        else
        {
            cout << "Invalid index. Cannot delete product.\n";
        }
    }

    static void ModifyProductByIndex(vector<Product> &products, int index)
    {
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
                        errorHandler(500, "Price Should Be Greater Than 0");
                    else
                        products[index].setPrice(newPrice);
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

    static void ProductDeailsAndStocks(const vector<Product> &products)
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
    static void viewFeedbacks(vector<Customer> &customerList, vector<pair<int, string>> &feedbacks)
    {
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
};
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
                    admin::ModifyProductByIndex(products, pos - 1);
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
                    admin::ProductDeailsAndStocks(products);
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
                customerList[n].updateQuantinty();
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
