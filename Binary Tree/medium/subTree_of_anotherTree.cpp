#include<bits/stdc++.h>
using namespace std;


class Node{
public:
    int data;
    Node* left;
    Node* right;
    Node(int data){
        data = data;
        left = right = NULL;
    }
};

bool match(Node* root, Node* subRoot){
    if(root!=NULL && subRoot!=NULL){
//            first match left sub of both root and subroot
        bool flag1 = match(root->left, subRoot->left);

//            Now match their right sub
        bool flag2 = match(root->right, subRoot->right);

//            If both sub matches then check for current Node
        if(flag1 && flag2 && (root->data == subRoot->data))
            return true;
        return false;
    }
    else if(root == NULL && subRoot == NULL)
        return true;
    return false;
}

void inorder(Node* root, Node* subRoot, bool &ans){
    if(root!=NULL){
        inorder(root->left, subRoot, ans);

        if(match(root, subRoot))
            ans = true;

        inorder(root->right, subRoot, ans);
    }
}

bool isSub(Node* root, Node* subRoot) {
    bool ans=false;
    inorder(root, subRoot, ans);
    return ans;
}
