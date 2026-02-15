#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> getFloorAndCeil(int x, vector<int> &arr) {
        // code here
        vector<int> ans = {-1, INT_MAX};
        for(int i=0; i<arr.size(); i++){
            if(arr[i] <= x && arr[i] > ans[0]){
                ans[0] = arr[i];
            }
            if(arr[i] >= x && arr[i] < ans[1]){
                ans[1] = arr[i];
            }
        }
        if(ans[1] == INT_MAX){
            return {ans[0], -1};
        }
        return ans;
    }
};