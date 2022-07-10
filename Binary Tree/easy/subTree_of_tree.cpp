#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int data)
    {
        data = data;
        left = right = NULL;
    }
};


/*
    Here trick is how to run recursion to match root and subroot
    whenever you want to do a match of nodes then try to do a traversal over tree and for each node check if it match or not
    because in these cases recursion wont work for this case
    root = [1, NULL, 1, NULL, 1, NULL, 1, NULL, 1, NULL, 1, NULL, 1, NULL, 1, NULL, 1, 2]
    subRoot = [1, NULL, 1, NULL, 1, NULL, 1, 2]
    so whenever recursion don't work try to do some kind of traversal
*/


/*
    *** APPROACH ***
1. Answer can be found on left subtree or right subtree or it may root
2. do inorder traversal over main tree and for every Node check whether its subtree or not
*/

// returns true if both trees match
bool match(Node* root1, Node* root2){
    if(root1 == NULL && root2 == NULL)
        return true;

    // if current Node dataues match then match left subtrees
    if(root1 != NULL && root2 != NULL){
        bool flag1 = match(root1->left, root2->left);
        bool flag2 = match(root1->right, root2->right);

        if(flag1 && flag2 && (root1->data == root2->data))
            return true;
        return false;
    }

    return false;
}

void inorder(Node* root, Node* subRoot, bool &ans){
    if(root == NULL)
        return;

    if(root->left)
        inorder(root->left, subRoot, ans);

    if(match(root, subRoot))
        ans = true;

    if(root->right)
        inorder(root->right, subRoot, ans);
}

bool isSubtree(Node* root, Node* subRoot) {
    int key = subRoot->data;
    bool ans = false;
    inorder(root, subRoot, ans);

    return ans;
}

int main()
{


    return 0;
}