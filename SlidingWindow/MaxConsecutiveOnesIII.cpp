#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size(), zeroes = 0, l = 0, r = 0, maxLength = 0;
        while(r < n){
            if(nums[r] == 0){
                if(zeroes == k){
                    while(nums[l] != 0){
                        l++;
                    }
                    l++;
                }
                else{
                    zeroes++;
                }
            }
            maxLength = max(maxLength, r-l+1);
            r++;
        }
        return maxLength;
    }
};