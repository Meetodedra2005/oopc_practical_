// concept used here is in 2 type heritance multiple and hierarchical
// also use virtual keyword to avoid the duplicated base class subobject that occurs with the

#include <iostream>
#include <iomanip>
#include <stdlib.h>
#include <string>

using namespace std;

class literature
{
private:
    string id, name;

public:
    void getdata();
    void putdata();
};

void literature ::getdata()
{
    fflush(stdin);
    cout << "Id : ";
    getline(cin, id);
    fflush(stdin);

    cout << "Name : ";
    fflush(stdin);
    getline(cin, name);
    fflush(stdin);
}

void literature ::putdata()
{
    cout << left << setw(5) << id << left << setw(25) << name;
}

class e_literature : public virtual literature
{
private:
    string doi;

public:
    void getdata();
    void putdata();
};

void e_literature::getdata()
{
    cout << "Doi : ";
    fflush(stdin);
    getline(cin, doi);
}

void e_literature ::putdata()
{
    cout << left << setw(20) << doi << endl;
}

class hard_bound : public virtual literature
{
private:
    int num_copy;

public:
    void getdata();
    void putdata();
};

void hard_bound ::getdata()
{
    cout << "number of copy : ";
    cin >> num_copy;
}

void hard_bound ::putdata()
{
    cout << left << setw(20) << num_copy << endl;
}

// here we use extra int variable n to know that the book is in hard copy or in soft copy

class book : public e_literature, public hard_bound
{
private:
    int isbn, n;
    char choice;

public:
    void getdata();
    void putdata();
};

void book ::getdata()
{
    literature::getdata();
    cout << "ISBN : ";
    cin >> isbn;

    cout << "(E) copy or (H)ard bound : ";
    cin >> choice;

    if (choice == 'E' || choice == 'e')
    {
        e_literature ::getdata();
        n = 1;
    }
    else
    {
        hard_bound::getdata();
        n = 2;
    }
}

void book ::putdata()
{
    literature ::putdata();
    cout << left << setw(5) << isbn;
    if (n == 1)
    {
        e_literature ::putdata();
    }
    else
    {
        hard_bound::putdata();
    }
}

class magazine : public e_literature, public hard_bound
{
private:
    int issn, n;
    char choice;

public:
    void getdata();
    void putdata();
};

void magazine ::getdata()
{
    literature::getdata();
    cout << "ISBN : ";
    cin >> issn;

    cout << "(E) copy or (H)ard bound : ";
    cin >> choice;

    if (choice == 'E' || choice == 'e')
    {
        e_literature ::getdata();
        n = 1;
    }
    else
    {
        hard_bound::getdata();
        n = 2;
    }
}

void magazine ::putdata()
{
    literature ::putdata();
    cout << left << setw(5) << issn;
    if (n == 1)
    {
        e_literature ::putdata();
    }
    else
    {
        hard_bound::putdata();
    }
}

int main()
{
    book b[50];
    magazine m[50];

    int choice, b_top = 0, m_top = 0, i;
    char choise;

m:

    cout << endl;
    cout << endl;
    cout << "Enter 1 : add book data " << endl;
    cout << "Enter 2 : add magazine data " << endl;
    cout << "Enter 3 : list all book " << endl;
    cout << "Enter 4 : list all magazine " << endl;
    cout << "Enter your choice : ";
    cin >> choice;

    switch (choice)
    {
    case 1:
        b[b_top].getdata();
        b_top++;
        cout << "Enter M to continue.press any other key to exit : ";
        cin >> choise;
        if (choise == 'm' || choise == 'M')
        {
            goto m;
        }
        else
        {
            break;
        }

    case 2:
        m[m_top].getdata();
        m_top++;
        cout << "Enter M to continue.press any other key to exit : ";
        cin >> choise;
        if (choise == 'm' || choise == 'M')
        {
            goto m;
        }
        else
        {
            break;
        }

    case 3:
        system("cls");
        for (i = 0; i < b_top; i++)
        {
            b[i].putdata();
        }
        if (choise == 'm' || choise == 'M')
        {
            goto m;
        }
        else
        {
            break;
        }

    case 4:
        system("cls");
        for (i = 0; i < b_top; i++)
        {
            m[i].putdata();
        }
        if (choise == 'm' || choise == 'M')
        {
            goto m;
        }
        else
        {
            break;
        }
    }

    return 0;
}