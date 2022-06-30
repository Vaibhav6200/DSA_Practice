#include<bits/stdc++.h>
using namespace std;


int minCost(int arr[], int n) {
    priority_queue<int , vector<int >, greater<int >> pq;

    for(int i=0; i<n; i++)
        pq.push(arr[i]);

    int min_cost=0;
    while(pq.size() > 1){
        int  x = pq.top(); pq.pop();
        int  y = pq.top(); pq.pop();

        int  sum = x+y;
        min_cost += sum;
        pq.push(sum);
    }
    return min_cost;
}

