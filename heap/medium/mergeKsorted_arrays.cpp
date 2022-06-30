#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    int i;
    int j;
    Node(int val, int row, int col){
        data = val;
        i = row;
        j = col;
    }
};

class compare{
    public:
    bool operator()(Node* a, Node* b){
        return a->data > b->data;
    }
};

vector<int> mergeKArrays(vector<vector<int>> arr, int K)
{
    vector<int> result;

    // Step1: Create our Min Heap
    priority_queue<Node*, vector<Node*>, compare> minHeap;

    // Step2: Push all 0th column elements in our min Heap
    int rows = arr.size();
    for(int i=0; i<rows; i++){
        Node* temp = new Node(arr[i][0], i, 0);
        minHeap.push(temp);
    }

    // Ste3: Now While our Min Heap does not become empty pop its first element an push it int our resultant vector
    while(!minHeap.empty()){
        Node* temp = minHeap.top();  minHeap.pop();
        int i = temp->i;
        int j = temp->j;

        result.push_back(temp->data);

        if(j+1 < arr[i].size()){
            Node* node = new Node(arr[i][j+1], i, j+1);
            minHeap.push(node);
        }
    }


    return result;
}