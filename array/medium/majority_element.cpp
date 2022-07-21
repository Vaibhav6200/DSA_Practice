#include<bits/stdc++.h>
using namespace std;


// Challange : Could you solve the problem in linear time and in O(1) space?
class Solution {
public:

/*
    Approach (using Boyer Moore Algo) Time - O(n), Space - O(1)
*/
    int majorityElement(vector<int>& nums) {
        int count = 0;
        int result = 0;
        for(int element: nums){
            if(count == 0)
                result = element;

            if(result == element)
                count++;
            else
                count--;
        }
        return result;
    }
};

int main()
{

    return 0;
}