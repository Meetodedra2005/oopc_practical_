#include "non_teach_employee.h"
#include <iostream>
#include <stdlib.h>
#include <string>
#include <iomanip>

using namespace std;

void non_teach_employee :: getdata()
{

    employee::getdata();

    cout << "Enter salary :- ";
    cin >> salary;
}

void non_teach_employee :: putdata()
{
    cout << endl << "---------------Data of non teaching staff---------------" << endl;
    employee::putdata();

    cout << endl << "salary    : " << salary << endl ;
    cout << endl
         << "------------------------------" << endl;
}

int non_teach_employee :: findid(int id_temp, int a)
{
    a = employee::findid(id_temp, a);
    return a;
}

