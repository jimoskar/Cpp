#include "Meeting.hpp"




ostream& operator<<(ostream& os, const Campus& c) {
    
    return os;
}

void Meeting::addParticipants(Person &p) {
    Person* pp = &p;
    participants.insert(pp);
}

set<const Meeting*> Meeting::meetings;

Meeting::Meeting(int day, int startTime, int endTime, Campus location, string subject, Person* leader) :
day{day}, startTime{startTime}, endTime(endTime), location(location), subject(subject), leader(leader) {
    set<const Person*> participants;
    this->participants.insert(leader);
    meetings.insert(this);
}


vector <string> Meeting::getParticipantList() {
    vector <string> vec;
    for (const auto& e : participants) {
        vec.push_back(e->getName());
    }
    return vec;

}

ostream& operator<<(ostream& os, const Meeting& m) {
    os << "Subject: " << m.getSubject() << endl;
    os << "Location: " << m.getLocation() << endl;
    os << "Start time: " << m.getStartTime() << endl;
    os << "End time: " << m.getEndTime() << endl;
    return os;
}

vector <const Person*> Meeting::findPotentialCoDriving() {
    vector <const Person*> vec;
    for (const auto& m : meetings) {
        if(m->getLocation() == location and (abs(startTime-m->getStartTime()) < 100) and (abs(endTime-m->getEndTime()) < 100) and (m != this)) {
            for (const auto& p : m->participants) {
                if (p->hasAvailableSeats()) {
                    vec.push_back(p);
                }
            }
        }
    }
    return vec;
}
