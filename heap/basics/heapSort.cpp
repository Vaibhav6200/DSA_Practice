#include<bits/stdc++.h>
using namespace std;

class heap{
public:
    int arr[100];
    int size;

    heap(){
        size = 0;
        arr[0] = -1;
    }

    void swap(int *x, int *y){
        int temp = *x;
        *x = *y;
        *y = temp;
    }

    void insert(int val)
    {
        size = size + 1;
        int index = size;
        arr[index] = val;

        while(index > 1)       // while parent is smaller than ith node swap parent and ith node
        {
            int parent = index/2;
            if(arr[parent] < arr[index])
            {
                swap(&arr[index/2], &arr[index]);
                index = parent;
            }
            else             // means root node inserted
                return;
        }
    }

// NOTE: we can only delete root node in a Heap
    void deletion(){
        if(size == 0){
            cout << "Nothing to delete \n";
            return;
        }

        // Step1: Exchange root with last element and Decrement size
        arr[1] = arr[size];
        size--;

        // Step2: take our element to its correct position
        int i = 1;
        int child = 2*i;
        while(child < size)
        {
            if(arr[child+1] > arr[child])       // checking our of left and right child which is greater
                child++;

            if(arr[i] < arr[child]){
                swap(&arr[i], &arr[child]);
                i=child;
                child = 2*i;
            }
            else
                break;
        }
    }

/*
    When we are deleting elements from our heap and placing deleted elements at vacant spaces
    we are getting array in sorted order
*/
    void heapSort(int n){

        int x = arr[1];     // extracting our root element (which will be deleted)
        arr[1] = arr[n];

        int i = 1;
        int child = 2*i;
        while(child < n-1)
        {
            if(arr[child+1] > arr[child])       // checking our of left and right child which is greater
                child++;

            if(arr[i] < arr[child]){
                swap(&arr[i], &arr[child]);
                i=child;
                child = 2*i;
            }
            else
                break;
        }
        arr[n] = x;
    }


    void print(){
        for(int i=1; i<=size; i++)
            cout << arr[i] << " ";
        cout << endl;
    }
};



int main()
{
    heap h;

    h.insert(30);
    h.insert(20);
    h.insert(15);
    h.insert(5);
    h.insert(10);
    h.insert(12);
    h.insert(6);

    cout << "Before Sorting : ";
    h.print();

    for(int i=h.size; i>=1; i--){
        h.heapSort(i);
    }

    cout << "After Sorting : ";
    h.print();

    return 0;
}