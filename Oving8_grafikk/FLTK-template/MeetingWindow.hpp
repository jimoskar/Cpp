#include "std_lib_facilities.h"
#include "Meeting.hpp"
#include "Person.hpp"
#include "Car.hpp"
#include "Graph.h"
#include "GUI.h"
#include "Graph_lib.h"
#pragma once

using namespace Graph_lib;

class MeetingWindow : public Graph_lib::Window {
    static constexpr int fieldH = 30;
    static constexpr int fieldW = 100;
    static constexpr int fieldPad = 100;
    static constexpr int buttonW = 40;
    static constexpr int buttonH = 30;
    static constexpr int buttonPad = 50;
    static constexpr int pad = 50;
    
    Vector_ref<Person> people;
    void addPerson();
    
    Button quitBtn;
    Button personNewBtn;
    In_box personName;
    In_box personEmail;
    
    In_box personSeats;
    Vector_ref<Car> cars;
    Multiline_out_box data;
    void displayPeople();
    
    static void cb_newPerson(Address, Address pw);
    static void cb_quit(Address,Address pw);
   
    
    
public:
    MeetingWindow(Point xy, int w, int h, const string& title);
    void printPeople() const;
};
