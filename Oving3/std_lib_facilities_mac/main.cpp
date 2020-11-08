#include "std_lib_facilities.h"
#include "cannonball.h"
#include "utilities.hpp"



void testDeviation(double compareOperand, double toOperand, double maxError, string name) {
    double diff = abs(compareOperand-toOperand);
    if (diff>maxError) {
        cout << "False\n";
        }
    else {
        cout << "True\n";
    }
}


void playTargetPractice() {
    
    int tries = 0;
    
    for (int i = 0; i <10; i++) {
        int distance =  randomWithLimits(100, 1000);
        cout << "Avstanden er " << distance << endl;
        
        double theta = 0;
        double absVelocity = 0;
        getUserInput(theta,absVelocity);
        theta = degToRad(theta);
        
        double velocityX = 0;
        double velocityY = 0;
        getVelocityVector(theta, absVelocity, velocityX, velocityY);
        
        double difference = targetPractice(distance, velocityX, velocityY);
        
        if (abs(difference) < 5 ) {
            cout << "Du traff!\n" << "Avstand: " << abs(difference) << "\nTid: ";
            printTime(flightTime(absVelocity*sin(theta)));
            break;
        }
        else if (difference < 0) {
            cout << "Du skjøt for langt!\nAvstand: " << abs(difference) << "\nTid: ";
            printTime(flightTime(absVelocity*sin(theta)));
            cout << "==================\n";
        }
        else if (difference > 5) {
            cout << "Du skjøt for kort!\nAvstand: " << abs(difference) << "\nTid: ";
            printTime(flightTime(absVelocity*sin(theta)));
            cout << "==================\n";
            
        }
        
        tries += 1;
    
    }
    
    if (tries==10) {
        cout << "Du tapte :(" << endl;
    }
    
    
    
    
}


int main(){
    
    srand(static_cast<unsigned int>(time(nullptr)));
    /*
    for (double i = 0; i<=5.0; i+=2.5) {
        
        cout << acclY() << "|" << velY(25, i) << "|" << posX(0, 50, i) << "|" << posY(0, 25, i) << "\n";
        
    }
    
    
    testDeviation(posX(0.0,50.0,5.0), 250.0, 0.00001, "posX(0.0,50.0,5.0)"); */
    
    //cout << targetPractice(10, 10, 10);
    
    
    /*
    
    for (int i = 0; i < 10; i++) {
        cout << randomWithLimits(1000,100) << "|";
    }
    
    cout << endl; */
    
    playTargetPractice();
    
    
    return 0;
}
