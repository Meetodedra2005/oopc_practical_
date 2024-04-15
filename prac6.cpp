#include <iostream>
#include <stdlib.h>
#include <iomanip>
#include <string>

using namespace std;

class Employee
{
private:
    char contact[11];
    string Employee_name, Qualifiction, Employee_id;
    float Experiance;
    static float average_exp;

public:
    void Getinput();        // To get the data from user
    void PutData(string);   // To compare the employee id
    void display() const;     // To display the employee details
    static void dis_average(int);
};

void Employee :: Getinput()
{

    _flushall();
    cout << endl << "Enter the id of Employee : ";
    getline(cin,Employee_id);

    if (Employee_id.length() != 4)
    {
        cout<< endl << "invalid id number. Please enter valid id number "<< endl;
    }

    cout << endl << "Enter the name of Employee : ";
    getline(cin,Employee_name);

    cout << endl << "Enter the qualification of Employee : ";
    getline(cin,Qualifiction);

    cout << endl << "Enter the Experiance of Employee : ";
    cin >> Experiance;

    average_exp += Experiance; 

    cout << endl << "Enter the contact number of Employee : " << endl;
    cin >> contact;

    cout << "............................................................." << endl;
}

// to find the id of employee.

void Employee :: PutData(string Em_id)
{
    if (Employee_id == Em_id)
    {
        display();
    }
}

// here we use const keyword so we cant change value from this function

void Employee::display() const
{
    cout << endl;

    cout << left << setw(15) << "Employee Id " << " : " << Employee_id << endl << endl;

    cout << "................................." << endl;

    cout << left << setw(15) << "Employee Name " << " : " << Employee_name << endl << endl;

    cout << left << setw(15) << "Qualification " << " : " << Qualifiction << endl << endl;

    cout << left << setw(15) << "Experience " << " : " << Experiance << endl << endl;

    cout << left << setw(15) << "Contact " << " : " << contact << endl << endl;

    cout << "................................." << endl;

    cout << endl;
}

//function to display and claculate the average

void Employee :: dis_average(int n)
{
    average_exp /= n;
    cout << "Average experiance is : " << average_exp << endl ;
}

float Employee :: average_exp = 0.0;

int main()
{
    int em_number,choise;
    string em_id;

    cout<< endl << "Enter the number of Employee : ";
    cin >> em_number;

    Employee *emplpoyee = new Employee[em_number];

    for (int i = 0; i < em_number; i++)
    {
        emplpoyee[i].Getinput();
    }

    system("cls");

    c:

    cout << endl << "Enter 1 to get the data of employee" << endl;
    cout << "Enter 2 to get the average experiance" << endl;
    cout << "Enter 3 to exit" << endl;
    cout << "Enter your choise : ";
    cin >> choise;


        switch (choise)
        {
        case 1:
            cout << "Enter the employee id : ";
            cin.ignore();
            getline(cin,em_id);

            if (em_id.length() != 4)  // calculate the length of id number
        {
            cout << "*********************************" << endl;
            cout << endl << "ERROR : ENTERED EMPLOYEE ID DOES NOT EXIST" << endl;
            cout << endl << "*********************************" << endl;
            goto c;
        }
            

            for (int i = 0; i < em_number; i++)
            {
                emplpoyee[i].PutData(em_id);
            }
            goto c;
            break;

        case 2:
            Employee :: dis_average(em_number);
            goto c;
            break;

        case 3: 
            system("cls");
            exit(0);
            break;

        }

    return 0;
}