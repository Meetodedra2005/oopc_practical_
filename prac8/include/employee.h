#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include<string>

using namespace std;

class employee
{
private:
    int id;
    string name,qualification;
    float experiance;
    string number;
    static float ava_exp;

protected:

    int id_temp;

    void getdata();

    void putdata();

    int findid(int , int );

public:

    static void ava_exp_empl(int );

};

#endif // EMPLOYEE_H

