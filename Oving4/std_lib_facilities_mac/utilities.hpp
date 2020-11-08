#ifndef utilities_hpp
#define utilities_hpp
#include <stdio.h>
#endif
#include "std_lib_facilities.h"
#include <cstdlib>
#include <ctime>


int incrementByValueNumTimes(int startValue, int increment, int numTimes);
void incrementByValueNumTimesRef(int& startValue, int increment, int numTimes);
void swapNumbers(int& num1, int& num2);
void randomizeVector(vector<int>& vec, int n);
void sortVector(vector<int>& vec);
double medianOfVector(vector<int>);
string randomizeString(int length, char lower, char upper);
string readInputToString(int n, char lower, char upper);
int countChar(string str, char c);


