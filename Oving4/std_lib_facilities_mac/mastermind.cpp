#include "mastermind.hpp"

int checkCharacterAndPosition(string code, string guess) {
    int result = 0;
    for (int i = 0; i < code.length(); i++) {
        if (code[i] == guess[i]) {
            result++;
        }
    }
    return result;
}



int checkCharacters(string code, string guess) {
    int count = 0;
    for (int i = 0; i < guess.size(); i++) {
        for ( int j = 0; j < code.size(); j++) {
            if (guess[i] == code[j]) {
                count++;
                code.erase(code.begin()+j);
                break;
            }
        }
    }
    return count;
}


void playMastermind() {
    constexpr int size = 4;
    constexpr int letters = 6;
    //Oppgave 5 a)
    //Vi benytter constexpr fordi vi vil ha tilgang til deisse verdiene før programmet kompilerer.
    //Dersom vi ikke visste verdien av size og letters på forhånd, vill vi brukt const.
    
    MastermindWindow mwin{Point{900, 20}, 400, 600, "Mastermind"};
    
    string code;
    string guess;
    code = randomizeString(size, 'A', 'A'+letters-1);
    cout << code << endl;
    addGuess(mwin, code, size, 'A', 0);
    hideCode(mwin, size);
    int tries = 1;
    do{
        
        if (tries > 10) {
            cout << "Du tapte :(" << endl;
            break;
        }
        cout << "**Skriv inn en kombinasjon**" << endl;
        guess = readInputToString(size, 'A', 'A'+letters-1);
        int corrChar = checkCharacters(code, guess);
        int corrCharPos = checkCharacterAndPosition(code, guess);
        cout << "Antall riktige tegn: " << corrChar << endl;
        cout << "Antall riktige på riktig plass: " << corrCharPos << endl;
        cout << "==============================" << endl;
        
        addGuess(mwin, guess, size, 'A', tries);
        addFeedback(mwin, corrCharPos, corrChar, size, tries);
        mwin.wait_for_button();
        tries += 1;
    } while(checkCharacterAndPosition(code, guess)<size);
    
    if (tries <  11) {
        cout << "Gratulerer! Du klarte det :)" << endl;
    }
    

    
}


