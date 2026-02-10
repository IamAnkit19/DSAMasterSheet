#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int k = 1;
        for(int i = 1; i < n; i++){
            if (nums[i] != nums[k - 1]) {
                nums[k] = nums[i];                
                k++;
            }
        }
        return k;

        // Not Optimized...
        // int i = 1;
        // while(i < n){
        //     if(nums[i-1] == nums[i]){
        //         int j = i;
        //         while(j < n - 1){
        //             nums[j] = nums[j + 1];
        //             j++;
        //         }
        //         n--;
        //         continue;
        //     }
        //     i++;
        // }
        // return n;
    }
};