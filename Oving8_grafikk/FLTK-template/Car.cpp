#include "Car.hpp"

Car::Car(int freeSeats) : freeSeats{freeSeats} {};

bool Car::hasFreeSeats() const {
    if (freeSeats > 0) {
        return true;
    }
    return false;
}

void Car::reserveFreeSeat() {
    freeSeats -= 1;
}
