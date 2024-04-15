//Practical 5 : Develop a system to calculate the area of circle. 
/*
    Set circle radius to 1 when the new circle object is created.
    Set circle radius to parameter value if the new circle object is created with parameter.
    Copy the radius of one circle object to another if circle object is created with another object as parameter.
    System calculates and display the area of a circle.
    System should count total number of circle object created and display total number of active circle object
    when any circle object is deleted.
*/

// with static memory allocation 

#include <iostream>
#include<iomanip>

using namespace std;

class circle{

    private :
        int radius;
        double area;
        static int object;

    public: 

    void display();

    circle(){
        radius = 1;
    }

    circle(int a){
        radius = a;
    }

    ~circle(){
        cout << "One object is deleted" << endl;
        object--;
        cout << "Total active object are " << object << endl;
    }
};

int circle :: object = 0;

void circle :: display(){
    area = 3.148 * radius * radius;

    cout << "circle with radius " << radius << " has area " << area << endl;

    object++;
}

int main()
{

    circle a1, a2(20), a3;
    a1.display();
    a2.display();
    a3.display();

    return 0;
}