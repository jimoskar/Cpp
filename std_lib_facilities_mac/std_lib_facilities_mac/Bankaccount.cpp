#include "Bankaccount.hpp"


AccountNum Bankaccount::getNewAccountNum() {
    static AccountNum currAccNum{ 1234, 99, 10000 };
    //Ved bruk av static overlever variabelen gjennom hele kjøringen av programmet
    
    if (currAccNum.customerNum > 99998) {
        currAccNum.customerNum = 10000;
    }
    else {
        ++currAccNum.customerNum;
    }
    return currAccNum;
}

bool operator==(const AccountNum& lhs, const AccountNum& rhs) {
    return ((lhs.bankNum == rhs.bankNum) && (lhs.accountType == rhs.accountType) && (lhs.customerNum == rhs.customerNum));
}

ostream& operator<<(ostream& os, const AccountNum& acc) {
    os << acc.bankNum << "." << acc.accountType << "." << acc.customerNum;
    return os;
}

    

