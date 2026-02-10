#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        bool isPos = true;
        int i = 0, j = 0;
        while(i < n && j < n){
            if(isPos){
                while(i < n && nums[i] < 0){
                    i++;
                }
                if(i < n){
                    ans.push_back(nums[i]);
                }
                isPos = false;
                i++;
            }
            else{
                while(j < n && nums[j] >= 0){
                    j++;
                }
                if(j < n){
                    ans.push_back(nums[j]);
                }
                isPos = true;
                j++;
            }
        }
        if(isPos){
            while(i < n && nums[i] < 0){
                i++;
            }
            if(i < n){
                ans.push_back(nums[i]);
            }
        }
        else{
            while(j < n && nums[j] >= 0){
                j++;
            }
            if(j < n){
                ans.push_back(nums[j]);
            }
        }
        return ans;

        // Another way...
        // vector<int> pos, neg;
        // for(int val : nums){
        //     if(val < 0){
        //         neg.push_back(val);
        //     }
        //     else{
        //         pos.push_back(val);
        //     }
        // }
        // int n = pos.size();
        // vector<int> ans;
        // for(int i=0; i<n; i++){
        //     ans.push_back(pos[i]);
        //     ans.push_back(neg[i]);
        // }
        // return ans;

        // Wrong...
        // int n = nums.size();
        // int oddIt = 1;
        // for(int evenIt=0; evenIt<n; evenIt+=2){
        //     if(nums[evenIt] < 0){
        //         while(oddIt < n && nums[oddIt] < 0){
        //             oddIt+=2;
        //         }
        //         if(oddIt < n){
        //             int temp = nums[evenIt];
        //             nums[evenIt] = nums[oddIt];
        //             nums[oddIt] = temp;
        //         }
        //     }
        //     else if(nums[oddIt] >= 0){
        //         while(evenIt < n && nums[evenIt] >= 0){
        //             evenIt+=2;
        //         }
        //         if(evenIt < n){
        //             int temp = nums[evenIt];
        //             nums[evenIt] = nums[oddIt];
        //             nums[oddIt] = temp;
        //         }
        //     }
        //     oddIt += 2;
        // }
        // return nums;
    }
};