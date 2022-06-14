#include<bits/stdc++.h>
using namespace std;

class Stack{
public:
    queue<int> q;
    queue<int> temp;

    void push(int val){
        if(q.empty())
            q.push(val);
        else{
            // Step1: Taking all elements from our queue to temp queue
            while(!q.empty()){
                int x = q.front();
                q.pop();
                temp.push(x);
            }

            // Step 2: Adding our value in our queue
            q.push(val);

            // Step 3: Bringing all values back to our queue from temp queue
            while(!temp.empty()){
                int x = temp.front();
                temp.pop();
                q.push(x);
            }
        }
    }
};

int main()
{

    return 0;
}