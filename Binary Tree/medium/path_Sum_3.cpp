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



int main()
{
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    // Node* root = NULL;
    // root = buildTree(root);

    int arr[] = {10, 5, 3, -2};
    int n = 4;
    int sum=0;
    int target = 8;

    for(int i=n-1; i>=0; i--){
        sum += arr[i];
        if(sum == target)
            cout << "yess";
    }

    return 0;
}