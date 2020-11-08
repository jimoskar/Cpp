#include "std_lib_facilities.h"
#include "Card.h"
#include "CardDeck.hpp"
#include "BlackJack.hpp"

int main(){
    
    srand(static_cast<unsigned int>(time(nullptr)));
    
    /*
    CardDeck deck{};
    
    deck.shuffle();
    
    deck.print();
    deck.printShort();
    */
    
    playBlackJack();
    
    
    
   
    

    return 0;
}
