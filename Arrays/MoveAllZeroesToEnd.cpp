#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void pushZerosToEnd(vector<int>& arr) {
        // code here
        int n = arr.size();
        int idx = 0;
        for(int i=0; i<n; i++){
            if(arr[i] != 0){
                arr[idx++] = arr[i];
            }
        }
        while(idx < n){
            arr[idx++] = 0;
        }
    }
};