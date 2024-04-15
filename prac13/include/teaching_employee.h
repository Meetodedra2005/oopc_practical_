#ifndef TEACHING_EMPLOYEE_H
#define TEACHING_EMPLOYEE_H
#include<string>
#include <employee.h>

using namespace std;

class teaching_employee : public employee
{
    private:
        string designation;
        string specialization;
        string pay_scale;

    public:

        void getdata_t();

        void putdata_t();

        int findid(int, int);
    protected:

};

#endif // TEACHING_EMPLOYEE_H
