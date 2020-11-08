#ifndef Temps_hpp
#define Temps_hpp
#include <stdio.h>
#endif
#pragma once
#include "std_lib_facilities.h"


struct Temps {
    double max, min;

    Temps();
    Temps(double max, double min);
    friend istream& operator>>(istream& is, Temps& t);
};

vector <Temps> makeTempVec(string fileName);

