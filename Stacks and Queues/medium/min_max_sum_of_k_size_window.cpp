#include<bits/stdc++.h>
using namespace std;


long long sumOfMaxAndMin(vector<int> &arr, int n, int k) {
    deque<int> maxi(k);
    deque<int>mini(k);

//     Step 1: Processing First k elements
    for(int i=0; i<k; i++){
        while(!maxi.empty() && arr[maxi.back()] <= arr[i])
            maxi.pop_back();
        while(!mini.empty() && arr[mini.back()] >= arr[i])
            mini.pop_back();
        maxi.push_back(i);
        mini.push_back(i);
    }
    int sum=0;
    sum += arr[maxi.front()] + arr[mini.front()];

//     Processing remaining n-k elements and finding sum
    for(int i=k; i<n; i++){
//         Logic for Removal of 1 element
        while(!maxi.empty() && i - maxi.front() >= k)
            maxi.pop_front();
        while(!mini.empty() && i - mini.front() >= k)
            mini.pop_front();

//         Logic for Addition of 1 element (COPY PASTE ABOVE ADDITION LOGIC)
        while(!maxi.empty() && arr[maxi.back()] <= arr[i])
            maxi.pop_back();
        while(!mini.empty() && arr[mini.back()] >= arr[i])
            mini.pop_back();
        maxi.push_back(i);
        mini.push_back(i);

        sum += arr[maxi.front()] + arr[mini.front()];
    }

    return sum;
}

int main()
{

    return 0;
}