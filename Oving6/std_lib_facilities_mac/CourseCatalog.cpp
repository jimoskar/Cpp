#include "CourseCatalog.hpp"


CourseCatalog::CourseCatalog() : subjects{} {
}

ostream& operator<<(ostream& os, const CourseCatalog& cc) {
    for (const auto& p : cc.subjects) {
        os << p.first << ": " << p.second << endl;
        }
    return os;
}

void CourseCatalog::addCourse(string code, string name) {
    subjects[code] = name;
    //subjects.insert(code,name);
}

void CourseCatalog::removeCourse(string code) {
    subjects.erase(code);
}

string CourseCatalog::getCourse(string code) const{
    return subjects.at(code);
}

void testFunction() {
    CourseCatalog cc;
    cc.addCourse("TDT4110", "Informasjonsteknologi grunnkurs");
    cc.addCourse("TDT4102", "Prosedyre- og objektorientert programmering");
    cc.addCourse("TMA4100", "Matematikk 1");
    cc.addCourse("TDT4102", "C++");

    cout << cc;
    cc.writeToFile("subjects.txt");
}

void CourseCatalog::readFromFile(string fileName) {
    
    
}

void CourseCatalog::writeToFile(string fileName) const{
    ofstream writeFile{fileName};
    
    for (const auto& p: subjects) {
        writeFile << p.first << ";" << p.second << endl;
    }
}

