#include <FL/Fl_Double_Window.H>
#include <FL/Fl_Widget.H>
#include <FL/Fl.h>
#include "Vehicle.hpp"
#include <chrono>
#include <thread>



int main() {
    
    Fl_Double_Window* win = new Fl_Double_Window{1000,1000};
   // win->color(FL_BLACK);
    
    Vehicle* car = new Vehicle{100,100,100,10};
    win->show();
    win->end();

   
    auto next = std::chrono::steady_clock::now();
    while(win->shown()) {
        next += std::chrono::microseconds(1000000 / 60);
        Fl::check();
        Fl::redraw();
        std::this_thread::sleep_until(next);
    }
   
};
