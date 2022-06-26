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

    void print(){
        for(int i=1; i<=size; i++)
            cout << arr[i] << " ";
        cout << endl;
    }

};

int main()
{
    heap h;

    h.insert(50);
    h.insert(55);
    h.insert(53);
    h.insert(52);
    h.insert(54);

    h.print();

    return 0;
}