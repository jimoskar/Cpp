#include <FL/Fl_Widget.H>
#include <FL/fl_draw.H>
#include "utilities.hpp"

class Vehicle : public Fl_Widget {
    double rx;
    double ry;
    int diameter;
    PhysicsState ps;
public:
    Vehicle(double rx, double ry, int diameter, double vel) : Fl_Widget(rx,ry,diameter,diameter), rx{rx}, ry{ry}, diameter{diameter}, ps{rx,ry,vel} {}
    void draw() override {
        fl_color(FL_GREEN);
        fl_circle(rx,ry,diameter);
    }
};


