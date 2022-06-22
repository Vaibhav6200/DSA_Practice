#include <bits/stdc++.h>
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

pair<bool, int> checkBalanced(node *root)
{
    if (root == NULL)
        return {true, 0};

    pair<bool, int> left = checkBalanced(root->left);
    pair<bool, int> right = checkBalanced(root->right);

    bool flag1 = left.first; // tells whether left subtree is balanced or not
    bool flag2 = right.first;

    int diff = abs(left.second - right.second); // diff of left & right subtree heights

    pair<bool, int> ans = {false, 0};

    if (diff <= 1 && flag1 && flag2)     // if our node is leaf or its diff is <=1 then its balanced
        ans.first = true;

    ans.second = max(left.second, right.second) + 1;
    return ans;
}

// Function to check whether a binary tree is balanced or not.
bool isBalanced(node *root)
{
    return checkBalanced(root).first;
}

int main()
{

    return 0;
}