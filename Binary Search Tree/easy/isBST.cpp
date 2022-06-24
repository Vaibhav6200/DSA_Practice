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


// Approach 1: find inorder traversal and check whether its sorted or not
void inOrder(Node* root, vector<int> &ans){
    if(root == NULL)
        return;
    inOrder(root->left, ans);
    ans.push_back(root->data);
    inOrder(root->right, ans);
}

bool isBST(Node* root){
    vector<int> inorder;
    inOrder(root, inorder);

    for(int i=0; i<inorder.size()-1; i++){
        if(inorder[i]>=inorder[i+1])
            return false;
    }
    return true;
}


int predecessor(Node* root){
    if(root == NULL)
        return -1;
    while(root->right!=NULL)
        root = root->right;
    return root->data;
}

int successor(Node* root){
    if(root == NULL)
        return -1;
    while(root->left!=NULL)
        root = root->left;
    return root->data;
}

// Approach 2: Checking Using Recursion
bool isBST(Node* root)
{
    // Base Case
    if((root == NULL) || (root->left == NULL && root->right == NULL))
        return true;

    // Check Left Subtree
    bool leftCheck = isBST(root->left);

    // Check Right Subtree
    bool rightCheck = isBST(root->right);
    // If Both left Subtree and Right Subtree are valid BST then check for current node

    if(leftCheck && rightCheck)
    {
        // Check Current Node
        bool flag1 = true;
        bool flag2 = true;

        if(root->left){
             int pred = predecessor(root->left);
             if(pred >= root->data)
                flag1 = false;
        }

        if(root->right){
             int succ = successor(root->right);
            if(succ <= root->data)
                flag2 = false;
        }

        if(flag1 && flag2)
            return true;
    }
    return false;
}


// Approach 3: Range Based Approach