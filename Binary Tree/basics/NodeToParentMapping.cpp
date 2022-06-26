#include<bits/stdc++.h>
using namespace std;


class Node{
public:
    int data;
    Node* left;
    Node* right;
    Node(int data){
        data = data;
        left = right = NULL;
    }
};


Node* buildTree(Node* root){
    int data;
    cout << "Enter Data : ";
    cin >> data;
    root = new Node(data);

    if(data == -1)
        return NULL;

    cout << "Enter data to insert at left of " << data << endl;
    root->left = buildTree(root->left);

    cout << "Enter data to insert at right of " << data << endl;
    root->right = buildTree(root->right);

    return root;
}


void parentMapping(Node* root, Node* prev, map<Node*, Node*> &NodeToParent){
    if(root == NULL)
        return;

    NodeToParent[root] = prev;
    prev = root;

    parentMapping(root->left, prev, NodeToParent);
    parentMapping(root->right, prev, NodeToParent);
}



int main()
{
//         Get Parent Mapping
        Node* root = NULL;
        root = buildTree(root);

        Node* prev = NULL;
        map<Node*, Node*> NodeToParent;
        parentMapping(root, prev, NodeToParent);

        for(auto i: NodeToParent){
            if(i.second != NULL)
            cout << i.first->data << " : " << i.second->data << endl;
            else
                cout << i.first->data << " : NULL" << endl;
        }

    return 0;
}