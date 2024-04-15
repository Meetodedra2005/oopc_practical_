// Here we use the concept of basic to class convertion

#include <iostream>
#include <iomanip>

using namespace std;

class emp_experiance
{
    int experiance_year;
    int experiance_month;
    public:
    void getdata();
    operator float();
};

// teke the data

void emp_experiance :: getdata()
{
    cout << "Enter the experiance year of employee : ";
    cin >> experiance_year;

    cout << "Enter the experiance month of employee : ";
    cin >> experiance_month;
}

// convert the data to basic data type

emp_experiance::operator float()
{
    float exp;
    exp = experiance_year;
    exp += (experiance_month*8.33)/100;
    return exp;
}

int main()
{
    emp_experiance emp;
    emp.getdata();

    float Experince;
    Experince = emp; // here we done the convertion

    cout << "The total experiance of employee is : " << Experince;
    return 0;
}