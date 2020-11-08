#ifndef CardDeck_hpp
#define CardDeck_hpp
#include <stdio.h>
#endif
#include "std_lib_facilities.h"
#include "Card.h"
#include <cstdlib>
#include <ctime>
#pragma once

class CardDeck {
    vector<Card> cards;
    int currentCardIndex;
public:
    CardDeck();
    void swap(int i1, int i2);
    void print();
    void printShort();
    void shuffle();
    const Card& drawCard();
    
    
    
    
    
};
