// A sorted array of distinct integers shiftArr is shifted to the left by an unknown offset and you don’t have a pre-shifted copy of it. For instance, the sequence 1, 2, 3, 4, 5 becomes 3, 4, 5, 1, 2, after shifting it twice to the left.
// Given shiftArr and an integer num, implement a function shiftedArrSearch that finds and returns the index of num in shiftArr. If num isn’t in shiftArr, return -1. Assume that the offset can be any value between 0 and arr.length - 1.

#include<bits/stdc++.h>
using namespace std;

int find_index(vector<int> arr, int num){
 for(int i=0; i<arr.size(); i++){
   if(arr[i] == num)
    return i;
 }
  return -1;  // means element not present in array
}

int shiftedArrSearch(vector<int>& shiftArr, int num )
{
  int index = find_index(shiftArr, num);
  if(index == -1){
      cout << "Element does not Exist" << endl;
      return -1;
  }
  int n = index;
  // Now we have to shift array "index" Times
  while(index!=0){
    int temp = shiftArr[0];
    shiftArr.erase(shiftArr.begin() + 0);
    shiftArr.push_back(temp);
    index--;
  }
  return n;
}

int main() {
  vector<int> shiftArr;
  shiftArr.push_back(9);
  shiftArr.push_back(12);
  shiftArr.push_back(17);
  shiftArr.push_back(2);
  shiftArr.push_back(4);
  shiftArr.push_back(5);

  cout << "Before Shifting : ";
  for(auto i: shiftArr)
      cout << i << " ";
  cout << endl;


  int num=2;
  int n = shiftedArrSearch(shiftArr, num);
  cout << n << endl;

  cout << "After Shifting : ";
  for(auto i: shiftArr)
      cout << i << " ";
  cout << endl;

  return 0;
}