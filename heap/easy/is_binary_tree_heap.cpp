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

/*
    Approach

For a binary tree to become a heap it must satisfy these 2 conditions
1. It should be C.B.T.
2. It should be in heap order
    for max heap - parent > child
    for min heap - parent < child
*/

int totalNodes(Node* root){
    if(root == NULL)
    return 0;
    int x = totalNodes(root->left);
    int y = totalNodes(root->right);

    return x+y+1;
}

/*
    Approach
    for any Node if (i > NodesCount) then its not a CBT
    NOTE: here i=index of that node and NodesCount is total no of nodes in the tree
*/
bool isCBT(Node* root, int i, int NodesCount){
    if(root == NULL)
        return true;

    if(i >= NodesCount)
        return false;

    bool flag1 = isCBT(root->left, 2*i+1, NodesCount);
    bool flag2 = isCBT(root->right, 2*i+2, NodesCount);

    return (flag1 && flag2);
}

bool heapOrder(Node* root){
    if((root == NULL) || (root->left == NULL && root->right == NULL))
        return true;

    if(root->left != NULL && root->right == NULL){
        if(root->data > root->left->data)
            return true;
    }
    else{
        if((root->data > root->left->data) && (root->data > root->right->data))
            return true;
    }
    return false;
}


bool isHeap(struct Node* root) {
    int NodesCount = totalNodes(root);
    bool flag1 = isCBT(root, 0, NodesCount);
    bool flag2 = heapOrder(root);

    return flag1 && flag2;

}