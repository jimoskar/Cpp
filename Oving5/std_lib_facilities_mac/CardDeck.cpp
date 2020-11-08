#include "CardDeck.hpp"



CardDeck::CardDeck() : currentCardIndex{0} {
    for (int i = 0; i < 4; i++) {
        for ( int j = 2; j < 15; j++) {
            Suit suit = Suit(i);
            Rank rank = Rank(j);
            Card card{suit,rank};
            cards.push_back(card);
        }
    }
}
 


void CardDeck::swap(int i1, int i2) {
    Card tmp = cards[i1];
    cards[i1] = cards[i2];
    cards[i2] = tmp;
}

void CardDeck::print() {
    for( Card card : cards) {
        cout << card.toString() << endl;
    }
}

void CardDeck::printShort() {
    for( Card card : cards) {
        cout << card.toStringShort() << endl;
    }
}

void CardDeck::shuffle() {
    for (int i = 0; i < 52; i++) {
        int randint = rand()%52;
        swap(i, randint);
    }
    
}

const Card& CardDeck::drawCard() {
    const Card& card = cards[currentCardIndex++];
    return card;
}
