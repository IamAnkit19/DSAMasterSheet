#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        map[0] = 1;
        int count = 0;
        int prefixSum = 0;
        for(int i=0; i<nums.size(); i++){
            prefixSum += nums[i];
            int remove = prefixSum - k;
            count += map[remove];
            map[prefixSum]++;
        }
        return count;
    }
};