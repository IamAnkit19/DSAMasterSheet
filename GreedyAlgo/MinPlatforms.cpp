#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int minPlatform(vector<int>& arr, vector<int>& dep) {
        // code here
        int n = arr.size();
        sort(arr.begin(), arr.end());
        sort(dep.begin(), dep.end());
        int maxCount = 0, currCount = 0;
        int l = 0, h = 0;
        while(l < n){
            if(arr[l] <= dep[h]){
                l++;
                currCount++;
            }
            else{
                h++;
                currCount--;
            }
            maxCount = max(maxCount, currCount);
        }
        return maxCount;
    }
};