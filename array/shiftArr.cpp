// A sorted array of distinct integers shiftArr is shifted to the left by an unknown offset and you don’t have a pre-shifted copy of it. For instance, the sequence 1, 2, 3, 4, 5 becomes 3, 4, 5, 1, 2, after shifting it twice to the left.
// Given shiftArr and an integer num, implement a function shiftedArrSearch that finds and returns the index of num in shiftArr. If num isn’t in shiftArr, return -1. Assume that the offset can be any value between 0 and arr.length - 1.
#include <iostream>
#include <vector>

using namespace std;


/*
[9, 12, 17, 2, 4, 5]
 l      m         h
l = 0
m = (l+h)/2
h = n-1

if(arr[m] == num)
return m;

search(arr, l, m, num);
search(arr, m+1, h, num);

num = 7

20  30  40  50  60  5  7  10
l            m            h
                 l  m     r

17 2 4 5 9 12
l    m      h
l  m r

*/

int search(vector<int>& arr, int l, int h, int num) {
  if(arr[l] == num)
    return l;
  if(arr[h] == num)
    return h;
  if(arr[l]>num || arr[h]<num)
    return -1;

  int m = (l+h)/2;
  if(search(arr, l, m, num) == -1)
    return search(arr, m+1, h, num);
  return search(arr, l, m, num);
}

int shiftedArrSearch( const vector<int>& shiftedArr, int num )
{
  // your code goes here
  vector<int> arr = shiftedArr;
  int n = arr.size();
  int l=0, h=n-1;
  int m = l + (h-l)/2;

  if(search(arr, l, m, num) == -1)
    return search(arr, m+1, h, num);
  return search(arr, l, m, num);
}

int main() {
  return 0;
}