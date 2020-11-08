#ifndef GraphTemps_hpp
#define GraphTemps_hpp
#include <stdio.h>
#endif /* GraphTemps_hpp */
#include "std_lib_facilities.h"
#include "Graph.h"
#include "Simple_window.h"
#include "Temps.hpp"
#pragma once



class Scale {
    int cbase;
    int vbase;
    double scale;
public:
    Scale(int b, int vb, double s) : cbase{b}, vbase{vb}, scale{s} {};
    int operator()(int v) {return cbase + (v-vbase)*scale;}
};

void makeGraphs(vector <Temps>);


