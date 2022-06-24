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

Node* predecessor(Node* pred, Node* curr){
    if(pred == NULL)
        return NULL;
    while(pred->right!=NULL && pred->right != curr)
        pred = pred->right;
    return pred;
}

//     Using Morris Traversal
void inOrder(Node* root, vector<int> &arr){
    Node* curr = root;
    while(curr != NULL)
    {
        // If curr left does not exist then visit node and move to right
        if(curr->left == NULL){
            arr.push_back(curr->data);
            curr = curr->right;
        }
        else{
            Node* pred = predecessor(curr->left, curr);
            if(pred->right == NULL){
                pred->right = curr;
                curr = curr->left;
            }
            else{
                pred->right = NULL;
                arr.push_back(curr->data);
                curr = curr->right;
            }
        }
    }
}

vector<int> merge(vector<int> arr1, vector<int> arr2){
    int n1 = arr1.size();
    int n2 = arr2.size();

    vector<int> result(n1+n2);
    int i=0, j=0, k=0;
    while(i<n1 && j<n2){
        if(arr1[i] == arr2[j]){
            result[k++] = arr1[i++];
            result[k++] = arr2[j++];
        }
        else if(arr1[i] < arr2[j])
            result[k++] = arr1[i++];
        else
            result[k++] = arr2[j++];
    }
    while(i<n1)
        result[k++] = arr1[i++];

    while(j<n2)
        result[k++] = arr2[j++];

    return result;
}

Node* makeTreeFromInorder(vector<int> arr, int start, int end){
    if(start == end)
        return new Node(arr[start]);

    int mid = (start+end)/2;
    Node* root = new Node(arr[mid]);

//     make left subtree using recursion
    root->left = makeTreeFromInorder(arr, start, mid-1);
    root->right = makeTreeFromInorder(arr, mid+1, end);

    return root;
}

Node* mergeTrees(Node* root1, Node* root2) {
//        Step1: Finding inorder arrays of tree1 and tree2
    vector<int> arr1;
    vector<int> arr2;
    inOrder(root1, arr1);
    inOrder(root2, arr2);

//        Step2: merging those arrays
    vector<int> result = merge(arr1, arr2);

//        Step3: creating BST from merged array (sorted array / inorder of resultant BST)
    int start = 0;
    int end = result.size() - 1;
    Node* ans = makeTreeFromInorder(result, start, end);

    return ans;
}