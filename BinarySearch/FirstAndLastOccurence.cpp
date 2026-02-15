#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> find(vector<int>& arr, int x) {
        // code here
        int n = arr.size();
        int l = 0, h = n-1;
        vector<int> ans = {-1, -1};
        while(l <= h){
            int mid = (l + h) / 2;
            if(arr[mid] == x){
                int idx = mid - 1;
                while(idx >= 0 && arr[idx] == x){
                    idx--;
                }
                ans[0] = idx + 1;
                idx = mid + 1;
                while(idx <= n && arr[idx] == x){
                    idx++;
                }
                ans[1] = idx - 1;
                return ans;
            }
            else if(arr[mid] < x){
                l = mid + 1;
            }
            else{
                h = mid - 1;
            }
        }
        return ans;
    }
};