#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        // Optimal Approach (Moore's Voting Algorithm)
        int n = nums.size();
        int count = 0;
        int element = nums[0];
        for(int val : nums){
            if(count == 0){
                element = val;
                count++;
            }
            else if(val == element){
                count++;
            }
            else{
                count--;
            }
        }
        int tempCount = 0;
        for(int val : nums){
            if(val == element) tempCount++;
        }
        if(tempCount > (n / 2)) return element;
        return 0;

        // It takes O(n) space
        // int n = nums.size();
        // unordered_map<int, int> freq;
        // for(int val : nums){
        //     freq[val]++;
        // }
        // for(auto& val : freq){
        //     if(val.second > (n/2)){
        //         return val.first;
        //     }
        // }
        // return 0;
    }
};