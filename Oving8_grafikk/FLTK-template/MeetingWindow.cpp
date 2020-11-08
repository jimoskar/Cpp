#include "MeetingWindow.hpp"

MeetingWindow::MeetingWindow(Point xy, int w, int h, const string& title): Window{w,h,title},
quitBtn{Point{x_max() - pad, pad}, buttonW,buttonH,"Quit",cb_quit},
personNewBtn{Point{x_max()-pad,0}, buttonW,buttonH,"Add", cb_newPerson},
personName{Point{fieldPad, pad}, fieldW,fieldH,"Name"},
personEmail{Point{fieldPad, 2*pad}, fieldW, fieldH, "Email"},
personSeats{Point{fieldPad, 3*pad}, fieldW, fieldH, "Seats"},
data{Point{pad, pad + buttonH * 6 + pad}, x_max() - 2 * pad, y_max() - 3 * pad - buttonH * 6 ,""}
{
    attach(quitBtn);
    attach(personNewBtn);
    attach(personName);
    attach(personEmail);
    attach(personSeats);
    attach(data);
}

void MeetingWindow::cb_quit(Address, Address pw) {
    reference_to<MeetingWindow>(pw).hide();
}

void MeetingWindow::cb_newPerson(Address, Address pw) {
    reference_to<MeetingWindow>(pw).addPerson();
}



void MeetingWindow::addPerson() {
    if (personName.get_string() != "" and personEmail.get_string() != "") {
        if (personSeats.get_int() == 0) {
            people.push_back(new Person{personName.get_string(), personEmail.get_string()});
        }
        else {
            Car* car = new Car{personSeats.get_int()-1};
            cars.push_back(car);
            people.push_back(new Person{personName.get_string(), personEmail.get_string(), car});
            
        }
        displayPeople();
    } else {
        cout << "A field is empty" << endl;
    }
}

void MeetingWindow::printPeople() const {
    for (const auto& p : people) {
        cout << "{" << p->getName() << "," << p->getEmail() << "}" << endl;
    }
}

void MeetingWindow::displayPeople() {
    stringstream ss;
    for (auto p : people) {
        ss << *p << '\n';
    }
    data.put(ss.str());
}
