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

//  Since Space complexity can Max = height of Binary Tree, So we cannot use recursion inorder
//  So we Use Moris Traversal - {Time- O(n), Space - O(1) }

void inOrder(Node* root, vector<int> &arr){
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


int isPairPresent(struct Node *root, int target)
{
    vector<int> arr;
    inOrder(root, arr);
    int n=arr.size();

    // Now using 2 pointer approach to find sum 2 pair
    int i=0;
    int j=n-1;
    while(i<j){
        int sum = arr[i] + arr[j];
        if(target == sum)
            return 1;       // pair exists
        else if(target < sum)
            j--;
        else
            i++;
    }
    return 0;
}