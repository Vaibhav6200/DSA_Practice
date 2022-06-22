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

vector <int> zigZagTraversal(node* root)
{
    queue<node*> q;
    q.push(root);
    bool LeftToRight = true;
    vector<int> result;

    while(!q.empty()){
        int size = q.size();
        vector<int> temp(size);

        for(int i=0; i<size; i++){
            node* frontNode = q.front();
            q.pop();

            int index = LeftToRight ? i : size-i-1;
            temp[index] = frontNode->data;

            if(frontNode->left)
                q.push(frontNode->left);
            if(frontNode->right)
                q.push(frontNode->right);
        }

        // Changing direction
        LeftToRight = !LeftToRight;

        for(int i=0; i<temp.size(); i++)
            result.push_back(temp[i]);
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