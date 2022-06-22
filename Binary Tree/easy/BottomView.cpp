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

vector<int> BottomView(node* root){
    vector<int> result;
    if(root == NULL)
        return result;

    map<int, int> map;
    queue<pair<node*, int>> q;      // {Node, Horizontal Distance}

    // Queue Initialization
    q.push({root, 0});      // initially HD = 0

    while(!q.empty()){
        pair<node*, int> temp = q.front();
        q.pop();

        node* frontNode = temp.first;
        int hd = temp.second;

        map[hd] = frontNode->data;  // if node does not exist then map it with its horizontal distance

        if(frontNode->left)
            q.push({frontNode->left, hd-1});

        if(frontNode->right)
            q.push({frontNode->right, hd+1});
    }

    for(auto i: map)
        result.push_back(i.second);

    return result;
}

int main()
{
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    node* root = NULL;
    root = buildTree(root);

    return 0;
}