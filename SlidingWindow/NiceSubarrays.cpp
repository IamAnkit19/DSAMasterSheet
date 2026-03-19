#include<bits/stdc++.h>
using namespace std;

class Solution {
    int solve(vector<int> &nums, int k){
        if(k < 0){
            return 0;
        }
        int n = nums.size(), sum = 0, count = 0, l = 0, r = 0;
        while(r < n){
            sum += (nums[r] % 2);
            while(sum > k){
                sum -= (nums[l] % 2);
                l++;
            }
            count += (r - l + 1);
            r++;
        }
        return count;
    }
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        return solve(nums, k) - solve(nums, k-1);
    }
};