#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int largest(vector<int> &arr) {
        // code here
        int largestElement = arr[0];
        for(int i=1; i<arr.size(); i++){
            if(arr[i] > largestElement){
                largestElement = arr[i];
            }
        }
        return largestElement;
    }
};