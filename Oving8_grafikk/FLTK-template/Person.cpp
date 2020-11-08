#include "Person.hpp"


Person::Person(string name, string email, Car* car) : name{name}, email{email}, car{car} {}

bool Person::hasAvailableSeats() const {
    if (car==nullptr) {
        return false;
    }
    return true;
}

ostream &operator<<(ostream& os, const Person& p) {
    os << "Name: " << p.name << endl;
    os << "Email: " << p.email << endl;
    
    return os;
}
