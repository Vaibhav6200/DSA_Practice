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


Node* invertTree(Node* root) {
    if((root == NULL) || (root->left == NULL && root->right == NULL))
        return root;

    if(root->left)
        root->left = invertTree(root->left);
    if(root->right)
        root->right = invertTree(root->right);

//        Case 1: 1 Left Child
    if(root->left != NULL && root->right == NULL){
        root->right = root->left;
        root->left = NULL;
    }

//        Case 2: 1 right Child
    else if(root->left == NULL && root->right != NULL){
        root->left = root->right;
        root->right = NULL;
    }

//        Case 3: 2 Child
    else{
        Node* temp = root->right;
        root->right = root->left;
        root->left = temp;
    }

    return root;
}