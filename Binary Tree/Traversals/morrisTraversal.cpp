// This Question is asked in "GOOGLE INTERVIEW"
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

Node* predecessor(Node* pred, Node* curr){
    if(pred == NULL)
        return NULL;
    while(pred->right!=NULL && pred->right != curr)
        pred = pred->right;

    return pred;
}


//  Moris Traversal - { Time- O(n), Space - O(1) }

void inOrder(Node* root, vector<int> &arr)
{
    Node* curr = root;
    while(curr != NULL)
    {
        // If curr left does not exist then visit node and move to right
        if(curr->left == NULL){
            arr.push_back(curr->data);
            curr = curr->right;
        }
        else{
            Node* pred = predecessor(curr->left, curr);
            if(pred->right == NULL){
                pred->right = curr;
                curr = curr->left;
            }
            else{
                pred->right = NULL;
                arr.push_back(curr->data);
                curr = curr->right;
            }
        }
    }
}