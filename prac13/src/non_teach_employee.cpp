#include "non_teach_employee.h"
#include <iostream>
#include <stdlib.h>
#include <string>
#include <iomanip>

using namespace std;

void non_teach_employee :: getdata_n_t()
{

    getdata_e();

    cout << "Enter salary :- ";
    cin >> salary;
}

void non_teach_employee :: putdata_n_t()
{
    cout << endl << "---------------Data of non teaching staff---------------" << endl;
    putdata_e();

    cout << endl << "salary    : " << salary << endl ;
    cout << endl
         << "------------------------------" << endl;
}

int non_teach_employee :: findid(int id_temp, int a)
{
    a = employee::findid(id_temp, a);
    return a;
}
