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

node* buildTree(node* root){
    int data;
    cout << "Enter Data : " << endl;
    cin >> data;
    root = new node(data);

    if(data == -1)
        return NULL;

    cout << "Enter data to insert at left of " << data << endl;
    root->left = buildTree(root->left);

    cout << "Enter data to insert at right of " << data << endl;
    root->right = buildTree(root->right);

    return root;
}


void preOrder(node* root){
    if(root == NULL)
       return;
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}


int main()
{
    node* root = NULL;
    root = buildTree(root);

    preOrder(root);
    cout << endl;


// 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    return 0;
}