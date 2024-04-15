#include <iostream>
#include <string>
#include "employee.h"
#include "teaching_employee.h"
#include "non_teach_employee.h"

using namespace std;

float employee::ava_exp = 0.0;

int main()
{
    int i = 0, id, te_emp,nte_emp;
    int ft,fnt;
    int ch;


    cout << "Enter number of teaching employee : ";
    cin >> te_emp;

    cout << "Enter number of non teaching employee : ";
    cin >> nte_emp;

    teaching_employee teaching_emp[500];
    non_teach_employee non_teach_emp[500];

    // To get the employee data from user

    for (int i=0; i<te_emp; i++)
    {
        cout << endl << "Enter teaching " << i + 1 << " employee detail \n" << endl;
        teaching_emp[i].getdata();
    }

    for (int i=0; i<te_emp; i++)
    {
        cout << endl << "Enter not teaching " << i + 1 << " employee detail \n" << endl;
        non_teach_emp[i].getdata();
    }
    system("cls");

    m:

    cout << endl << " Enter 1 to get employee detail \n Enter 2 for get avarage experience of employee   \n Enter 3 for exit" << endl;
    cout << endl << "Number :- ";
    cin >> ch;

    while (1)
    {
        switch (ch)
        {
        case 1:
            cout << "Enter an employee id : ";
            cin >> id;

            // Find the employee according to entered id
            for (i = 0; i < te_emp; i++)
            {
                ft = teaching_emp[i].findid(id, ft);
                if (ft == 1)
                {
                    teaching_emp[i].putdata();
                    break;
                }
            }

            for (i = 0; i < nte_emp; i++)
            {
                fnt = non_teach_emp[i].findid(id, fnt);
                if (fnt == 1)
                {
                    non_teach_emp[i].putdata();
                    break;
                }
            }

            if (ft == 0 && fnt==0)
            {
                cout << endl
                     << "******************************" << endl;
                cout << endl
                     << "ERROR : ENTERED EMPLOYEE ID DOES NOT EXIST " << endl;
                cout << endl
                     << "******************************" << endl;
            }
            goto m;
            break;

        case 2:
            employee ::ava_exp_empl(te_emp+nte_emp);
            goto m;
            break;

        case 3:
            exit(0);

        default:
            cout << "Enter valid number ";
            goto m;
            break;
        }
        break;
    }

    return 0;
}

