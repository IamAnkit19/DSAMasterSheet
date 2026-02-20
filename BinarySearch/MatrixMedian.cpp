#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int upperBound(vector<int> &arr, int m, int target){
        int l = 0, h = m;
        while(l <= h){
            int mid = (l + h) / 2;
            if(arr[mid] <= target){
                l = mid + 1;
            }
            else{
                h = mid - 1;
            }
        }
        return l;
    }
    int blackBox(vector<vector<int>> &arr, int mid, int n, int m){
        int count = 0;
        for(int i=0; i<n; i++){
            count += upperBound(arr[i], m, mid);
        }
        return count;
    }
    int findMedian(vector<vector<int> > &arr, int n, int m){
        // Write your code here 
        int low = INT32_MAX, high = INT32_MIN;
        for(int i=0; i<n; i++){
            low = min(low, arr[i][0]);
            high = max(high, arr[i][m-1]);
        }
        int required = (n*m)/2;
        while(low <= high){
            int mid = (low + high) / 2;
            int smallerEquals = blackBox(arr, mid, n, m);
            if(smallerEquals <= required){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }
        return low;
    }
};