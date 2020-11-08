#include "GraphTemps.hpp"


constexpr int xmax = 600;
constexpr int ymax = 400;

constexpr int xoffset = 100;
constexpr int yoffset = 60;

constexpr int xspace = 40;
constexpr int yspace = 40;

constexpr int xlength = xmax-xoffset-xspace;
constexpr int ylength = ymax-yoffset-yspace;

constexpr int numberdays = 30*12;
constexpr double xscale = double(xlength)/numberdays;
constexpr double yscale = double(ylength)/100;

Scale xs {xoffset,0,xscale};
Scale ys {ymax-yoffset,0,-yscale};

Simple_window win {Point{100,100},xmax,ymax,"Temps"};

Axis x {Axis::x, Point{xoffset,ymax-yoffset}, xlength,numberdays/12, "Feb  Mar  Apr  May  Jun  Jul  Aug  Sep  Nov  Des  Jan"};

//x.label.move(-100,0);

Axis y {Axis::y, Point{xoffset,ymax-yoffset},ylength,7,"Degrees [C]"};



void makeGraphs(vector<Temps> vec) {
    
    Open_polyline maxTemps;
    Open_polyline minTemps;
    int day_counter = 0;
    for (int i = 0; i < vec.size(); i++) {
        const int x = xs(day_counter);
        maxTemps.add(Point{x,ys(vec[i].max)});
        minTemps.add(Point{x,ys(vec[i].min)});
    }
    win.attach(maxTemps);
    win.attach(minTemps);
    
    win.wait_for_button();
}



