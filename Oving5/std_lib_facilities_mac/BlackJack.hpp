#ifndef BlackJack_hpp
#define BlackJack_hpp
#include <stdio.h>
#endif
#include "std_lib_facilities.h"
#include "Card.h"
#include "CardDeck.hpp"
#pragma once


class BlackJack {
    vector <Card> hand;
    int points;
    int aces;
    bool isDealer;
public:
    BlackJack(bool isDealer);
    void drawCard(CardDeck& deck);
    int getPoints();
    void printHand();
    void printUpcard();
    bool checkBlackJack();
    
    
};

bool checkBust(BlackJack hand);
void printHandandUpCard(BlackJack player, BlackJack dealer);
void compareHands(BlackJack player, BlackJack dealer);
void playBlackJack();

