// WHY THIS CODE IS NOT PASSING TEST CASE ON GFG PRACTICE QUESTION



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


Node* predecessor(Node* root){
    if(root == NULL)
        return NULL;

    while(root->right != NULL)
        root = root->right;
    return root;
}

Node* successor(Node* root){
    if(root == NULL)
        return NULL;

    while(root->left != NULL)
        root = root->left;
    return root;
}

int Height(Node *p)
{
    if (p == NULL)
        return 0;
    int x = Height(p->left);
    int y = Height(p->right);

    return (x>y ? x+1 : y+1);
}

Node *deleteNode(Node *root, int x) {

    // BASE CASE
    if(root->left == NULL && root->right == NULL){
        delete root;
        return NULL;
    }

    if(x < root->data)
        root->left = deleteNode(root->left, x);

    else if(x > root->data)
        root->right = deleteNode(root->right, x);

    else
    {
        if(Height(root->left) > Height(root->right)){
            Node* pred = predecessor(root->left);
            root->data = pred->data;
            root->left = deleteNode(root->left, pred->data);
        }
        else{
            Node* succ = successor(root->right);
            root->data = succ->data;
            root->right = deleteNode(root->right, succ->data);
        }
    }

    return root;
}



int main()
{
    Node* root = NULL;
    takeInput(root);

    levelOrderTraversal(root);

    return 0;
}
