#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;
    Node(int val){
        data = val;
        left = right = NULL;
    }
};

Node* insertIntoBST(Node* root, int val){
    if(root == NULL)
        return new Node(val);

    if(val > root->data)
        root->right = insertIntoBST(root->right, val);

    else if(val < root->data)
        root->left = insertIntoBST(root->left, val);

    return root;
}

Node* takeInput(Node* &root){
    cout << "Enter Nodes in BST (-1 to stop)" << endl;
    int data;
    cin >> data;

    while(data != -1){
        root = insertIntoBST(root, data);
        cin >> data;
    }
    return root;
}

void levelOrderTraversal(Node* root){
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node* temp = q.front();
        q.pop();

        // LOGIC for seperating different levels of a tree
        if(temp == NULL){
            cout << endl;
            if(!q.empty())
                q.push(NULL);
        }
        else{
            cout << temp->data << " ";
            if(temp->left != NULL)
                q.push(temp->left);

            if(temp->right)
                q.push(temp->right);
        }
    }
}



Node* searchNode(Node* root, int key){
    if(root->data == key)
        return root;
    if(key < root->data)
        return searchNode(root->left, key);
    else
        return searchNode(root->right, key);
}

int predecessor(Node* root){
    if(root == NULL)
        return -1;
    while(root->right!=NULL)
        root = root->right;
    return root->data;
}

int successor(Node* root){
    if(root == NULL)
        return -1;
    while(root->left!=NULL)
        root = root->left;
    return root->data;
}


pair<int,int> predecessorSuccessor(Node* root, int key){
//     Base Case
    if(root == NULL)
        return {-1, -1};

    Node* target = searchNode(root, key);
    int pred = -1;
    int succ = -1;

    Node* temp;
    if(target->left)
        pred = predecessor(root->left);

    if(target->right)
        succ = successor(root->right);

    cout << target->data << " : " << pred << " : " << succ << endl;
    return {pred, succ};
}

int main()
{
    Node* root = NULL;
    takeInput(root);

    int key;
    cout << "Enter Key : ";
    cin >> key;

    pair<int, int> temp = predecessorSuccessor(root, key);

    cout << "Predecessor : " << temp.first << endl;
    cout << "Successor : " << temp.second << endl;


    return 0;
}
