#include<bits/stdc++.h>
using namespace std;

class Solution {
    long long totalHours(vector<int> &piles, int mid){
        long long ans = 0;
        for(int val : piles){
            ans += (val + mid -1) / mid;
        }
        return ans;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int maxNum = INT_MIN;
        for(int val : piles){
            maxNum = max(maxNum, val);
        }
        int low = 1, high = maxNum;
        while(low <= high){
            int mid = (low + high) / 2;
            long long x = totalHours(piles, mid);
            if(x <= h){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return low;
    }
};