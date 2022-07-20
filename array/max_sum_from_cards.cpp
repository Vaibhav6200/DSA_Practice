#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();

        int left = 0;
        int right = n-k;

        int total = accumulate(cardPoints.begin() + right, cardPoints.end(), 0);
        // initiallizing "maxPoints" variable
        int maxPoints = total;

        while(right < n){
            total += cardPoints[left] - cardPoints[right];
            maxPoints = max(maxPoints, total);
            left++;
            right++;
        }
        return maxPoints;
    }
};

int main()
{

    return 0;
}