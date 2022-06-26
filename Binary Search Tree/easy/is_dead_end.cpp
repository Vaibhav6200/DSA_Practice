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

void inorder(Node* root, unordered_map<int, int> &allNodes, unordered_map<int, int> &leaf){
    if(root == NULL)
        return;

    allNodes[root->data]++;

    // insert leaf node in your set
    if(root->left == NULL && root->right == NULL)
        leaf[root->data];

    inorder(root->left, allNodes, leaf);
    inorder(root->right, allNodes, leaf);
}

bool isDeadEnd(Node *root)
{
    unordered_map<int, int> allNodes;
    unordered_map<int, int> leaf;
    inorder(root, allNodes, leaf);

    int n=leaf.size();
    for(auto i: leaf){
        int x = i.first;

        if((x == 1) && allNodes.count(x+1)>0)
            return true;

        else if(allNodes.count(x-1)>0 && allNodes.count(x+1)>0)
            return true;
    }

    return false;
}