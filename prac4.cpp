// Practical 4 : Develop a system to calculate the area of a shape.
/*
A system calculates the area of circle, rectangle and cuboid. Every time it called the same function for
calculating the area. Depending on the number of parameters passed, it chooses where to find area or
circle / rectangle / cuboid.
*/

#include <iostream>
#include<iomanip>
#include<stdlib.h>
#include <string>

using namespace std;

class area{

    private:

        int area_rect,area_cuboid;
        float area_circle;

    public:

        void calculatearea(int);            // funtion who only have one parameter (calculate area of circle)
        void calculatearea(int,int);        // function who have two parameter     (calculate area of rectangle)
        void calculatearea(int,int,int);    // function who have three parameter   (calculate area of cuboid)
};

void area :: calculatearea(int r){
    
    area_circle = 3.14 *r *r;

    cout << endl  << "The area of circle is " << area_circle << endl;
}

void area :: calculatearea(int h,int w){
    area_rect = (h * w);

    cout<< endl << "The area of rectangle is " << area_rect << endl;
}

void area :: calculatearea(int h,int w,int d){
    fflush(stdin);

    area_cuboid = (h * w * d);

    cout << endl << "The area of cuboid is " << area_cuboid << endl;
}

int main()
{
    area obj;

    int radius, height_r, width_r, height_c, width_c, depth_c;
    int choice;

    cout << endl << "Enter the radius of circle : ";
    cin >> radius;

    obj.calculatearea(radius); // call the function having one parameter

    cout << endl << "Enter the height of rectangle : ";
    cin >> height_r;

    cout << endl << "Enter the width of rectangle : ";
    cin >> width_r;

    obj.calculatearea(height_r,width_r); // call the function having two parameter

    fflush(stdin);

    cout << endl << "Enter the height of cuboid : ";
    cin >> height_c;

    cout << endl << "Enter the width of cuboid : ";
    cin >> width_c;

    cout << endl << "Enter the depth of cuboid : ";
    cin >> depth_c;

    obj.calculatearea(height_c,width_c,depth_c); // call the function having three parameter
    return 0;
}