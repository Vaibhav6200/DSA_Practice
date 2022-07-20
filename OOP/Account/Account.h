#ifndef ACCOUNT
#define ACCOUNT

#include<string>
using namespace std;

class Account{
private:
    double balance;
    string name;
public:
    void set_balance(double bal){
        balance = bal;
    }
    double get_balance(){
        return balance;
    }

    void set_name(string s);
    string get_name();

    bool deposit(double amount);
    bool withdraw(double amount);
};

#endif