#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    // I
    int singleNumber(vector<int>& nums) {
        int x = 0;
        for(int val : nums){
            x ^= val;
        }
        return x;
    }
    // II
    int singleNumberII(vector<int>& nums) {
        int ones = 0, twos = 0;
        for(int i=0; i<nums.size(); i++){
            ones = (ones ^ nums[i]) & ~twos;
            twos = (twos ^ nums[i]) & ~ones;
        }
        return ones;
    }
    // III
    vector<int> singleNumberIII(vector<int>& nums) {
        long long x = 0;
        for(int val : nums){
            x ^= val;
        }
        // long long rightMost = (x & x-1) & x;
        long long rightMost = x & -x;
        int b1 = 0, b2 = 0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] & rightMost){
                b1 ^= nums[i];
            }
            else{
                b2 ^= nums[i];
            }
        }
        return {b1, b2};
    }
};