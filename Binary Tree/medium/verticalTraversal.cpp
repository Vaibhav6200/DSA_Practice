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

void preOrder(node* root){
    if(root == NULL)
       return;
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}


// My Approach
vector<int> verticalOrder(node *root)
{
    vector<int> result;
    if (root == NULL)
        return result;

    map<int, vector<int>> map;
    queue<pair<node *, int>> q;     // {Node, HorizontalDistance}

    // Queue Initiallization
    q.push({root, 0}); // initially Horizontal Distance == 0 and Level == 0    {consider levels start from zero}

    while (!q.empty()){

        // Fetch Front Element from Queue
        pair<node *, int> temp = q.front();
        q.pop();

        node *frontnode = temp.first;
        int hd = temp.second;

        // Do mapping of Fetched Element
        map[hd].push_back(frontnode->data);

        // Push Left node and right node(if exist) for level order traversal
        if (frontnode->left)
            q.push({frontnode->left, hd - 1});
        if (frontnode->right)
            q.push({frontnode->right, hd + 1});
    }

    for (auto i : map){
        for (auto j : i.second){
            result.push_back(j);
        }
    }
    return result;
}

// Mentor Approach
vector<int> verticalOrder(node *root)
{
    vector<int> result;
    if (root == NULL)
        return result;

    map<int, map<int, vector<int>>> map;
    queue<pair<node *, pair<int, int>>> q;

    // Queue Initiallization
    q.push({root, {0, 0}}); // initially Horizontal Distance == 0 and Level == 0    {consider levels start from zero}

    while (!q.empty()){

        // Fetch Front Element from Queue
        pair<node *, pair<int, int>> temp = q.front();
        q.pop();

        node *frontnode = temp.first;
        int hd = temp.second.first;
        int level = temp.second.second;

        // Do mapping of Fetched Element
        map[hd][level].push_back(frontnode->data);

        // Push Left node and right node(if exist) for level order traversal
        if (frontnode->left)
            q.push({frontnode->left, {hd - 1, level + 1}});
        if (frontnode->right)
            q.push({frontnode->right, {hd + 1, level + 1}});
    }

    for (auto i : map){
        for (auto j : i.second){
            for (auto k : j.second)
                result.push_back(k);
        }
    }
    return result;
}

int main()
{
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1
    node* root = NULL;
    root = buildTree(root);

    return 0;
}

