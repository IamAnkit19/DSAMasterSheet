#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void nextPermutation(vector<int>& arr) {
        // code here
        int n = arr.size();
        for(int i=n-2; i>=0; i--){
            if(arr[i] < arr[i+1]){
                int j = n-1;
                while(arr[j] <= arr[i]){
                    j--;
                }
                swap(arr[i], arr[j]);
                reverse(arr.begin() + i + 1, arr.end());
                return;
            }
        }
        reverse(arr.begin(), arr.end());
    }
};