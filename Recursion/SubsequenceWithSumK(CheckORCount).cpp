#include<bits/stdc++.h>
using namespace std;

// Check
class Solution {
    // Recursive
    bool check(int n, int idx, vector<int> &arr, int k, int currSum){
        if(idx == n){
            return currSum == k;
        }
        currSum += arr[idx];
        bool take = check(n, idx+1, arr, k, currSum);
        currSum -= arr[idx];
        bool notTake = check(n, idx+1, arr, k, currSum);
        return take || notTake;
    }
  public:
    bool checkSubsequenceSum(int n, vector<int>& arr, int k) {
        // Code here
        return check(n, 0, arr, k, 0);
    }
};