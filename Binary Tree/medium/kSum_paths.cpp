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

void solve(node* root, int k, int &count, vector<int> &path){
    // BASE CASE
    if(root == NULL)
        return;

    path.push_back(root->data);

    // Left
    solve(root->left, k, count, path);
    // Right
    solve(root->right, k, count, path);

    // Check For K-Sum
    int size = path.size();
    int sum = 0;
    for(int i=size-1; i>=0; i--){
        sum += path[i];
        if(sum == k)
            count++;
    }
    path.pop_back();
}

int sumK(node *root, int k){
    int count=0;
    vector<int> path;
    solve(root, k, count, path);
    return count;
}

int main()
{
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    node* root = NULL;
    root = buildTree(root);

    return 0;
}

