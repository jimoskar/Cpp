#include "utilities.hpp"



int randomWithLimits(int lower, int upper) {
    
    return lower + (rand()%(upper-lower+1));
}
