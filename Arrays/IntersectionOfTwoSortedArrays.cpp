#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> intersection(vector<int> &arr1, vector<int> &arr2) {
        // code here
        vector<int> ans;
        int m = arr1.size();
        int n = arr2.size();
        int i = 0, j = 0, idx = -1;
        while(i < m && j < n){
            if(arr1[i] == arr2[j] && (idx == -1 || ans[idx] != arr1[i])){
                ans.push_back(arr1[i]);
                i++;
                j++;
                idx++;
            }
            else if(arr1[i] < arr2[j]){
                i++;
            }
            else{
                j++;
            }
        }
        return ans;
    }
};