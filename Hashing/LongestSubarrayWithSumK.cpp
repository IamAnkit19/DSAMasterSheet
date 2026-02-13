#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int longestSubarray(vector<int>& arr, int k) {
        // code here
        map<int, int> preMap;
        long long sum = 0;
        int maxLength = 0;
        for(int i=0; i < arr.size(); i++){
            sum += arr[i];
            if(sum == k){
                maxLength = max(maxLength, i+1);
            }
            int rem = sum - k;
            if(preMap.find(rem) != preMap.end()){
                int len = i - preMap[rem];
                maxLength = max(maxLength, len);
            }
            if(preMap.find(sum) == preMap.end()){
                preMap[sum] = i;
            }
        }
        return maxLength;
    }
};