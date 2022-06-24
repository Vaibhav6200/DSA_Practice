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

Node* LCA(Node *root, int n1, int n2)
{

    if(root == NULL)
        return NULL;

    // If true means: Both roots in Left Subtree
    if(n1 < root->data && n2 < root->data)
        return LCA(root->left, n1, n2);

    if(n1 > root->data && n2 > root->data)
        return LCA(root->right, n1, n2);

    return root;
}