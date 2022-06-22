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


// Approach 1: Iterative Method {Time - O()}
vector<int> diagonal(node *root){
    vector<int> result;
    if(root == NULL)
        return result;

    queue<node*> q;

//   Queue Initiallization
    q.push(root);

    while(!q.empty()){
        node* temp = q.front();
        q.pop();

        while(temp != NULL){
            result.push_back(temp->data);
            if(temp->left)
                q.push(temp->left);
            temp = temp->right;
        }
    }
    return result;
}


// Approach 2: Recursive Method
void solve(node* root, map<int, vector<int>> &map, int diag){
    if(root == NULL)
        return;

    map[diag].push_back(root->data);

    solve(root->left, map, diag+1);
    solve(root->right, map, diag);
}

vector<int> diagonal(node* root){
    vector<int> result;
    if(root == NULL)
        return result;

    map<int, vector<int>> map;
    solve(root, map, 0);

    for(auto i: map){
        for(auto j: i.second)
            result.push_back(j);
    }
    return result;
}


int main()
{
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    node* root = NULL;
    root = buildTree(root);

    return 0;
}