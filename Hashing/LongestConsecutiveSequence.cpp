#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> set;
        for(int val : nums){
            set.insert(val);
        }
        int maxLength = 0;
        for(int val : set){
            if(set.find(val-1) == set.end()){
                int count = 1;
                while(set.find(val + count) != set.end()){
                    count++;
                }
                maxLength = max(maxLength, count);
            }
        }
        return maxLength;
    }
};