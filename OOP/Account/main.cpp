#include<iostream>
#include "Account.h"
using namespace std;

int main(){
    Account vaibhav;

    vaibhav.set_name("Vaibhav");
    cout << "Welcome " << vaibhav.get_name() << endl;

    vaibhav.deposit(1000);

    vaibhav.set_balance(1000);
    cout << "Current Balance : " << vaibhav.get_balance() << endl;


    if(vaibhav.withdraw(500))
        cout << "Successfully withdrawn !" << endl;
    else
        cout << "Insufficient Funds " << endl;



    if(vaibhav.withdraw(1500))
        cout << "Successfully withdrawn !" << endl;
    else
        cout << "Insufficient Funds " << endl;

    return 0;
}