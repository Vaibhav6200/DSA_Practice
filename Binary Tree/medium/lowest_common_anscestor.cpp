
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

node* lca(node* root ,int n1 ,int n2 )
{
    if(root == NULL)
        return NULL;

    if(root->data == n1)
        return root;
    else if(root->data == n2)
        return root;

    node* leftAns = lca(root->left, n1, n2);
    node* rightAns = lca(root->right, n1, n2);

    if(leftAns == NULL && rightAns == NULL)
        return NULL;

    if(leftAns != NULL && rightAns == NULL)
        return leftAns;

    if(rightAns == NULL && rightAns != NULL)
        return rightAns;

    if(leftAns != NULL && rightAns != NULL)
        return root;
}

int main()
{
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    node* root = NULL;
    root = buildTree(root);

    return 0;
}
