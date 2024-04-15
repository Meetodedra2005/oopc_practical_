// concept used in this code is friend function otherwise all the things are same as practical 1

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class result;

class student
{
    char std_id[7], std_name[10];
    int sem;

    public:
        void getdata();
        void putdata();
        void get_result(result &);
        void put_result(result &);
};

class result
{
    int credit = 3,theory[3], practical[3], th_grade[3], pr_grade[3];
    float sgpa_th=0,sgpa_pr=0,sgpa,sgpa1,sgpa2;
    string sub[3], theoryg[3], practicalg[3];

    public:
    // make this functions as friend so we can access the member of student class
    friend void student::get_result(result &);
    friend void student::put_result(result &);
};

void student::getdata()
{
        // Geting the students primary data

    cout << "Enter your studentID : ";
    cin >> std_id;

    cout << "Enter your Name : ";
    cin >> std_name;

    cout << "Enter your semester : ";
    cin >> sem;

    cout << endl;
}

void student::putdata()
{
    // Displaying the primary data

    cout << "student ID \t" << ": " << std_id << endl;
    fflush(stdin);
    cout << "student name \t" << ": " << std_name << endl;
    cout << "semester \t" << ": " << sem << endl;
}

void student :: get_result(result &r)
{
    // Input subject names
    for (int i = 0; i < 3; i++)
    {
        fflush(stdin);
        cout << "Enter your subject " << i+1 << " ";
        getline(cin, r.sub[i]);
        fflush(stdin);
    }

    // Input r.theory and r.practical marks for each subject

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            if (j % 2 == 0)
            {
                cout << "Enter your marks of subject " << i + 1 << " theory marks : ";
                cin >> r.theory[i];
            }
            else
            {
                cout << "Enter your marks of subject " << i + 1 << " practical marks : ";
                cin >> r.practical[i];
            }
        }
    }

    // Calculate the grades according to marks

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            if (j % 2 == 0)
            {
                if (r.theory[i] >= 80)
                {
                    r.theoryg[i] = "AA";
                    r.th_grade[i] = 10;
                }
                else if (r.theory[i] < 80 && r.theory[i] >= 73)
                {
                    r.theoryg[i] = "AB";
                    r.th_grade[i] = 9;
                }
                else if (r.theory[i] < 73 && r.theory[i] >= 66)
                {
                    r.theoryg[i] = "BB";
                    r.th_grade[i] = 8;
                }
                else if (r.theory[i] < 66 && r.theory[i] >= 60)
                {
                    r.theoryg[i] = "BC";
                    r.th_grade[i] = 7;
                }
                else if (r.theory[i] < 60 && r.theory[i] >= 55)
                {
                    r.theoryg[i] = "CC";
                    r.th_grade[i] = 6;
                }
                else if (r.theory[i] < 55 && r.theory[i] >= 50)
                {
                    r.theoryg[i] = "CD";
                    r.th_grade[i] = 5;
                }
                else if (r.theory[i] < 50 && r.theory[i] >= 45)
                {
                    r.theoryg[i] = "DD";
                    r.th_grade[i] = 4;
                }
                else
                {
                    r.theoryg[i] = "FF";
                    r.th_grade[i] = 0;
                }
            }
            else
            {
                if (r.practical[i] >= 80)
                {
                    r.practicalg[i] = "AA";
                    r.pr_grade[i] = 10;
                }
                else if (r.practical[i] < 80 && r.practical[i] >= 73)
                {
                    r.practicalg[i] = "AB";
                    r.pr_grade[i] = 9;
                }
                else if (r.practical[i] < 73 && r.practical[i] >= 66)
                {
                    r.practicalg[i] = "BB";
                    r.pr_grade[i] = 8;
                }
                else if (r.practical[i] < 66 && r.practical[i] >= 60)
                {
                    r.practicalg[i] = "BC";
                    r.pr_grade[i] = 7;
                }
                else if (r.practical[i] < 60 && r.practical[i] >= 55)
                {
                    r.practicalg[i] = "CC";
                    r.pr_grade[i] = 6;
                }
                else if (r.practical[i] < 55 && r.practical[i] >= 50)
                {
                    r.practicalg[i] = "CD";
                    r.pr_grade[i] = 5;
                    
                }
                else if (r.practical[i] < 50 && r.practical[i] >= 45)
                {
                    r.practicalg[i] = "DD";
                    r.pr_grade[i] = 4;
                }
                else
                {
                    r.practicalg[i] = "FF";
                    r.pr_grade[i] = 0;
                }
            }
        }
    }
}

void student::put_result(result &r)
{
    // Display the subject details with grades

    cout << setw(45) << "\ttheory\tpractical" << endl;

    for (int i = 0; i < 3; i++)
    {
        cout << left << setw(30) << r.sub[i] << ": " << r.theoryg[i] << "\t" << r.practicalg[i] << endl;
    }

    // calculatiang sgpa

    for (int i = 0; i < 3; i++)
    {
        r.sgpa_th = r.sgpa_th + (r.th_grade[i] * r.credit);
        r.sgpa_pr = r.sgpa_pr + (r.pr_grade[i]* r.credit);    
    }

    cout << endl;

    r.sgpa1 = r.sgpa_th/(r.credit*3);
    r.sgpa2 = r.sgpa_pr/(r.credit*3);

    r.sgpa = (r.sgpa1+r.sgpa2)/2;

    cout << fixed << setprecision(2) << "sgpa : " << r.sgpa << endl;

}
int main()
{
    student s;
    result r;

    s.getdata();
    s.get_result(r);
    s.putdata();
    s.put_result(r);
}