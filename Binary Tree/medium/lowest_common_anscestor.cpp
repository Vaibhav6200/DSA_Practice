#include<bits/stdc++.h>
using namespace std;


class node{
public:
    int data;
    node* left;
    node* right;
    node(int val){
        data = val;
        left = right = NULL;
    }
};

node* lca(node* root ,int n1 ,int n2 )
{
    if(root == NULL)
        return NULL;

    if(root->data == n1)
        return root;
    else if(root->data == n2)
        return root;

    node* leftAns = lca(root->left, n1, n2);
    node* rightAns = lca(root->right, n1, n2);

    if(leftAns == NULL && rightAns == NULL)
        return NULL;

    if(leftAns != NULL && rightAns == NULL)
        return leftAns;

    if(rightAns == NULL && rightAns != NULL)
        return rightAns;

    if(leftAns != NULL && rightAns != NULL)
        return root;
}
