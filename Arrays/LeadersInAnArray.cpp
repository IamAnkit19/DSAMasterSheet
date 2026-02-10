#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> leaders(vector<int>& arr) {
        // code here
        vector<int> ans;
        int n = arr.size();
        int currMax = arr[n-1];
        ans.push_back(currMax);
        for(int i=n-2; i>=0; i--){
            if(arr[i] >= currMax){
                currMax = arr[i];
                ans.push_back(currMax);
            }
        }
        int l = 0, r = ans.size()-1;
        while(l < r){
            int temp = ans[l];
            ans[l] = ans[r];
            ans[r] = temp;
            l++;
            r--;
        }
        return ans;
    }
};