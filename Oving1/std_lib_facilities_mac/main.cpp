#include "std_lib_facilities.h"

int maxOfTwo(int a, int b) {
    
    if (a>b) {
        cout << "A is greater than B \n" ;
        return a;
    } else {
        cout << "B is greater than or equal to A \n";
        return b;
    }
    
}

int fibonacci(int n) {
    int a = 0;
    int b = 1;
    cout << "Fibonnaci numbers: \n";
    for (int x = 1; x< n +1; x+= 1) {
        cout << x << b << "\n";
        int temp = b;
        b += a;
        a = temp;
    }
    cout << "----\n";
    return b;
    
}

int squareNumberSum(int n) {
    int totalSum = 0;
    for (int i = 0; i < n; ++i) {
        totalSum += i*i;
        cout << i*i << "\n";
    }
    cout << totalSum << "\n";
    return totalSum;
}

void triangleNumbersBelow(int n) {
    int acc = 1;
    int num = 2;
    cout << "Triangle numbers below " << n << ":\n";
    while (acc < n) {
        cout << acc << "\n";
        acc += num;
        num += 1;
        
    }
    cout << "\n";
    
}

bool isPrime( int n) {
    for (int j = 2; j < n; ++j) {
        if (n%j == 0) {
            return false;
        }
    }
    return true;
}

void naivePrimeNumberSearch (int n) {
    for (int number = 2; number < n; ++number) {
        if (isPrime(number)) {
            cout << number << " is a prime \n";
        }
    }

}

unsigned int findGreatestDivisor (unsigned int n) {
    for (unsigned int divisor = n-1; divisor > 0; --divisor) {
        if (n%divisor == 0) {
            return divisor;
        }
    }
    return 1;
    
}


int main(){
    
    cout << "Oppgave a \n";
    cout << maxOfTwo(5, 6) << "\n";
    
    cout << "Oppgave c \n";
    cout << fibonacci(5) << "\n";
    
    cout << "Oppgave d \n";
    cout << squareNumberSum(5) << "\n";
    
    cout << "Oppgave e \n";
    triangleNumbersBelow(5);
    
    cout << "Oppgave f \n";
    cout << isPrime(4) << "\n";
    
    cout << "Oppgave g \n";
    naivePrimeNumberSearch(5);
    
    cout << "Oppgave h \n";
    cout << findGreatestDivisor(10) << "\n";
    
    
    
    
    

    
    return 0;
}
