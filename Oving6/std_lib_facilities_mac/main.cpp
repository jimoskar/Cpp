#include "std_lib_facilities.h"
#include "CourseCatalog.hpp"
#include "Temps.hpp"



void writeToFile(string fileName) {
    ofstream myFile{fileName};
    string str;
    do {
        cout << "Skriv til fil: ";
        cin >> str;
        cout << endl;
        myFile << str;
        
    } while (str != "quit");
}

void lineNumber(string readFile, string writeFile) {
    ifstream read{readFile};
    if (!read) {
        error("can't open file, ",readFile);
    }
    ofstream write{writeFile};
    
    string line;
    int rowCounter = 0;
    while (getline(read,line)) {
        write << rowCounter++ << line << endl;
    }
}

void numberOfLetters(string fileName) {
    ifstream readFile{fileName};
    char c;
    vector<int> letterVector(26);
    while (readFile >> c) {
        char letter = tolower(c);
        if (letter >= 'a' and letter <= 'z') {
            letterVector[letter-'a']++;
        }
    }
    for (int i = 0; i < letterVector.size(); i++) {
        char letter  = 'a' + i;
        cout << letter << ": " << letterVector[i] << endl;
    }
}



int main() {

    numberOfLetters("grunnlov.txt");
    
   
    //lineNumber("testFile", "testWrite");
    
    //testFunction();
    
   
    
    return 0;
}
