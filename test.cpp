#include<bits/stdc++.h>
using namespace std;


class Node{
public:
    int data;
    Node* left;
    Node* right;
    Node(int val){
        data = val;
        left = right = NULL;
    }
};

int widthOfBinary(Node* root) {
    if(root == NULL)
        return 0;

    int ans=0;
    queue<pair<Node*, int>> q;      // {Node, index}
    q.push({root, 0});      // taking 1 based indexing

    while(!q.empty()){
        int size = q.size();
        int mmin = q.front().second;
        int first, last;
        for(int i=0; i<size; i++){
            int curr_id = q.front().second - mmin;
            Node* node = q.front().first;
            q.pop();
            if(i==0)
                first = curr_id;
            if(i==size-1)
                last = curr_id;
            if(node->left)
                q.push({node->left, curr_id*2+1});
            if(node->right)
                q.push({node->right, curr_id*2+2});
        }
        ans = max(ans, last-first+1);
    }

    return ans;
}