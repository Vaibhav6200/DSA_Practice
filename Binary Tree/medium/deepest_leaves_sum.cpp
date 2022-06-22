#include<bits/stdc++.h>
using namespace std;


class node{
public:
    int data;
    node* left;
    node* right;
    node(int data){
        data = data;
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

int maxDepth(node* root) {
    if(root == NULL)
        return 0;

    int x = maxDepth(root->left);
    int y = maxDepth(root->right);
    return (x>y ? x+1 : y+1);
}

void deepSum(node* root, int &sum, int height){
    if(root == NULL)
        return;
    deepSum(root->left, sum, height-1);
    deepSum(root->right, sum, height-1);

    int newHeight = maxDepth(root);
    if(root->left == NULL && root->right == NULL && newHeight == height)
        sum += root->data;
}
int deepestLeavesSum(node* root) {
    int sum=0;
    int maxHeight = maxDepth(root);
    deepSum(root, sum, maxHeight);
    return sum;
}

int main()
{
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    node* root = NULL;
    root = buildTree(root);

    return 0;
}
