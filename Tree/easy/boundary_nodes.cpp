#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;
    node(int val)
    {
        data = val;
        left = right = NULL;
    }
};

node *buildTree(node *root)
{
    int data;
    cout << "Enter Data : ";
    cin >> data;
    root = new node(data);

    if (data == -1)
        return NULL;

    cout << "Enter data to insert at left of " << data << endl;
    root->left = buildTree(root->left);

    cout << "Enter data to insert at right of " << data << endl;
    root->right = buildTree(root->right);

    return root;
}
void printLeftnodes(node *root, vector<int> &left)
{
    if ((root == NULL) || (root->left == NULL && root->right == NULL))
        return;

    // If root is not a leaf node then print its data
    left.push_back(root->data);

    if (root->left)
        printLeftnodes(root->left, left);
    else
        printLeftnodes(root->right, left);
}

void printLeafnodes(node *root, vector<int> &leaf)
{
    if (root == NULL)
        return;

    if (root->left == NULL && root->right == NULL)
        leaf.push_back(root->data);

    if (root->left)
        printLeafnodes(root->left, leaf);
    if (root->right)
        printLeafnodes(root->right, leaf);
}

void printRightnodes(node *root, vector<int> &right)
{
    if ((root == NULL) || (root->left == NULL && root->right == NULL))
        return;

    if (root->right)
        printRightnodes(root->right, right);
    else
        printRightnodes(root->left, right);

    // If root is not a leaf node then print its data
    right.push_back(root->data);
}

vector<int> boundary(node *root)
{
    vector<int> result;
    if (root == NULL)
        return result;

    result.push_back(root->data);

    // Traversing left Subtree
    if (root->left)
        printLeftnodes(root->left, result);

    // Traversing all Leaf nodes
    printLeafnodes(root->left, result);
    printLeafnodes(root->right, result);

    // Traversing right Subtree
    if (root->right)
        printRightnodes(root->right, result);

    return result;
}

int main()
{
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    node *root = NULL;
    root = buildTree(root);

    return 0;
}