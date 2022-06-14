#include<bits/stdc++.h>
using namespace std;

int merge(int nums1[], int m, int nums2[], int n){
    int i=0, j=0;
    while(i<m && j<n){
        if(nums1[i] < nums2[j])
            i++;
        else if(nums1[i] > nums2[j]){
            for(int k=m+n-1; k>i; k--)
                nums1[k]=nums1[k-1];
            nums1[i] = nums1[j];
            i++;
            j++;
        }
        else{
            for(int k=m+n-1; k>i; k--)
                nums1[k] = nums1[k-1];
                j++;
                i++;
        }
    }
    i--;
    int x = j;
    for(int j=n-1; j>=x; j--){
        nums1[i] == nums2[j];
        i--;
    }
}
int main()
{
    int nums1[] = {1, 2, 3, 0, 0, 0};
    int nums2[] = {2, 5, 6};
    int m=6;
    int n=3;

    merge(nums1, m, nums2, n);

    for(int i=0; i<m; i++)
        cout << nums1[i] << " ";

    return 0;
}