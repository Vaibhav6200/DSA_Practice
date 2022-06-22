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


// Approach 1: Using Recursions and Vector
int solve(node* root, int k, int val, vector<int> path){       // pair : {node, k}
    if(root == NULL)
        return -1;

    path.push_back(root->data);

    if(root->data == val){      // means we found our node
        int size = path.size();
        int idx = size - k - 1;
        if(idx >=0 )
            return path[idx];
        else
            return -1;

    }

    int x = solve(root->left, k, val, path);
    int y = solve(root->right, k, val, path);

    if(x == -1 && y == -1)
        return -1;

    if(x != -1 && y == -1)
        return x;

    if(x == -1 && y != -1)
        return y;
}
int kthAncestor(node *root, int k, int val)
{
    vector<int> path;
    int ans = solve(root, k, val, path);
    return ans;
}

int main()
{
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    node* root = NULL;
    root = buildTree(root);

    return 0;
}

