// Practical 1 : Develop a C++ program for CHARUSAT student marksheet generator
// Which contain this much data
/* Student ID (alphanumeric of length 6 to 7),
Student name (string without space),
Semester (number between 1 to 8),
3 Subject names (string with space),
Theory and practical marks of all subject(number between 0 to 100)*/

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main()
{
    // Decalartion of some variable according to given conditions

    char std_id[7], std_name[10];
    int sem=0, credit = 3,theory[3], practical[3], th_grade[3], pr_grade[3];
    float sgpa = 0;
    string sub[3], theoryg[3], practicalg[3];

    // Geting the students primary data

    cout << "Enter your studentID ";
    cin >> std_id;

    cout << "Enter your Name ";
    cin >> std_name;

    cout << "Enter your semester ";
    cin >> sem;

    cout << endl;

    // Input subject names

    for (int i = 0; i < 3; i++)
    {
        fflush(stdin);
        cout << "Enter your subject " << i+1 << " ";
        getline(cin, sub[i]);
        fflush(stdin);
    }

    // Input theory and practical marks for each subject

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            if (j % 2 == 0)
            {
                cout << "Enter your marks of subject " << i + 1 << " theory marks" << endl;
                cin >> theory[i];
            }
            else
            {
                cout << "Enter your marks of subject " << i + 1 << " practical marks " << endl;
                cin >> practical[i];
            }
        }
    }

    // Displaying the primary data

    cout << "student ID \t" << ": " << std_id << endl;
    cout << "student name \t" << ": " << std_name << endl;
    cout << "semester \t" << ": " << sem << endl;

    // Calculate the grades according to marks

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            if (j % 2 == 0)
            {
                if (theory[i] >= 80)
                {
                    theoryg[i] = "AA";
                    th_grade[i] = 10;
                }
                else if (theory[i] < 80 && theory[i] >= 73)
                {
                    theoryg[i] = "AB";
                    th_grade[i] = 9;
                }
                else if (theory[i] < 73 && theory[i] >= 66)
                {
                    theoryg[i] = "BB";
                    th_grade[i] = 8;
                }
                else if (theory[i] < 66 && theory[i] >= 60)
                {
                    theoryg[i] = "BC";
                    th_grade[i] = 7;
                }
                else if (theory[i] < 60 && theory[i] >= 55)
                {
                    theoryg[i] = "CC";
                    th_grade[i] = 6;
                }
                else if (theory[i] < 55 && theory[i] >= 50)
                {
                    theoryg[i] = "CD";
                    th_grade[i] = 5;
                }
                else if (theory[i] < 50 && theory[i] >= 45)
                {
                    theoryg[i] = "DD";
                    th_grade[i] = 4;
                }
                else
                {
                    theoryg[i] = "FF";
                    th_grade[i] = 0;
                }
            }
            else
            {
                if (practical[i] >= 80)
                {
                    practicalg[i] = "AA";
                    pr_grade[i] = 10;
                }
                else if (practical[i] < 80 && practical[i] >= 73)
                {
                    practicalg[i] = "AB";
                    pr_grade[i] = 9;
                }
                else if (practical[i] < 73 && practical[i] >= 66)
                {
                    practicalg[i] = "BB";
                    pr_grade[i] = 8;
                }
                else if (practical[i] < 66 && practical[i] >= 60)
                {
                    practicalg[i] = "BC";
                    pr_grade[i] = 7;
                }
                else if (practical[i] < 60 && practical[i] >= 55)
                {
                    practicalg[i] = "CC";
                    pr_grade[i] = 6;
                }
                else if (practical[i] < 55 && practical[i] >= 50)
                {
                    practicalg[i] = "CD";
                    pr_grade[i] = 5;
                    
                }
                else if (practical[i] < 50 && practical[i] >= 45)
                {
                    practicalg[i] = "DD";
                    pr_grade[i] = 4;
                }
                else
                {
                    practicalg[i] = "FF";
                    pr_grade[i] = 0;
                }
            }
        }
    }

    // Display the subject details with grades

    cout << setw(45) << "\ttheory\tpractical" << endl;

    for (int i = 0; i < 3; i++)
    {
        cout << left << setw(30) << sub[i] << ": " << theoryg[i] << "\t" << practicalg[i] << endl;
    }

    // calculatiang sgpa

    for (int i = 0; i < 3; i++)
    {
        sgpa = sgpa + (th_grade[i] * credit)+ (pr_grade[i] * credit);       
    }

    cout << endl;

    sgpa = sgpa / (credit*6);

    cout << fixed << setprecision(2) << "sgpa : " << sgpa << endl;
    
}