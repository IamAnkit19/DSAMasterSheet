#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> findUnion(vector<int> &a, vector<int> &b) {
        // code here
        vector<int> ans;
        int m = a.size();
        int n = b.size();
        int i = 0, j = 0, idx = -1;
        while(i < m && j < n){
            if(a[i] < b[j]){
                if(idx == -1 || a[i] != ans[idx]){
                    ans.push_back(a[i]);
                    idx++;
                }
                i++;
            }
            else if(a[i] == b[j]){
                if(idx == -1 || a[i] != ans[idx]){
                    ans.push_back(a[i]);
                    idx++;
                }
                i++;
                j++;
            }
            else{
                if(idx == -1 || b[j] != ans[idx]){
                    ans.push_back(b[j]);
                    idx++;
                }
                j++;
            }
        }
        while(i < m){
            if(idx == -1 || a[i] != ans[idx]){
                ans.push_back(a[i]);
                idx++;
            }
            i++;
        }
        while(j < n){
            if(idx == -1 || b[j] != ans[idx]){
                ans.push_back(b[j]);
                idx++;
            }
            j++;
        }
        return ans;
    }
};