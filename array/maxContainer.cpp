#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int area=0;
        int maxArea = INT_MIN;

        int left=0;
        int right = n-1;
        int width = n-1;

        while(left < right)
        {
            area = min(height[left], height[right]) * width;
            maxArea = max(area, maxArea);

            if(height[left] < height[right])
                left++;
            else
                right--;
            width--;
        }

        return maxArea;
    }
};