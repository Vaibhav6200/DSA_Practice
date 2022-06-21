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

// Logic To Count ALL NODES
int countTotalNodes(node* root) {
    if(root == NULL)
        return 0;
    int x = countTotalNodes(root->left);
    int y = countTotalNodes(root->right);

    return x+y+1;
}


// Logic To Count ALL LEAF NODES
void recursive_count(node* root, int &count){
    if(root == NULL)
        return;

    if(root->left == NULL && root->right == NULL)
        count++;
    recursive_count(root->left, count);
    recursive_count(root->right, count);
}

int countLeaves(node* root)
{
        int count=0;
        recursive_count(root, count);
        return count;
}


int main()
{

    return 0;
}