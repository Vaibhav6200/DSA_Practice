#include "Account.h"
using namespace std;

void Account::set_name(string s){
    name = s;
}

string Account::get_name(){
    return name;
}

bool Account::deposit(double amount){
    balance+=amount;
    return true;
}

bool Account::withdraw(double amount){
    if(balance-amount>=0){
        balance-=amount;
        return true;
    }
    return false;
}