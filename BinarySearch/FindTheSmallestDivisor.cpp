#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int computeSum(vector<int>& arr, int d) {
        int sum = 0;
        for (int num : arr) {
            sum += (num + d - 1) / d; // Equivalent to ceil(num / d)
        }
        return sum;
    }
  
    int smallestDivisor(vector<int>& arr, int k) {
        // Code here
        int low = 1;
        int high = *max_element(arr.begin(), arr.end());
        int ans = high;
    
        while (low <= high) {
            int mid = (low + high) / 2;
            int sum = computeSum(arr, mid);
            
            if (sum <= k) {
                ans = mid; // mid is a potential answer
                high = mid - 1; // try smaller
            } else {
                low = mid + 1; // try larger
            }
        }
        return ans;
    }
};