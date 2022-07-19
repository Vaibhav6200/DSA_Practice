#include<bits/stdc++.h>
using namespace std;


int characterReplacement(string s, int k) {

    int left=0, right=0;
    int n = s.length();
    int result=0;

    while(right != n){
        string substring = s.substr(left, right+1);
        int len = substring.length();
        int arr[26] {0};

        for(int i=0; i<len; i++){
            int x = substring[i] - 'A';
            arr[x]++;
        }

        // find count of max occuring character
        int maxCount = INT_MIN;
        for(int i=0; i<26; i++)
            if(arr[i] > maxCount)
                maxCount = arr[i];

        // check whether window is valid or not
        if(len - maxCount <= k){
            result = max(result, len);
            right++;
        }
        else
            left++;
    }

    return result;
}

int main()
{
    string s = "AABABBA";
    int k = 1;

    cout << characterReplacement(s, k);

    return 0;
}