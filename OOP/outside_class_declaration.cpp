#include<bits/stdc++.h>
using namespace std;

class Account{
    double balance;
public:

    void setBalance(double bal);
    double getBalance();
};

void Account::setBalance(double bal){
    balance = bal;
}
double Account::getBalance(){
    return balance;
}

int main()
{

    return 0;
}