#include "utilities.hpp"


int incrementByValueNumTimes(int startValue, int increment, int numTimes) {
    for (int i = 0; i < numTimes; i++) {
        startValue += increment;
    }
    return startValue;
}

void incrementByValueNumTimesRef(int& startValue, int increment, int numTimes) {
    for (int i = 0; i<numTimes; i++) {
        startValue += increment;
    }
}

//Oppgave 1 e)
//Siden funksjonen skal endre to verdier, børe den bruke referanser.

void swapNumbers(int& num1, int& num2) {
    int a = num1;
    int b = num2;
    num1 = b;
    num2 = a;
}

void randomizeVector(vector<int>& vec, int n) {
    
    for ( int i = 0; i < n; i++) {
        int random = 0 + (rand()%(100-0+1));
        vec.push_back(random);
    }
}

void sortVector(vector<int>& vec) {
    for (int i = 1; i < vec.size(); ++i) {
        for (int j = i; j > 0 and vec[j-1] > vec[j]; j--) {
            int tmp = vec[j];
            vec[j] = vec[j-1];
            vec[j-1] = tmp;
        }
    }
}

double medianOfVector(vector<int> vec) {
    if (vec.size()%2 == 0) {
        return vec[(double)vec.size()/2];
    }
    
    return static_cast<double>(vec[(vec.size()-1)/2]+vec[(vec.size()+1)/2])/2;
    
}

string randomizeString(int length, char lower, char upper) {
    lower = (int) lower;
    upper = (int) upper;
    
    string str;
    for(int i = 0; i<length; i++) {
        int random = lower + rand()%(upper-lower+1);
        char c = random;
        str += c;
        }
    return str;
}

string readInputToString(int n, char lower, char upper) {
    string str;
    for (int i = 0; i < n; i++) {
        char input;
        cout << "Skriv inn bokstav: ";
        cin >> input;
        if (isalpha(input)) {
            input = toupper(input);
            lower = toupper(lower);
            upper = toupper(upper);
            if ((int)input >= (int)lower and (int)input <= (int)upper){
                str += input;
            }
            else {
                cout << "Bokstaven er utenfor grensene, vennligst skriv inn en ny. ";
                i--;
                continue;
            }
            }
        else {
            cout << "Du skrev ikke inn en bokstav, vennnligst skriv på nytt. ";
            i--;
            continue;
            }
        }
    return str;
}

int countChar(string str, char c) {
    int frq = 0;
    for (char n:str) {
        if (n == c) {
            frq++;
        }
    }
    return frq;
}
    

