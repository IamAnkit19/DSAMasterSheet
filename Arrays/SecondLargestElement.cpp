#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int getSecondLargest(vector<int> &arr) {
        // code here
        int n = arr.size();
        if(n == 1){
            return -1;
        }
        int largest = -1;
        int secondLargest = -1;
        for(int i=0; i<n; i++){
            if(arr[i] > largest){
                secondLargest = largest;
                largest = arr[i];
            }
            else if(arr[i] > secondLargest && arr[i] < largest){
                secondLargest = arr[i];
            }
        }
        if(largest == secondLargest){
            return -1;
        }
        return secondLargest;
    }
};