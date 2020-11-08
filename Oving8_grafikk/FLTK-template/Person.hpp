#include "std_lib_facilities.h"
#include "Car.hpp"
#pragma once


class Person {
    string name, email;
    Car* car;
public:
    Person(string,string, Car* car = nullptr);
    string getName() const {return name;}
    string getEmail() const {return email;}
    void setEmail(string newMail) {email = newMail;}
    bool hasAvailableSeats() const;
    friend ostream& operator<<(ostream& os, const Person& p);
    
};


