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

pair<int, int> solve(node* root){ // {MaxSum Including Currnode, MaxSum Excluding Currnode}
// Base Case
    if(root == NULL)
        return {0, 0};

    pair<int, int> left = solve(root->left);
    pair<int, int> right = solve(root->right);

// MaxSum including Current node
    int a = root->data + left.second + right.second;
    int b = max(left.first, left.second) + max(right.first, right.second);

    return {a, b};
}
int getMaxSum(node *root)
{
    pair<int, int> temp = solve(root);
    int a = temp.first;
    int b = temp.second;
    return max(a,b);
}

int main()
{
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    node* root = NULL;
    root = buildTree(root);

    return 0;
}
