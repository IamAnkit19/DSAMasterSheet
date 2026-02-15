#include<bits/stdc++.h>
using namespace std;

class Solution {
    long long solve(vector<int> &arr, long long mid, int k){
        int count = 0;
        long long ans = 0;
        for(int i=0; i<arr.size(); i++){
            if(arr[i] <= mid){
                count++;
            }
            else{
                ans += (count / k);
                count = 0;
            }
        }
        ans += (count / k);
        return ans;
    }
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        if((1LL*m)*(1LL*k) > n){
            return -1;
        }
        int l = INT_MAX;
        int h = INT_MIN;
        for(int val : bloomDay){
            h = max(h, val);
            l = min(l, val);
        }
        while(l <= h){
            long long mid = (l + h) / 2;
            long long x = solve(bloomDay, mid, k);
            if(x < m){
                l = mid + 1;
            }
            else{
                h = mid - 1;
            }
        }
        return l;
    }
};