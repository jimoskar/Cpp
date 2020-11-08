#include "BlackJack.hpp"



BlackJack::BlackJack(bool isDealer) : hand{}, points{}, isDealer{isDealer}, aces{} {
    
}

void BlackJack::drawCard(CardDeck& deck) {
    
    if (!isDealer or points < 17) {
        Card card = deck.drawCard();
        hand.push_back(card);
        
        int value = static_cast<int>(card.rank());
        if (value < 10) {
            points += value;
        }
        else if (value == 14) {
            aces += 1;
        }
        else {
            points += 10;
        }
    }
}

void BlackJack::printHand() {
    for (Card c: hand) {
        cout << "|" << c.toStringShort() << "|";
    }
    cout << endl;
}

void BlackJack::printUpcard() {
    cout << "|" << hand[0].toStringShort() << "|" << endl;
}

bool BlackJack::checkBlackJack() {
    int card1 = static_cast<int>(hand[0].rank());
    int card2 = static_cast<int>(hand[1].rank());
    if (((card1 > 9 and card1 < 14 ) and card2 == 14) or ((card2 > 9 and card2 < 14) and card1 == 14)) {
        return true;
    }
    else {
        return false;
    }
}

bool checkBust(BlackJack hand) {
    if (hand.getPoints() > 21) {
        return true;
    }
    return false;
    
}


void compareHands(BlackJack player, BlackJack dealer) {
    cout << "Dealers hand: ";
    dealer.printHand();
    if (player.checkBlackJack() and !dealer.checkBlackJack()) {
        cout << "Congratulations, you won!" << endl;
        }
    else if (!player.checkBlackJack() and dealer.checkBlackJack()) {
        cout << "You lose." << endl;
        }
    else if (player.checkBlackJack() and dealer.checkBlackJack()) {
        cout << "You lose." << endl;
    }
    else if (checkBust(dealer)) {
        cout << "Congratulations, you won!"<< endl;
    }
    else {
        if (player.getPoints() > dealer.getPoints()) {
            cout << "Congratulations, you won!" << endl;
        }
        else {
            cout << "You lose." << endl;
        }
    }
}


void printHandandUpCard(BlackJack player, BlackJack dealer) {
    cout << "Your hand: " << endl;
    player.printHand();
    cout << "Upcard: ";
    dealer.printUpcard();
    
}




int BlackJack::getPoints() {
    if (aces == 1) {
        if (points + 14 < 21) {
            return points + 14;
        } else {
            return points +1;
            }
        }
    else if (aces == 2) {
            if (points + 14 +1 < 21) {
                return points + 14 +1;
            } else {
                return points +1 +1;
            }
        }
    else if (aces == 3) {
            if(points + 14 + 1 + 1 > 21) {
                return points + 1 + 1 + 1;
            } else {
                return points + 14 + 1 + 1;
            }
        }
    else if (aces == 4) {
                if(points + 14 + 1 + 1 + 1 > 21) {
                    return points + 1 + 1 + 1  + 1;
                } else {
                    return points + 14 + 1 + 1 + 1;
                }
        }
    else {
        return points;
    }
}


void playBlackJack() {
    
    cout << "Get ready to play BlackJack!" << endl;
    cout << "=====================================" << endl;
    
    BlackJack player{false};
    BlackJack dealer{true};
    CardDeck deck;
    deck.shuffle();
    
    player.drawCard(deck);
    dealer.drawCard(deck);
    player.drawCard(deck);
    dealer.drawCard(deck);
    
    bool loopCondition = true;
    
    while (loopCondition) {
        printHandandUpCard(player, dealer);
        char choice;
        cout << "Do you want to hit or stand? (h/s): ";
        bool badInput = true;
        do {
            cin >> choice;
            if (choice == 'h') {
                player.drawCard(deck);
                dealer.drawCard(deck);
                if (checkBust(player)) {
                    cout << "Busted." << endl;
                    loopCondition = false;
                    badInput = false;
                }
                badInput = false;
            }
            else if (choice == 's' ) {
                compareHands(player, dealer);
                loopCondition = false;
                badInput = false;
            }
            else {
                cout << "Incorrect input, please write again ";
            }
            
        } while (badInput);
        
        
    }
}
