#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

// main parent class to manage all the basic data's

class product
{
protected:
    int product_id;
    string product_name, product_manufacture;
    float price;

public:
    product()
    {
        product_id = 0;
        price = 0;
    }
    product(int id, string p_name, string manu, float price)
    {
        product_id = id;
        product_name = p_name;
        product_manufacture = manu;
        this->price = price;
    }

    virtual void putdata() = 0; // pure virtual function to declare class as abstract class
};

// class to manage the data of smart watch & inherited from product

class smartwatch : public product
{
protected:
    float dial_size;

public:
    smartwatch() {}
    smartwatch(int id, string p_name, string manu, float price, float size) : product(id, p_name, manu, price)
    {
        dial_size = size;
    }
    void putdata();
};

void smartwatch::putdata()
{
    cout << left << setw(5) << product_id << " : " << left << setw(20) << product_name << " : " << left << setw(10) << product_manufacture << left << setw(8) << price << " : " << left << setw(3) << dial_size << endl;
}

// class to manage the data of bedsheet watch & inherited from product

class bedsheet : public product
{
protected:
    float height, width;

public:
    bedsheet() {}
    bedsheet(int id, string p_name, string manu, float price, float h, float w) : product(id, p_name, manu, price)
    {
        height = h;
        width = w;
    }
    void putdata();
};

void bedsheet::putdata()
{
    cout << left << setw(5) << product_id << " : " << left << setw(20) << product_name << " : " << left << setw(10) << product_manufacture << left << setw(8) << price << " : " << left << setw(5) << height << " : " << left << setw(5) << width << endl;
}

int main()
{
    int product_id, choice;
    string product_name, product_manufacture;
    float price, size, height, width;

    cout << "Enter 1 : Smart watch menu " << endl;
    cout << "Enter 2 : Bedsheet menu" << endl;
    cout << "Enter your choice : ";
    cin >> choice;

    switch (choice)
    {
    case 1:
    {
        cout << "********** ENTER SMART WATCH MENU **********" << endl;
        cout << "Enter product id: ";
        cin >> product_id;

        cout << "Enter product name: ";
        cin.ignore();
        getline(cin, product_name);

        cout << "Enter product manufacturer: ";
        getline(cin, product_manufacture);

        cout << "Enter product price: ";
        cin >> price;

        cout << "Enter the dial size: ";
        cin >> size;

        smartwatch s(product_id, product_name, product_manufacture, price, size);
        s.putdata();
        break;
    }
    case 2:
    {
        cout << "********** ENTER BEDSHEET MENU **********" << endl;
        cout << "Enter product id: ";
        cin >> product_id;

        cout << "Enter product name: ";
        cin.ignore(); // Ignore newline character from previous input
        getline(cin, product_name);

        cout << "Enter product manufacturer: ";
        getline(cin, product_manufacture);

        cout << "Enter product price: ";
        cin >> price;

        cout << "Enter bedsheet height: ";
        cin >> height;

        cout << "Enter bedsheet width: ";
        cin >> width;

        bedsheet b(product_id, product_name, product_manufacture, price, height, width);
        b.putdata();
        break;
    }
    default:
        cout << "Invalid choice" << endl;
        break;
    }

    return 0;
}