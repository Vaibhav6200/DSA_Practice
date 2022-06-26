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



Node* iterate(Node* &current){
    // here throw some exception
    if(current == NULL)
        return NULL;

    if(current->left == NULL){
        Node* temp = current;
        current = current->right;
        return temp;
    }
    else{
        Node* pred = current->left;
        while(pred->right!=NULL && pred->right != current)
            pred = pred->right;

        if(pred->right == NULL){
            pred->right = current;
            current = current->left;
        }
        else{
            pred->right = NULL;
            Node* temp = current;
            current = current->right;
            return temp;
        }
    }
    return iterate(current);
}


int main()
{
    Node* root = NULL;
    takeInput(root);

    Node* current = root;
    Node* temp = NULL;

    int x;

    cout << "---------------------------------" << endl;
    while(true){
        temp = iterate(current);
        cout << temp->data << endl << endl;

        if(current == NULL)
            cout << "No Such Element Found";

        cout << "Do You want to continue (1/0) : ";
        cin >> x;
        if(x == 0)
            break;
    }

    return 0;
}