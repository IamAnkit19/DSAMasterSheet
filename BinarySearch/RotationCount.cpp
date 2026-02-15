#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int findKRotation(vector<int> &arr) {
        // Code Here
        int n = arr.size();
        int low = 0, high = n - 1;
        while (low <= high) {
            // If array is already sorted
            if (arr[low] <= arr[high])
                return low;
            int mid = low + (high - low) / 2;
            int next = (mid + 1) % n;
            int prev = (mid - 1 + n) % n;
            // Minimum element found
            if (arr[mid] <= arr[next] && arr[mid] <= arr[prev])
                return mid;
            // Decide which half to search
            if (arr[mid] >= arr[low])
                low = mid + 1;
            else
                high = mid - 1;
        }
        return 0;
    }
};