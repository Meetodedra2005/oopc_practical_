#include "teaching_employee.h"
#include <iostream>
#include <stdlib.h>
#include <string>
#include <iomanip>

using namespace std;

void teaching_employee :: getdata_t()
{
    getdata_e();

    cout << "Enter designation of an employee :- ";
    fflush(stdin);
    getline(cin,designation);

    cout << "Enter specialization of an employee :- ";
    fflush(stdin);
    getline(cin,specialization);

    cout << "Enter pay scale of an employee :- ";
    fflush(stdin);
    getline(cin,pay_scale);

}

void teaching_employee :: putdata_t()
{
    cout << endl << "---------------Data of teaching staff---------------" << endl;
    putdata_e();

    cout << endl << "Designation    : " << designation << endl;
    cout << endl << "Specialization : " << specialization << endl;
    cout << endl << "Pay Scale      : " << pay_scale << endl;
    cout << endl
         << "------------------------------" << endl;
}
int teaching_employee :: findid(int id_temp, int a)
{
    a = employee::findid( id_temp, a);
    return a;
}
