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



// METHOD 2: { TIME - O(n) }
pair<int, int> diameterFast(node* root){
    if(root == NULL){
        pair<int, int> p = {0, 0};
        return p;
    }
    pair<int, int> left = diameterFast(root->left);
    pair<int, int> right = diameterFast(root->right);

    int op1 = left.first;
    int op2 = right.first;
    int op3 = left.second + right.second + 1;

    pair<int, int> ans;
    ans.first = max(op1, max(op2, op3));
    ans.second = max(left.second, right.second) + 1;

    return ans;
}

//     Method 2: Time - O(n)
int diameterOfBinaryTree(node* root) {
    return diameterFast(root).first - 1;
}


// METHOD 1: { Time - O(n^2) }
// int Height(node* root){
//     if(root == NULL)
//         return 0;
//     int x = Height(root->left);
//     int y = Height(root->right);
//     return (x>y ? x+1 : y+1);
// }

// int maxDiameter(node* root, int currMax){
//     if(root==NULL)
//         return 0;

//     int x = Height(root->left);
//     int y = Height(root->right);

//     int temp = x + y + 1;

//     // find max diameter of left subtree
//     int dia1 = maxDiameter(root->left, currMax);

//     // find max diameter of right subtree
//     int dia2 = maxDiameter(root->right, currMax);

//     currMax = max(temp, max(dia1, dia2));

//     return currMax;
// }


int main()
{
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    node* root = NULL;
    root = buildTree(root);

    return 0;
}