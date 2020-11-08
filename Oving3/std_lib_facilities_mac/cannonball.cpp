#include <stdio.h>
#include "cannonball.h"
#include "std_lib_facilities.h"

constexpr double  pi  = 3.14159265359;

double acclY() {
    return -9.81;
}

double velY(double initVelocityY, double time) {
    return initVelocityY + acclY()*time;
}

double posX(double initPosition, double initVelocity, double time) {
    return initPosition + initVelocity*time;
}

double posY(double initPosition, double initVelocity, double time) {
    return initPosition + initVelocity*time + (acclY()*time*time)/2;
}

void printTime(double time) {
    int hours = time/(60*60);
    time -= hours*60*60;
    
    int minutes = time/60;
    time -= minutes*60;
    
    cout << "Time: " << hours << ":" << minutes << ":" << time << "\n";
}



double flightTime(double initVelocityY) {
    
    return -2.0*initVelocityY/acclY();
}


void getUserInput(double& theta, double& absVelocity) {
    cout << "Oppgi vinkel: ";
    cin >> theta;
    
    cout << "Oppgi fart: ";
    cin >> absVelocity;
}

double degToRad(double deg) {
    return deg*pi/180.0;
}

double getVelocityX(double theta, double absVelocity) {
    return absVelocity*cos(theta);
}



double getVelocityY(double theta, double absVelocity) {
    return absVelocity*sin(theta);
}

void getVelocityVector(double theta, double absVelocity,double& velocityX, double& velocityY) {
    velocityX = getVelocityX(theta, absVelocity);
    velocityY = getVelocityY(theta, absVelocity);
}


double getDistanceTraveled(double velocityX, double velocityY) {
    
    
    double x = 0;
    double  y = 0;
    double time = 0;
    double dt = 0.001;
    
    
    while (y >= 0) {
        
        x = posX(0, velocityX, time);
        y = posY(0, velocityY, time);
        
        time += dt;
        }
    
    return x;
}

double targetPractice(double distanceToTarget, double velocityX, double velocityY) {
    double diff = distanceToTarget - getDistanceTraveled(velocityX, velocityY);
    return diff;
}



