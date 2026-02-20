#include<bits/stdc++.h>
using namespace std;

class Solution {
    int divideArray(vector<int> &nums, int mid){
        int count = 1;
        int sum = 0;
        for(int i=0; i<nums.size(); i++){
            if(sum+nums[i] > mid){
                count++;
                sum = nums[i];
            }
            else{
                sum += nums[i];
            }
        }
        return count;
    }
public:
    int splitArray(vector<int>& nums, int k) {
        int low = 0, high = 0;
        for(int val : nums){
            low = max(low, val);
            high += val;
        }
        int ans = high;
        while(low <= high){
            int mid = (low + high) / 2;
            int count = divideArray(nums, mid);
            if(count > k){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        return low;
    }
};