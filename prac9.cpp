// concept used in his program is class to class convertion

#include <iostream>
#include <iomanip>

using namespace std;

// previous declaration to inform that this class is declared after certain code
class centi_con;

class mili_con
{
    float mm;
    public:
        mili_con()//default constructor
        {
            mm = 0;
        }
        mili_con(centi_con &);// pearmeterized constructor to store converted unit
        void getdata();
        float getmili();// function which convert the unit 
        void putdata();
};

class centi_con 
{
    float cm;
    public:
        centi_con()//defualt constructor
        {
            cm=0;
        }
        centi_con(mili_con &);// pearmeterized constructor to store converted unit
        void getdata();
        float getcenti();// function which convert the unit 
        void putdata();
};

void mili_con::getdata()
{
    cout << "Enter measurment in mm : ";
    cin >> mm;
}

mili_con::mili_con(centi_con &c)
{
    mm = c.getcenti();
}

float mili_con :: getmili()
{
    return mm/10;
}

void mili_con ::putdata()
{
    cout << "Meauserment in mm : " << mm;
}


void centi_con::getdata()
{
    cout << "Enter measurement in cm : ";
    cin >> cm;
}

centi_con :: centi_con(mili_con &m)
{
    cm = m.getmili();
}

void centi_con::putdata()
{
    cout << "measurment in cm : " << cm;
}

float centi_con :: getcenti()
{
    return cm*10;
}

int main()
{
    centi_con c1;
    mili_con m;
    int choice;

    cout << "Enter 1 : mm to cm convertion" << endl;
    cout << "Enter 2 : cm to mm convertion" << endl;
    cout << "Enter your choice : ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        m.getdata();
        c1 = m;
        c1.putdata();
        break;

    case 2:
        c1.getdata();
        m = c1;
        m.putdata();
    default:
        break;
    }
    return 0;
}