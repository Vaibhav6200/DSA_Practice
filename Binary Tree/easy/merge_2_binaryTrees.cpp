/*
You are given two binary trees root1 and root2.
Imagine that when you put one of them to cover the other, some nodes of the two trees are overlapped while the others are not.
You need to merge the two trees into a new binary tree. The merge rule is that if two nodes overlap,
then sum node values up as the new value of the merged node. Otherwise, the NOT null node will be used as the node of the new tree.
Return the merged tree.

Note: The merging process must start from the root nodes of both trees.
*/

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

Node* merges(Node* root1, Node* root2) {
    if(root1 == NULL && root2 == NULL)
        return NULL;

    Node *root = NULL;
//        Case1
    if(root1 != NULL && root2 == NULL){
        root = new Node(root1->data);
        root->left = merges(root1->left, root2);
        root->right = merges(root1->right, root2);
    }

//        Case2
    if(root1 == NULL && root2 != NULL){
        root = new Node(root2->data);
        root->left = merges(root1, root2->left);
        root->right = merges(root1, root2->right);
    }

//        Case3
    if(root1 != NULL && root2 != NULL){
        root = new Node(root1->data + root2->data);
        root->left = merges(root1->left, root2->left);
        root->right = merges(root1->right, root2->right);
    }
    return root;
}