#include<bits/stdc++.h>
using namespace std;


// Code to reverse a number
int reverse(int n){
    int curr=0;
    while(n>0){
        curr = curr*10 + n%10;
        n = n/10;
    }
    return curr;
}

int binary_to_decimal(int n){
    int counter=0, curr=0, ans=0;
    while(n>0){
        curr = n%10;
        ans += curr*pow(2, counter);
        n/=10;
        counter++;
    }
    return ans;
}

int octal_to_decimal(int n){
    int counter=0, curr=0, ans=0;
    while(n>0){
        curr = n%10;
        ans += curr*pow(8, counter);
        n/=10;
        counter++;
    }
    return ans;
}

int find_num(int n){

}

int hexadecimal_to_decimal(string n){
    int s = n.size();
    int ans=0, num=0, x=1;
    for(int i=s-1; i>=0; i--){
        if (n[i]>='0' && n[i]<='9')
            num = n[i]-'0';
        else if(n[i]>='A' && n[i]<='F')
            num = n[i]-'A' + 10;
        ans = ans + x*num;
        x*=16;
    }
    return ans;
}

int decimal_to_binary(int n){
    int rem=0, ans=0, x=1;

    while(n>0){
        rem = n%2;
        n/=2;
        ans = rem*x + ans;
        x*=10;
    }
    return ans;
}

int decimal_to_octal(int n){
    int rem=0, ans=0, x=1;

    while(n>0){
        rem = n%8;
        n/=8;
        ans = rem*x + ans;
        x*=10;
    }
    return ans;
}

string str_reverse(string s){
    string ans="";
    for(int i=s.length()-1; i>=0 ; i--)
        ans.push_back(s[i]);
    return ans;
}

string decimal_to_hexadecimal(int n){
    int rem=0, x=1;
    string ans="";

    while(n>0){
        rem = n%16;
        n/=16;
        if (rem>=0 && rem <=9)
            ans = ans + to_string(rem);
        else if(rem>9 && rem <=15){
            char c = rem+'A'-10;
            ans.push_back(c);
        }
        x*=10;
    }
    return str_reverse(ans);
}

int octal_to_hexadecimal(int n){

}

int main()
{
    cout << binary_to_decimal(010);
    cout << octal_to_decimal(17);
    cout << hexadecimal_to_decimal("1CF");
    cout << decimal_to_binary(32);
    cout << decimal_to_octal(50);
    cout << decimal_to_hexadecimal(455);

    return 0;
}