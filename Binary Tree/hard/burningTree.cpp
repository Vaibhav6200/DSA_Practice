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

node* buildTree_levelOrderTraversal(node* root){
    int data;
    cout << "Enter root node data: ";
    cin >> data;
    root = new node(data);

    queue<node*> q;
    q.push(root);

    while(!q.empty()){
        node* temp = q.front();
        q.pop();

        cout << "Enter Left Child of " << temp->data << " : ";
        cin >> data;
        if(data != -1){
            temp->left = new node(data);
            q.push(temp->left);
        }

        cout << "Enter Right Child of " << temp->data << " : ";
        cin >> data;
        if(data != -1){
            temp->right = new node(data);
            q.push(temp->right);
        }
    }
    return root;
}



void createMapping(node* root, map<node*, node*> &nodeToParent){

    // BASE CASE
    if(root == NULL)
        return;

    queue<node*> q;

    // Queue Initialization with root node and its parent
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        node* temp = q.front();
        q.pop();

        nodeToParent[temp] = q.front();      // mapping root node with its parent;
        q.pop();        // pop parent element

        if(temp->left){
            q.push(temp->left);     // pushing left child and its parent
            q.push(temp);
        }
        if(temp->right){
            q.push(temp->right);
            q.push(temp);
        }
    }
}

node* findTargetnode(node* root, int target){
    if(root == NULL)
        return NULL;

    if(root->data == target)
        return root;

    node* leftAns = findTargetnode(root->left, target);
    node* rightAns = findTargetnode(root->right, target);

    if(leftAns!=NULL)
        return leftAns;

    if(rightAns!=NULL)
        return rightAns;

    return NULL;
}


int BurnTree(node* root, map<node*, node*> &nodeToParent, node* target){
    int count=0;

    queue<node*> q;
    q.push(target);

    map<node*, bool> visited;
    visited[root] = true;


    while(!q.empty()){
        node* temp = q.front();
        q.pop();

        bool flag = false;

        if(temp->left && visited[temp->left] == false){
            visited[temp->left] = true;
            q.push(temp->left);
            flag = true;
        }

        if(temp->right && visited[temp->right] == false){
            visited[temp->right] = true;
            q.push(temp->right);
            flag = true;
        }

        node* parent = nodeToParent[temp];
        if(parent && visited[parent] == false){
            visited[parent] = true;
            q.push(parent);
            flag = true;
        }

        if(flag == true)
            count++;
    }

    return count;
}

int minTime(node* root, int target)
{
    map<node*, node*> nodeToParent;
    createMapping(root, nodeToParent);

    node* targetnode = findTargetnode(root, target);

    int t = BurnTree(root, nodeToParent, targetnode);

    return -1;
}


int main()
{
    // 1 2 3 4 5 -1 6 -1 -1 7 8 -1 9 10 11 -1 -1 -1 12 -1 -1 -1 13
    node* root = NULL;
    root = buildTree_levelOrderTraversal(root);
    int target = 8;

    cout << minTime(root, target) << endl;

    return 0;
}