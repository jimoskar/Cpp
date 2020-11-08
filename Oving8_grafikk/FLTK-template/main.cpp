// Lec2Ex1c.cpp, an improvement of Lec2Ex1c.cpp
#include "Graph.h"
#include "Simple_window.h"
#include "Person.hpp"
#include "Car.hpp"
#include "MeetingWindow.hpp"

using namespace Graph_lib;


int main() {
    
    MeetingWindow win{{100,100},400,500,"Canvas"};
    
  gui_main();
    
    win.printPeople();
    
    return 0;
    
    
};

//spørsmål: hvorfor new?, lagrer vector_ref alltid pointers? 
