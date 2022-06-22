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
    cout << "Enter Data : ";
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


node* solve(node* root, int &k, int val){       // pair : {node, k}
    if(root == NULL)
        return NULL;

    if(root->data == val)
        return root;

    node* leftAns = solve(root->left, k, val);
    node* rightAns = solve(root->right, k, val);

    if(leftAns != NULL && rightAns == NULL){
        --k;
        if(k <= 0){
            // answer lock
            k = INT_MAX;
            return root;
        }
        return leftAns;
    }


    if(leftAns == NULL && rightAns != NULL){
        --k;
        if(k <= 0){
            // answer lock
            k = INT_MAX;
            return root;
        }
        return rightAns;
    }

    return NULL;
}

int kthAncestor(node *root, int k, int val)
{
    node* temp =  solve(root, k, val);
    if(temp == NULL || temp->data == val)
        return -1;
    return temp->data;
}

int main()
{
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    node* root = NULL;
    root = buildTree(root);

    return 0;
}


