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

Node* construct(vector<int> &pre, vector<int> &post, int &index, int l, int h, int size){
//  Base case: if pre array is over : No element to insert
    if(index == size || l>h)
        return NULL;

//  1st Element of preorder is always root node
    Node* root = new Node(pre[index++]);

    if(l == h)
        return root;

//  search for pre(i+1)th element in post array
    int i;
    for(i=l; i<=h; i++){
        if(pre[index] == post[i])
            break;
    }

    root->left = construct(pre, post, index, l, i, size);
    root->right = construct(pre, post, index, i+1, h-1, size);

    return root;
}

Node* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
    int index = 0;
    int size = postorder.size();
    return construct(preorder, postorder, index, 0, size-1, size);
}