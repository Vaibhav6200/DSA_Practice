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

node* buildTree_levelOrderTraversal(node* root){
    int data;
    cout << "Enter root node data: ";
    cin >> data;
    root = new node(data);

    queue<node*> q;
    q.push(root);

    while(!q.empty()){
        node* temp = q.front();
        q.pop();

        cout << "Enter Left Child of " << temp->data << " : ";
        cin >> data;
        if(data != -1){
            temp->left = new node(data);
            q.push(temp->left);
        }

        cout << "Enter Right Child of " << temp->data << " : ";
        cin >> data;
        if(data != -1){
            temp->right = new node(data);
            q.push(temp->right);
        }
    }
    return root;
}

void preOrder(node* root){
    if(root == NULL)
       return;
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

int main()
{
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    node* root = NULL;
    root = buildTree_levelOrderTraversal(root);
    preOrder(root);

    return 0;
}