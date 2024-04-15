// concept used in this program is basic to class convertion

#include <iostream>
#include <iomanip>

using namespace std;

class emp_experiance
{
    int experiance_year;
    int experiance_month;

    public:
        emp_experiance()
        {
            experiance_month = 0;
            experiance_month = 0;
        }
        emp_experiance(float &);//parameterized constructor to convert the basic datatype's value to class's data members
        void putdata();
};

emp_experiance :: emp_experiance(float &experaince)
{
    experiance_year = experaince;
    experiance_month = ((experaince - experiance_year)*100)/8.33;//use to calculate the month from the fractional
}

void emp_experiance::putdata()
{
    cout << "The expeeriance of Employee is " << experiance_year << " years " << experiance_month << " month ";
}

int main()
{
    float Exp;

    cout << "Enter the experinace of employee : ";
    cin >> Exp;

    emp_experiance emp(Exp);
    emp.putdata();
    return 0;
}