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


// Space - O(n)
map<int, int> createMapping(int in[], int n){
    map<int, int> map;
    for(int i=0; i<n; i++)
        map[in[i]] = i;

    return map;
}

node* solve(int in[], int inorderStart, int inorderEnd, int post[], int &index, int n, map<int, int> &nodeToIndex){
    // Base Case
    if(index == -1 || inorderStart > inorderEnd)
        return NULL;

    int element = post[index--];
    node* root = new node(element);
    int pos = nodeToIndex[element];

    // Recursive Calls
    root->right = solve(in, pos+1, inorderEnd, post, index, n, nodeToIndex);
    root->left = solve(in, inorderStart, pos-1, post, index, n, nodeToIndex);

    return root;
}

node* buildTree(int in[],int post[], int n)
{
    int inorderStart = 0;
    int inorderEnd = n-1;
    int index = n-1;

    map<int, int> map = createMapping(in, n);
    node* root = solve(in, inorderStart, inorderEnd, post, index, n, map);
    return root;
}

int main()
{
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    node* root = NULL;
    root = buildTree(root);

    return 0;
}

