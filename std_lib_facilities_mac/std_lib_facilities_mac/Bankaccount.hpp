#pragma once
#include "std_lib_facilities.h"

struct AccountNum {
    int bankNum;
    int accountType;
    int customerNum;
};

ostream& operator<<(ostream& os, const AccountNum& acc);
bool operator==(const AccountNum& lhs, const AccountNum& rhs);


class Bankaccount {
private:
    string owner;
    const AccountNum accountNum;
    int balance;
    
    AccountNum getNewAccountNum();
    
public:
    Bankaccount(string owner, int balance) : owner{ owner }, balance{ balance }, accountNum{ getNewAccountNum() } {}
    Bankaccount(string owner) : Bankaccount{ owner, 0 } {}
    
    int getBalance() { return balance; } const
    AccountNum& getAccountNum() { return accountNum; } const
    string getOwner() { return owner; } const
    
    void changeOwner(string newOwner) { owner = newOwner; }
    

};
