#include<bits/stdc++.h>
using namespace std;

// This question is for checking maxheap. Changing some condition can make it check for minheap as asked in sheet.
class Solution {
  public:
    bool isMaxHeap(int arr[], int n) {
        // Your code goes here
        for(int i=0; i<n; i++){
            int left = 2 * i + 1;
            int right = 2 * i + 2;
            if((left < n && arr[i] < arr[left]) || (right < n && arr[i] < arr[right])){
                return false;
            }
        }
        return true;
    }
};