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

// Approach 1: Iterative Method
vector<int> rightView(node *root)
{
    vector<int> result;
    if(root == NULL)
        return result;

    map<int, int> map;
    queue<pair<node*, int>> q;

    // Initializing Queue
    q.push({root, 0});      // currently we are at zero Level

    while(!q.empty()){
        pair<node*, int> temp = q.front();
        q.pop();

        node* frontnode = temp.first;
        int lvl = temp.second;

        map[lvl] = frontnode->data;

        if(frontnode->left)
            q.push({frontnode->left, lvl+1});
        if(frontnode->right)
            q.push({frontnode->right, lvl+1});
    }
    for(auto i: map)
        result.push_back(i.second);

    return result;

}

// Approach 2: Recursive Method
void solve(node* root, vector<int> &result, int level){
    // BASE CASE
    if(root == NULL)
        return;

    // If this condition is true that means we entered in a new level
    if(level == result.size())
        result.push_back(root->data);

    solve(root->right, result, level+1);
    solve(root->left, result, level+1);
}
vector<int> recursive_rightView(node *root){
    vector<int> result;
    solve(root, result, 0);
    return result;
}

int main()
{
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    node* root = NULL;
    root = buildTree(root);

    return 0;
}

