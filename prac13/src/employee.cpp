#include "employee.h"
#include <iostream>
#include <stdlib.h>
#include <string>
#include <iomanip>

using namespace std;

void employee :: getdata_e()
{
    m:
    cout << "Enter id of an employee : ";
    cin >> id;
    if(id > 1000)
    {
        cout << "Please enter the valid id number";
        goto m;
    }

    cout << "Enter name of an employee : ";
    fflush(stdin);
    getline(cin, name);

    cout << "Enter qualification of an employee : ";
    fflush(stdin);
    getline(cin, qualification);

    cout << "Enter experience of an employee  : ";
    cin >> experiance;

    ava_exp += experiance;
    cout << "Enter contact number of an employee : ";
    cin >> number;
}

 void employee :: putdata_e()
{
    cout << endl
         << "Employee id    : " << id;
    cout << endl
         << "-------------------------------" << endl;
    cout << endl
         << "Employee Name  : " << name << endl;
    cout << endl
         << "Qualification  : " << qualification << endl;
    cout << endl
         << "Experience     : " << experiance << " year" << endl;
    cout << endl
         << "Contact number : " << number << endl;

}

int employee :: findid(int id_temp, int a)
{
    a = 0;
    if (id == id_temp)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}
void employee :: ava_exp_empl(int n)
{
    cout << "Avarage exprience of employee : " << ava_exp / n << endl ;
}
