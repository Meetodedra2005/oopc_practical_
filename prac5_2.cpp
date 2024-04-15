#include <iostream>
#include<iomanip>

using namespace std;

// same as 5_1 but this is done woth new and delete

class circle
{
private:
    int radius;
    float area;
    static int object;
public:
    circle();
    circle(int);
    ~circle();
    void display();
};

circle::circle()
{
    radius = 1;
}

circle :: circle(int a){
    radius = a;
}

circle::~circle()
{
    cout << "One object is deleted" << endl;
        object--;
        cout << "Total active object are " << object << endl; 
}

void circle :: display(){
    area = 3.148 * radius * radius;

    cout << "circle with radius " << radius << " has area " << area << endl;

    object++;
}

int circle :: object = 0;

int main()
{
    circle *a1 = new circle();
    circle *a2 = new circle(20);

    a1->display();

    a2->display();

    delete a2;

    circle *a3 = new circle(*a1);

    delete a1;

    a3 -> display();

    delete a3;

    return 0;
}