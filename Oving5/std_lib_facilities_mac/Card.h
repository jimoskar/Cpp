#ifndef Card_h
#define Card_h
#endif
#include "std_lib_facilities.h"
#pragma once

enum class Suit {
    clubs=0, diamonds, hearts, spades
};

enum class Rank {
    two = 2, three, four, five, six, seven, eight, nine, ten, jack, queen, king, ace
};

struct CardStruct {
    Suit s;
    Rank r;
};

class Card {
    Suit s;
    Rank r;
    bool valid;
public:
    Card();
    Card(Suit suit, Rank rank);
    Suit suit() {return s;}
    Rank rank() {return r;}
    bool isValid() {
        return valid;
    }
    string toString();
    string toStringShort();
    
};


//string toString(CardStruct card);
//string toStringShort(CardStruct card);
string suitToString(Suit s);
string rankToString(Rank r) ;

