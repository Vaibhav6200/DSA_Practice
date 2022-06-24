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

//     Using Morris Traversal
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



Node* makeTreeFromInorder(vector<int> arr, int start, int end){
    if(start == end)
        return new Node(arr[start]);

    int mid = (start+end)/2;
    Node* root = new Node(arr[mid]);

//     make left subtree using recursion
    root->left = makeTreeFromInorder(arr, start, mid-1);
    root->right = makeTreeFromInorder(arr, mid+1, end);

    return root;
}

Node* mergeTrees(Node* root) {
    vector<int> arr;
    inOrder(root, arr);

    int start = 0;
    int end = arr.size() - 1;
    Node* ans = makeTreeFromInorder(arr, start, end);

    return ans;
}