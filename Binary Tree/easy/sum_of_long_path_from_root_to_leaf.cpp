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

pair<int , int> solve(node* root, int sum){
    if(root == NULL)
        return {0, 0};

    pair<int, int> x = solve(root->left, sum);
    pair<int, int> y = solve(root->right, sum);

    int left = x.first;     // indicates left subtree height
    int leftSum = x.second;

    int right = y.first;    // indicates right subtree height
    int rightSum = y.second;

    if(left > right)
        return { left+1, leftSum + root->data};
    else
        return { right+1, rightSum + root->data};
}

int sumOfLongRootToLeafPath(node *root){
    int sum=0;
    pair<int, int> temp = solve(root, sum);
    return temp.second;
}

int main()
{
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    node* root = NULL;
    root = buildTree(root);

    return 0;
}
