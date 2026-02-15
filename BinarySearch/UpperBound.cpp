#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int lowerBound(vector<int>& arr, int target) {
        // code here
        int n = arr.size();
        int l = 0, h = n-1;
        while(l <= h){
            int mid = (l + h) / 2;
            if(arr[mid] <= target){
                l = mid + 1;
            }
            else{
                h = mid - 1;
            }
        }
        return h+1;
    }
};