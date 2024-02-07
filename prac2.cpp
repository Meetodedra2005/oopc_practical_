//Practical 2 : Develop a C++ program store and retrieve CHARUSAT employee details.
// Which contain this much data
/*
Number of employee (number between 0 to 1000), 
Employee ID (4 digit number), 
Employee name(string with space), 
Qualification (string without space), 
Experience (factional point number), 
Contact number (10 digit number)
*/

#include <iostream>
#include <iomanip>
#include <string>
#include <cstring>
#include <cstdlib>

using namespace std;

class Employee{
private:
    char contact[11];
    string Employee_name, Qualifiaction, Employee_id;
    float Experiance;

public:
    void Getinput();        // To get the data from user
    void PutData(string);   // To compare the employee id
    void display();     // To display the employee details
};

void Employee::Getinput()
{
    fflush(stdin);

s:

    cout << left << setw(15) << "Employee Id " << " : ";
    getline(cin, Employee_id);

    fflush(stdin);  

    cout << endl;

    if (Employee_id.length() != 4)
    {

        cout << "*********************************" << endl;

        cout << endl << "ERROR : ENTERED EMPLOYEE ID IS NOT VALID" << endl;

        cout << endl << "*********************************" << endl;
        goto s;
    }
    else
    {
        cout << "................................." << endl;

        cout << endl;
    }

    cout << left << setw(15) << "Employee Name " << " : ";
    getline(cin, Employee_name);

    cout << left << setw(15) << "Qualification " << " : ";
    getline(cin, Qualifiaction);

    cout << left << setw(15) << "Experience " << " : ";  
    cin >> Experiance;

    cin.ignore();

    cout << left << setw(15) << "Contact " << " : ";
    cin.getline(contact, 11);

    cout << endl;

    cout << "................................." << endl;

    cout << endl;
}

void Employee::PutData(string em_id)
{
    if (Employee_id == em_id)
    {
        display();
    }
}

void Employee::display()
{
    cout << endl;

    cout << left << setw(15) << "Employee Id " << " : " << Employee_id << endl << endl;

    cout << "................................." << endl;

    cout << left << setw(15) << "Employee Name " << " : " << Employee_name << endl << endl;

    cout << left << setw(15) << "Qualification " << " : " << Qualifiaction << endl << endl;

    cout << left << setw(15) << "Experience " << " : " << Experiance << endl << endl;

    cout << left << setw(15) << "Contact " << " : " << contact << endl << endl;

    cout << "................................." << endl;

    cout << endl;
}

int main()
{

    int number = 0, em_number;
    char continue_input;
    string Employee_id;

    cout << "Enter the total number of Employees : ";
    cin >> em_number;       // get the total number of students

    Employee employee[em_number];

    do
    {
        employee[number].Getinput(); // call the function to get the employee details from user

        if (number < em_number)
        {
            cout << "Press 'y' or 'Y' to continue input. Press 'N' to Exit : ";
            cin >> continue_input;      // continue inpur for user wants to continue or not

            cout << endl;

            if (continue_input == 'n' || continue_input == 'N')
            {
                break;
            }
        }

        number++;

    } while (continue_input == 'y' || continue_input == 'Y' || number < em_number);

    do
    {

        a:

        cout << "Enter the employee id : ";
        cin.ignore();  
        getline(cin, Employee_id);

        if (Employee_id.length() != 4)  // calculate the length of id number 
        {
        cout << "*********************************" << endl;

        cout << endl << "ERROR : ENTERED EMPLOYEE ID DOES NOT EXIST" << endl;

        cout << endl << "*********************************" << endl;

        goto a;
        }
    

        for (int i = 0; i < em_number; i++)
        {
            employee[i].PutData(Employee_id); // call the function to compare the id number
        }

        cout << "Press 'y' or 'Y' to continue input. Press 'N' to Exit : ";
        cin >> continue_input;       // continue inpur for user wants to continue or not

        cout << endl;

        if (continue_input == 'n' || continue_input == 'N')
        {
            exit(0);
        }

        number ++;
    } while (number < em_number);
    

    return 0;
}