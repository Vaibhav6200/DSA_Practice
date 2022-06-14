#include<bits/stdc++.h>
using namespace std;

int getBit(int n, int pos){
    return (n & (1<<pos));
}

int get_rhs_bit_pos(int n){
    int flag =0;
    int pos=0;
    while(flag!=1){
        flag = n&1;
        pos++;
        n = n>>1;
    }
    return pos-1;
}

void get_2_unique(int arr[], int n){
    int xorSum=0;
    for(int i=0; i<n; i++)
        xorSum = xorSum ^ arr[i];

    int pos = get_rhs_bit_pos(xorSum);

    int num1=0, num2=0;
    bool flag;
    for(int i=0; i<n; i++){
        flag = getBit(arr[i], pos);
        if(flag)
            num1 = num1^arr[i];
        else
            num2 = num2^arr[i];
    }
    cout << num1 << " " << num2 << endl;
}

int main()
{
    int arr[] = {2, 4, 6, 7, 4, 5, 6, 2};
    int n=8;
    get_2_unique(arr, n);

    return 0;
}