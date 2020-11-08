#include "Temps.hpp"

Temps::Temps() : max{}, min{} {}
Temps::Temps(double max, double min) : max{max}, min{min} {}

istream& operator>>(istream& is, Temps& t) {
    is >> t.max >> t.min;
    return is;
}

vector <Temps>  makeTempVec(string fileName) {
    ifstream is{fileName};
    double max;
    double min;
    vector <Temps> vec;
    while (is >> max >> min) {
        Temps temp{max,min};
        vec.push_back(temp);
    }
    return vec;
}

