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

Node* buildTree(Node* root){
    int data;
    cout << "Enter Data : " << endl;
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


void levelOrderTraversal(Node* root){
    if(root == NULL)
        return;

    queue<Node*> q;
    q.push(root);

    while(!q.empty())
    {
        int size = q.size();
        while(size > 0){
            Node* temp = q.front();
            q.pop();

            cout << temp->data << " ";

            if(temp->left)
                q.push(temp->left);
            if(temp->right)
                q.push(temp->right);
            size--;
        }
        cout << endl;
    }
    return;
}


// void levelOrderTraversal(Node* root){
//     queue<Node*> q;
//     q.push(root);
//     q.push(NULL);

//     while(!q.empty()){
//         Node* temp = q.front();
//         q.pop();

//         // LOGIC for seperating different levels of a tree
//         if(temp == NULL){
//             cout << endl;
//             if(!q.empty())
//                 q.push(NULL);
//         }
//         else{
//             cout << temp->data << " ";
//             if(temp->left != NULL)
//                 q.push(temp->left);

//             if(temp->right)
//                 q.push(temp->right);
//         }
//     }
// }

// void reverse_levelOrderTraversal(Node* root){
//     queue<Node*> q;
//     q.push(root);
//     q.push(NULL);

//     while(!q.empty()){
//         Node* temp = q.front();
//         q.pop();

//         if(temp == NULL){
//             cout << endl;
//             if(!q.empty())
//                 q.push(NULL);
//         }
//         else{
//             cout << temp->data << " ";
//             if(temp->right)
//                 q.push(temp->right);

//             if(temp->left)
//                 q.push(temp->left);
//         }
//     }
// }

int main()
{
    Node* root = NULL;
    root = buildTree(root);

    levelOrderTraversal(root);

    // cout << endl;
    // reverse_levelOrderTraversal(root);


// 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    return 0;
}