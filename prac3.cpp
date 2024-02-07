//Practical 3 : Create a car data management system for TATA motors using C++
// Which contain this two task
/*
Task – 1 : Feed car details in the system
Number of cars (3 digit number), Model name (string with space), Fuel type (values can be petrol, diesel,
cng, electric), Showroom price (floating point number), Mileage (floating point number), Transmission
(values can be Manual or AMT), Tank capacity (floating point number), seating (1 digit number),
Airbags (values can be Yes or No)


Task – 2: Retrieve car data based on different options
Option 1 : Model name 
Option 2 : Fuel type 
Option 3 : Price range
*/

#include <iostream>
#include<iomanip>
#include<stdlib.h>
#include <string>

using namespace std;

class car_details
{
private:

    int num_cars, seat;
    string model_name, fuel_type, transmission;
    float price, milage, tank_cap;
    char airbag;

public:

    void GetData(); // To get the data from user
    void display(); // To diplay the data accoeding to user 
    void PutData_model(int);    // display all the model name 
    void PutData_fuel(int);     // display the car according to user's choice for fuel type
    void PutData_price(float);  // display the car according to user's budget
};

void car_details :: GetData(){
    cin.ignore();

    cout << "Enter the model name : ";
    getline(cin, model_name);
    cout << endl;

    cout << "Enter the fuel type : ";
    getline(cin, fuel_type);
    cout << endl;

    cout << "Enter the showroom price : ";
    cin >> price;
    cout << endl;

    cout << "Enter the mileage of car : ";
    cin >> milage;
    cout << endl;

    cin.ignore();

    cout << "Enter the transmission the car is manual or amt : ";
    getline(cin, transmission);
    cout << endl;

    cout << "Enter the tank capacity : ";
    cin >> tank_cap;
    cout << endl;

    cout << "Enter the seating capacity : ";
    cin >> seat;
    cout << endl;

    cout << "Enter 'y' if airbag is available else 'n' : ";
    cin >> airbag;
    cout << endl;
}

void car_details :: PutData_model(int i) {
    cout << i + 1 << ") " << model_name;    // display all the model name
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
    case 4:
        if (fuel_type == "electrical" || fuel_type == "Electrical")
        {
            display();
        }
        
        break;
    
    default:
            cout << "please select give option";
        break;
    }

}

void car_details :: PutData_price(float pr){

    if (price < pr)     // check the condition if model is in budeget of user than display
    {
        display();
    }
    

}

void car_details :: display(){

    cout << left << setw(8) << "model" << left << setw(7) << "fuel" << left << setw(6) << "price" << left << setw(7) << "milage" << left << setw(13) << "transmission" << left << setw(15) << "tank capacity" << left << setw(8) << "seat" << left << setw(7) << "airbag" << endl;
    cout << endl;
    cout << left << setw(8) << model_name << left << setw(7) << fuel_type << left << setw(6) << price << left << setw(7) << milage << left << setw(13) << transmission << left << setw(15) << tank_cap << left << setw(8) << seat << left << setw(7) << airbag << endl;

}

int main(){

    int number, option, i,model_num,fuel_num;
    float price;

    cout << "Enter the number of cars (max 999) : ";    // get the total number of car's available
    cin >> number;
    cout << endl;

    car_details car[number];       // create object of class car_details

    for (i = 0; i < number; i++)
    {
        cout << i + 1 << ") car details : " << endl;
        car[i].GetData();       // call the function to put all data
    } 

    cout << "\nWELCOME TO TATA MOTORS "<<endl;
    cout << "\nGET THE CAR DETAILS AS PER YOUR PREFRENCE " << endl;

    cout << "\n(1) Model name (2) Fuel type (3) price " << endl;
    cout << "\nENTER YOUR OPTION : ";
    cin >> option;
    cout << endl;

    cout << "\n--------------------------------" << endl;

    switch (option)
    {
    case 1:
        cout << "\nLIST OF TATA CARS" << endl;
        for (i = 0; i < number; i++)
            car[i].PutData_model(i);    //display all the model name available

        cout << endl << "Enter your choise : ";
        cin >> model_num;

        car[model_num - 1].display();   // call the funtion to display the data according to user's choice
        break;

    case 2:
        cout << "TATA MOTORS ARE AVAILABLE WITH FUEL OPTION" << endl;
        cout << endl << "(1) Petrol (2) Diesel (3) CNG (4) Electric " << endl << endl;
        cout << "ENTER YOUR FUEL PREFRENCE : ";
        cin >> fuel_num;

        for ( i = 0; i < number; i++)
        {
            car[i].PutData_fuel(fuel_num);      // call the function to check the fuel type of car
        }
        
        break;

    case 3:
        cout << "ENTER YOUR MAXIMUM AFFORDABLE RANGE IN LAKHS : ";
        cin >> price;

        for ( i = 0; i < number; i++)
        {
            car[i].PutData_price(price);     // call the function to check the price
        }

    }

    return 0;
}