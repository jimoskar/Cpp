#include "std_lib_facilities.h"
#include "tests.hpp"
#include "utilities.hpp"
#include "mastermind.hpp"





//Oppgave 1 a)
//25 blir skrevet ut.


int main(){
    
    testCallByValue();
    
    testCallByReference();
    
    srand(static_cast<unsigned int>(time(nullptr)));
    testVectorSorting();
    
    testString();
    
    char c = 'C';
    char b = 'c';
    cout << (int) c << " " << (int) b;
    
    
    //string test = readInputToString(4, 'a', 'c');
    
    //cout << test;
    
    cout << endl << "=====================" << endl;
    
    cout << countChar("aaaa", 'c') << endl;
    
    playMastermind();

    

    
    return 0;
}

