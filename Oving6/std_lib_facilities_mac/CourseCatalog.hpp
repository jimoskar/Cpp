#ifndef CourseCatalog_hpp
#define CourseCatalog_hpp
#include <stdio.h>
#endif
#pragma once
#include "std_lib_facilities.h"


class CourseCatalog {
    map <string,string> subjects;
public:
    CourseCatalog();
    friend ostream& operator<<(ostream&, const CourseCatalog&);
    void addCourse(string,string);
    void removeCourse(string);
    string getCourse(string) const;
    void readFromFile(string);
    void writeToFile(string) const;
    
};

void testFunction();
