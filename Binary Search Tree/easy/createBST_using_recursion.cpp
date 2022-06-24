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


int main()
{
    Node* root = NULL;
    takeInput(root);

    levelOrderTraversal(root);

    return 0;
}