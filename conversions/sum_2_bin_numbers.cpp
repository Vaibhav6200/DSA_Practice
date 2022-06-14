#include<bits/stdc++.h>
using namespace std;

int binary_sum(int num1, int num2){
    int sum, a, b, x=1, carry=0, temp, ans=0;
    while(num1>0 && num2>0){
        a = num1%10;
        b = num2%10;
        sum = a + b + carry;
        if(sum<2){
            temp=sum%2;
            carry=0;
        }
        else{
            temp=sum%2;
            carry=1;
        }
        ans += temp*x;
        x*=10;

        num1/=10;
        num2/=10;
    }
    while(num1>0){
        a = num1%10;
        sum = a + carry;
        if(sum<2){
            temp=sum%2;
            carry=0;
        }
        else{
            temp=sum%2;
            carry=1;
        }
        ans += temp*x;
        x*=10;
        num1/=10;
    }
    while(num2>0){
        b = num2%10;
        sum = b + carry;
        if(sum<2){
            temp=sum%2;
            carry=0;
        }
        else{
            temp=sum%2;
            carry=1;
        }
        ans += temp*x;
        x*=10;
        num2/=10;
    }
    if(carry)
        ans+=carry*x;
    return ans;
}

int main()
{
    cout << binary_sum(10, 1000);
    return 0;
}