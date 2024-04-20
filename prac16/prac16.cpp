#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
using namespace std;

class car_details
{
private:

    int num_cars, seat;
    string airbag,model_name, fuel_type, transmission;
    float price, milage, tank_cap;

public:

    void GetData(string &,char ); // To get the data from user
    void display(); // To diplay the data accoeding to user 
    void PutData_model();    // display all the model name 
    void PutData_fuel(int);     // display the car according to user's choice for fuel type
    void PutData_price(float,int);  // display the car according to user's budget
};

void car_details ::GetData(string &str,char dm)
{
    int p[7],n=0;

    // finding the index number of ',' 

    for (int i = 0; i < 7; i++)
    {
        p[i] = str.find(dm,n);
        n = p[i]+1;
    }

    // adding the data to the various variable using substring function

    model_name = str.substr(0,p[0]);
    fuel_type = str.substr(p[0]+1,p[1]-p[0]-1);
    price = stof(str.substr(p[1]+1,p[2]-p[1]-1));
    milage = stof(str.substr(p[2]+1,p[3]-p[2]-1));
    transmission = str.substr(p[3]+1,p[4]-p[3]-1);
    tank_cap = stof(str.substr(p[4]+1,p[5]-p[4]-1));
    seat = stoi(str.substr(p[5]+1,p[6]-p[5]-1));
    airbag = str.substr(p[6]+1,str.length()-p[6]);
}

void car_details :: PutData_model() {
    cout << model_name << "   ";    // display all the model name
}

void car_details :: PutData_fuel(int num){

    switch (num)    // switch the case according to user's choice
    {
    case 1:
        if (fuel_type == "petrol" || fuel_type == "Petrol")
        {
            display();
        }
        
        break;
    case 2:
        if (fuel_type == "diesel" || fuel_type == "Diesel")
        {
            display();
        }
        
        break;
    case 3:
        if (fuel_type == "cng" || fuel_type == "CNG")
        {
            display();
        }
        break;
    
    default:
            cout << "please select give option";
        break;
    }

}

void car_details :: PutData_price(float pr,int i)
{
    if (price < pr)     // check the condition if model is in budeget of user than display
    {
        if (i == 0)
        {
                cout << left << setw(8) << "model" << left << setw(8) << "fuel" << left << setw(8) << "price" << left << setw(9) << "milage" << left << setw(13) << "transmission" << left << setw(15) << "tank capacity" << left << setw(8) << "seat" << left << setw(7) << "airbag" << endl;
                cout << endl;
        }
        display();
    }
}

void car_details :: display(){

    cout << left << setw(8) << model_name << left << setw(8) << fuel_type << left << setw(8) << price << left << setw(9) << milage << left << setw(13) << transmission << left << setw(15) << tank_cap << left << setw(8) << seat << left << setw(7) << airbag << endl;

}

int main()
{
    car_details car[50];
    ifstream input;
    string full;

    int i = 0,total_car,option,model_num,fuel_num,price;

    // opening the file

    input.open("cardata.txt");

    while (getline(input,full,';'))// reading the data to the delimiter ";" from file and itrating till the end of file
    {
        car[i].GetData(full,','); // passing the string of 1 type of car to get data to store the data of various components
        i++;
    }

    total_car = i - 1;

    // closing the file

    input.close();

    cout << "\nWELCOME TO TATA MOTORS "<<endl;
    cout << "\nGET THE CAR DETAILS AS PER YOUR PREFRENCE " << endl;

    cout << "\n(1) Model name (2) Fuel type (3) price " << endl;
    cout << endl << "\nENTER YOUR OPTION : ";
    cin >> option;
    cout << endl;

    cout << "\n--------------------------------" << endl;

    switch (option)
    {
    case 1:
        cout << "\nLIST OF TATA CARS" << endl;
        cout << endl;
        for (i = 0; i < total_car; i++)
        {
            cout << i+1 << ")";
            car[i].PutData_model();    //display all the model name available
        }

        cout << endl << endl << "Enter your choise : ";
        cin >> model_num;

        cout << endl;

            cout << left << setw(8) << "model" << left << setw(8) << "fuel" << left << setw(8) << "price" << left << setw(9) << "milage" << left << setw(13) << "transmission" << left << setw(15) << "tank capacity" << left << setw(8) << "seat" << left << setw(7) << "airbag" << endl;
            cout << endl;

        car[model_num - 1].display();   // call the funtion to display the data according to user's choice
        break;

    case 2:

        menu:
        cout << endl << "TATA MOTORS ARE AVAILABLE WITH FUEL OPTION" << endl;
        cout << endl << "(1) Petrol (2) Diesel (3) CNG" << endl << endl;
        cout << "ENTER YOUR FUEL PREFRENCE : ";
        cin >> fuel_num;
        if (fuel_num > 3 || fuel_num < 0)
        {
            cout << "please enter valid choise "<< endl << endl;
            goto menu;
        }
        

            cout << left << setw(8) << "model" << left << setw(8) << "fuel" << left << setw(8) << "price" << left << setw(9) << "milage" << left << setw(13) << "transmission" << left << setw(15) << "tank capacity" << left << setw(8) << "seat" << left << setw(7) << "airbag" << endl;
            cout << endl;

        for ( i = 0; i < total_car; i++)
        {
            car[i].PutData_fuel(fuel_num);      // call the function to check the fuel type of car
        }
        
        break;

    case 3:
        cout << "ENTER YOUR MAXIMUM AFFORDABLE RANGE IN LAKHS : ";
        cin >> price;

        for ( i = 0; i < total_car; i++)
        {
            car[i].PutData_price(price,i);     // call the function to check the price
        }

    }

    return 0;
}