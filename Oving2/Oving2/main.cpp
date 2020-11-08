#include "std_lib_facilities.h"
#include <cmath>

//Oppgave 1 a)

void inputAndPrintInteger () {
    int n;
    cout << "Write integer: ";
    cin >> n;
    cout << "Your integer is " << n << "!\n";
    
    
    
}

//Oppgave 1 b)

int inputInteger() {
    int n;
    cout << "Write integer: ";
    cin >> n;
    return n;
    
}

//Oppgave 1 c)

void inputIntegersAndPrintSum() {
    
    int i1;
    int i2;
    
    i1 = inputInteger();
    i2 = inputInteger();
    
    cout << "The sum is " << i1 +i2 << ".\n";
}

//Oppgave 1 d)
//Jeg valgte å bruke inputInteger fordi den returnerer heltallet og kan derfor tillegges en variabel direkte.

//Oppgave 1 e)

bool isOdd (int n) {
    if (n%2 == 0) { // if (n % 2)
        return true;
    }
    else {
        return false;
    }
}

//Oppgave 1 f)

void printHumanReadableTime (int n) {
    
    int hours = n/(60*60);
    n -= hours*(60*60);
    
    int minutes = n/60;
    n -= minutes*60;
    
    cout << hours << " hours, " << minutes << " minutes, " << n << " seconds.\n";
}

//Oppgave 2 a)

void inputIntegersUsingLoopAndPrintSum () {
    cout << "How many numbers?\n";
    int n;
    cin >> n;
    
    int sum = 0;
    
    for (int i = 0; i <n; ++i) {
        
        int m;
        cout << "Write integer: ";
        cin >> m;
        if (m==0) {
            break;
        }
        sum += m;
    }
    
    cout << "The sum is " << sum <<".\n";
    
}

//Oppgave 2 b)
//Dersom brukeren angir antall tall på forhånd, vil en for-løkke være gunstig. Dersom antallet er ukjent, vil en while løkke være gunstig.

//Oppgave 2 c)

double inputDouble() {
    double n;
    cout << "Write double: ";
    cin >> n;
    return n;
    
}

//Oppgave 2 d)

void convertEUtoNOK() {
    double eu = -1;
    while (eu<0) {
        eu = inputDouble();
        
    }
    cout << "NOK: " << setprecision(4) << eu*9.75 << "\n"; //Usikker her
    
}

//Oppgave 2 e)
//Jeg bruker ipnutDoudble siden et desimaltall skal konverteres.

//Oppgave 3 b)

void gangeTabell() {
    int b;
    cout << "Bredde: ";
    cin >> b;
    int h;
    cout << "Høyde: ";
    cin >> h;
    
    for (int i = 1; i <b+1;++i) {
        
        for( int j = 1; j<h+1; ++j) {
            cout << i*j << setw(2);
        }
        cout << "\n";
    }
    
    

}

//Oppgave 4 a)

double discriminant( double a, double b, double c) {
    
    return b*b - 4*a*c;
}

//Oppgave 4 b)

void printRealRoots(double a, double b, double c) {
    double d = discriminant(a, b, c);
    
    if (d > 0) {
        
        double x1 = (-b+sqrt(d))/(2*a);
        double x2 = (-b-sqrt(d))/(2*a);
        
        cout << "Løsningne er " << x1 << " og " << x2 << "\n";
    }
    
    if (d==0) {
            
        double x1 = (-b+sqrt(d))/(2*a);
        cout << "Løsningen er " << x1 << "\n";
    }
    
    if (d < 0) {
        
        cout << "Det er ingen løsninger\n";
    }
        
}

//Oppgave 4 c)

void solveQuadraticEquation() {
    double a;
    double b;
    double c;
    
    cout << "Skriv inn a: ";
    cin >> a;
    
    cout << "Skriv inn b: ";
    cin >> b;
    
    cout << "Skriv inn c: ";
    cin >> c;
    
    printRealRoots(a,b,c);
}

//Oppgave 5 a)

vector <int> calculateSeries (int loan, int rent, int years) {
    
    vector <int> paymentVector;
    int remainingLoan = loan;
    
    for (int i =0; i<years; ++i) {
        
        int payment = loan/years + rent*remainingLoan/100;
        
        paymentVector.push_back(payment);
        remainingLoan -= loan/years;
    
    }
    
    cout <<"\n";
    
    return paymentVector;
        
        
}

//Oppgave 5 b)

vector <int> calculateAnnuity(int loan, int rent, int years) {
    vector <int> payments;
    double double_rent = (double) rent/100;
    for (int i = 0; i < years;++i) {
        int payment = loan*double_rent/(1-pow((1+double_rent),-years));
        payments.push_back(payment);
    }
    return payments;
}

//Oppgave 5 c)

void makeTable () {
    int loan;
    int rent;
    int years;
    cout << "Skriv inn lån, renter og antall år: ";
    cin >> loan >>  rent >>  years;
    
    vector <int> serialVector = calculateSeries(loan, rent, years);
    vector <int> annuityVector = calculateAnnuity(loan, rent, years);
    
    int n = 15;
    
    cout <<  "År" << setw(n) << "Annuitet" << setw(n) <<"Serie" << setw(n) <<"Differanse\n";
    
    int totalAnnuity =  0;
    int totalSerial = 0;
    
    for (int i = 0; i <years; ++i) {
        int year = i+1;
        int difference = serialVector[i]-annuityVector[i];
        
        cout << left << setw(5) << year << setw(n) << right << annuityVector[i] << setw(n) << serialVector[i] << setw(n) << difference <<"\n";
        
        totalAnnuity += annuityVector[i];
        totalSerial += serialVector[i];
        }
    cout << setw(5)<< "Total" << setw(n) << right << totalAnnuity << setw(n) << totalSerial << setw(n) << totalAnnuity - totalSerial << "\n";
}


int main(){
    
    //Oppgave 3 a)
    
    
    
    int valg = 1;
    
    
    while (valg != 0) {
        
        cout << "Velg funksjon:\n0) Avslutt\n1) Summer to tall\n2) Summer flere tall\n3) Konverter fra NOK til EURO\n4) Skriv gangetabell\n5) Løs andregradslikning\n6) Sammenlign lån\nAngi valg (0-6):\n";
        
        cin >> valg;
        
        if (valg == 1) {
            
             inputIntegersAndPrintSum();
            
        }
        else if (valg == 2) {
                inputIntegersUsingLoopAndPrintSum();
        }
        
        else if (valg == 3) {
            
            convertEUtoNOK();
        }
        else if (valg == 4) {
            gangeTabell();
        }
        else if (valg ==5) {
            solveQuadraticEquation();
        }
        else if (valg == 6) {
            makeTable();
        
            }
        }
        
    
    
   /* inputAndPrintInteger();
    int number = inputInteger();
    cout << "Your wrote " << number << "\n";
    
    
    for (int i =0; i<16;++i) {
        cout << isOdd(i) << "\n";
    }
    
    printHumanReadableTime(10000);
    
   */
    
        
    
        
    
    
    return 0;
}




