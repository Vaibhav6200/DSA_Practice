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

Node* constructTree(int pre[], int &index, int st, int end, int size){
    if(index == size || st > end)
        return NULL;

    Node* root = new Node(pre[index++]);
    if(st == end)
        return root;

    // Now find root el
    int i;
    for(int i=st+1; i<=end; i++){
        if(pre[i] > root->data)        // pre[st] is root , if we get any element greater than root
            break;
    }

    // Now recursively make left and right subtrees
    constructTree(pre, index, st, i-1, size);
    constructTree(pre, index, i, end, size);

    return root;
}

int main()
{
    int pre[] = {10, 5, 1, 7, 40, 50};
    int size = 6;
    int index=0;
    constructTree(pre, index, 0, size-1, size);
    return 0;
}