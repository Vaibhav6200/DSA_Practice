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

pair<bool, int> isSumTreeFast(node *root){
    if (root == NULL)
        return {true, 0};

    if (root->left == NULL && root->right == NULL)
        return {true, root->data};

    pair<bool, int> left = isSumTreeFast(root->left);
    pair<bool, int> right = isSumTreeFast(root->right);

    bool flag1 = left.first;
    bool flag2 = right.first;
    bool condition = root->data == left.second + right.second;

    pair<bool, int> ans = {false, 0};

    if (flag1 && flag2 && condition)
        ans.first = true;

    // ans.second = root->data + left.second + right.second;
    ans.second = 2 * root->data;
    return ans;
}

bool isSumTree(node *root){
    return isSumTreeFast(root).first;
}

int main()
{
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    node* root = NULL;
    root = buildTree(root);

    return 0;
}