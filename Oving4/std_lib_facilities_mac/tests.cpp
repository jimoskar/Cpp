#include "tests.hpp"



void testCallByValue() {
    int v0 = 5;
    int increment = 2;
    int iterations = 10;
    int result = incrementByValueNumTimes(v0, increment, iterations);
    cout << "v0: " << v0
    << " increment: " << increment
    << " iterations: " << iterations
    << " result: " << result << endl;
}

void testCallByReference() {
    int v0 = 5;
    int v01 = v0;
    int increment = 2;
    int iterations = 10;
    incrementByValueNumTimesRef(v0, 2, 10);
    cout << "v0: " << v01
    << " increment: " << increment
    << " iterations: " << iterations
    << " result: " << v0 << endl;
    

}

void testVectorSorting() {
    vector<int> percentages;
    randomizeVector(percentages, 11);
    
    for (auto n:percentages) {
        cout << n << "|";
    }
    cout << "\n";
    
    int& e1 = percentages[0];
    int& e2 = percentages[1];
    swapNumbers(e1, e2);

    for (auto n:percentages) {
        cout << n << "|";
    }
    cout << "\n";
    
    sortVector(percentages);
    for (auto n:percentages) {
        cout << n << "|";
        }
    cout << "\n";
    
    double median = medianOfVector(percentages);
    cout << median << endl;
    
    
    
}

void testString() {
    string grades;
    grades = randomizeString(8, 'A', 'F');
    cout << grades << endl;
    
    
    vector<int> gradeCount;
    int total = 0;
    int totalScore = 0;
    for (int i = (int)'A'; i <= (int) 'F'; i++) {
        int num = countChar(grades, (char)i);
        gradeCount.push_back(num);
        total ++;
        totalScore += (5-(i-(int)'A'))*num;
    }
    double average = (double)totalScore/(double)total;
    
    cout << "Gjennomsnitt: " << average << endl;
    
    
    
}
