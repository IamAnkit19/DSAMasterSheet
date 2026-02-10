#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int missingNum(vector<int>& arr) {
        // code here
        long long n = arr.size() + 1;
        long long totalSum = (n*(n+1))/2;
        long long currSum = 0;
        for(long long val : arr){
            currSum += val;
        }
        return int(totalSum - currSum);
    }
};