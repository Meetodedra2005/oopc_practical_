// here we use the concept of operator overloading

// here we do the operation of the complex number

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class operation
{
private:
    int real, img;
public:
    void getdata();
    void display();
    operation operator+(operation);
    operation operator-(operation);
    operation operator*(operation);
    operation operator/(operation);
    void operator!();
};

void operation::getdata(){
    cout << "Enter real number : ";
    cin >> real;
    cout << "Enter imaginary number : ";
    cin >> img;
}

void operation :: display(){
    cout << real << " + " << img << "i";
}

operation operation::operator+(operation sec){
    operation temp;
    temp.real = real + sec.real;
    temp.img = img + sec.img;
    return temp;
}
operation operation::operator-(operation sec){
    operation temp;
    temp.real = real - sec.real;
    temp.img = img - sec.img;
    return temp;
}
operation operation::operator*(operation sec){
    operation temp;
    temp.real = (real * sec.real) - (img * sec.img); 
    temp.img = (real * sec.img) + (img * sec.real); 
    return temp;
}
operation operation::operator/(operation sec){
    operation temp;
    temp.real = ((real * sec.real) + (img * sec.img))/((sec.real * sec.real)  + (sec.img * sec.img));
    temp.img = ((img * sec.real) - (real * sec.img))/((sec.real * sec.real)  + (sec.img * sec.img));
    return temp;
}

void operation :: operator!()
{
    real = -real;
    img = -img;
}

int main()
{
    operation o1,o2,o3;
    char choise;

    o1.getdata();
    o2.getdata();

    cout << "Choose operation " << endl;
    cout << "(+) addition \n(-) subtraction \n(*) multiplication \n(/) division \n(!) negation " << endl;

    cout << "Enter your choice : ";
    cin >> choise;

    switch (choise)
    {
    case '+':
        o3 = o1 + o2;
        o3.display();
        break;

    case '-':
        o3 = o1 - o2;
        o3.display();
        break;

    case '*':
        o3 = o1 * o2;
        o3.display();
        break;

    case '/':
        o3 = o1 / o2;
        o3.display();
        break;

    case '!':
        !o1;
        !o2;
        o1.display();
        cout << endl;
        o2.display();

    default:
        break;
    }
    return 0;
}