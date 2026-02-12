#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        int n = nums.size();
        int majority1, majority2;
        int count1 = 0, count2 = 0;
        vector<int> ans;
        for(int i=0; i<n; i++){
            if(count1 == 0 && majority2 != nums[i]){
                majority1 = nums[i];
                count1++;
            }
            else if(count2 == 0 && majority1 != nums[i]){
                majority2 = nums[i];
                count2++;
            }
            else if(majority1 == nums[i]){
                count1++;
            }
            else if(majority2 == nums[i]){
                count2++;
            }
            else{
                count1--;
                count2--;
            }
        }
        int tempCount1 = 0, tempCount2 = 0;
        for(int i=0; i<n; i++){
            if(nums[i] == majority1) tempCount1++;
            else if(nums[i] == majority2) tempCount2++;
        }
        if(tempCount1 > (n/3)){
            ans.push_back(majority1);
        }
        if(tempCount2 > (n/3)){
            ans.push_back(majority2);
        }
        return ans;
    }
};