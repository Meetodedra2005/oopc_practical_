#ifndef NON_TEACH_EMPLOYEE_H
#define NON_TEACH_EMPLOYEE_H

#include <employee.h>

using namespace std;
class non_teach_employee : public employee
{
    private:

        int salary;

    public:
        void getdata();

        void putdata();

        int findid(int, int );
    protected:
};

#endif // NON_TEACH_EMPLOYEE_H
