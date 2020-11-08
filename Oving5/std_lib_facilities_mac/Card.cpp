#include <stdio.h>
#include "Card.h"

string suitToString(Suit s){
    string str;
    
    switch (s) {
        case Suit::clubs:
            str = "clubs";
            break;
        case Suit::diamonds:
            str = "diamonds";
            break;
        case Suit::hearts:
            str = "hearts";
            break;
        case Suit::spades:
            str = "spades";
            break;
    }
    return str;
    
}

string rankToString(Rank r) {
    
    switch(r) {
        case Rank::two:
            return "two";
        case Rank::three:
            return "three";
        case Rank::four:
            return "four";
        case Rank::five:
            return "five";
        case Rank::six:
            return "six";
        case Rank::seven:
            return "seven";
        case Rank::eight:
            return "eight";
        case Rank::nine:
            return "nine";
        case Rank::ten:
            return "ten";
        case Rank::jack:
            return "jack";
        case Rank::queen:
            return "queen";
        case Rank::king:
            return "king";
        case Rank::ace:
            return "ace";
            
    }
}
 


//Oppgave 1 e)
//Dette gjør koden mer ryddig og hindrer faren for å bruke samme verdi for ulike variabler.

string toString(CardStruct card) {
    string suit = suitToString(card.s);
    string rank = rankToString(card.r);
    return rank + " of " + suit;
}

string toStringShort(CardStruct card) {
    string suit = suitToString(card.s);
    suit = toupper(suit[0]);
    int rank = static_cast<int>(card.r);
    return suit+ to_string(rank);
}

string Card::toString() {
    if (valid) {
        string suit = suitToString(Card::suit());
        string rank = rankToString(Card::rank());
        return rank + " of " + suit;
        }
    return "Ugyldig kort";
}

string Card::toStringShort() {
    if (valid) {
        string suit = suitToString(Card::suit());
        suit = toupper(suit[0]);
        int rank = static_cast<int>(Card::rank());
        return suit + to_string(rank);
    }
    return "Ugyldig kort";
}

Card::Card() : valid{false} {};
Card::Card(Suit suit, Rank rank) : s {suit}, r {rank}, valid {true} {};

//Oppgave 3 i)
//invariant: Et kort som har en av fire farger og en verdi fra 2-14.
//Usikker på hva som er fordel med struct.




