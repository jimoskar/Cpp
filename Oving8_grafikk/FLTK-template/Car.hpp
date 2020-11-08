#ifndef Car_hpp
#define Car_hpp
#include <stdio.h>
#endif
#pragma once
#include "std_lib_facilities.h"

class Car {
    int freeSeats;
public:
    Car(int);
    bool hasFreeSeats() const;
    void reserveFreeSeat();
    
};
