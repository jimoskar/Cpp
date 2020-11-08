#include "std_lib_facilities.h"

#include "Car.hpp"
#include "Person.hpp"
#pragma once


enum class Campus {
    Trondheim
};

class Meeting {
    int day;
    int startTime;
    int endTime;
    Campus location;
    string subject;
    const Person* leader;
    set<const Person*> participants;
    static set<const Meeting*> meetings;
public:
    Meeting(int day, int startTime, int endTime, Campus location, string subject, Person* leader);
    int getDay() const {return day;}
    int getStartTime() const { return startTime;}
    int getEndTime() const { return endTime;}
    Campus getLocation() const { return location;}
    string getSubject() const { return subject;}
    Person getLeader() const {return *leader;}
    void addParticipants(Person &p);
    vector<string> getParticipantList();
    vector <const Person*> findPotentialCoDriving();
    
    ~Meeting() {meetings.erase(this);}
};
