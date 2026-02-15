#include<bits/stdc++.h>
using namespace std;

class Solution {
    bool isPossible(vector<int> &arr, int mid, int k){
        int stuCount = 1;
        int pages = arr[0];
        for(int i=1; i<arr.size(); i++){
            if(pages + arr[i] <= mid){
                pages += arr[i];
            }
            else{
                pages = arr[i];
                stuCount++;
            }
            if(stuCount > k){
                return false;
            }
        }
        return stuCount <= k;
    }
  public:
    int findPages(vector<int> &arr, int k) {
        // code here
        int l = 0, h = 0;
        if(arr.size() < k){
            return -1;
        }
        for(int val : arr){
            l = max(l, val);
            h += val;
        }
        while(l <= h){
            int mid = (l + h) / 2;
            if(isPossible(arr, mid, k)){
                h = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }
        return l;
    }
};