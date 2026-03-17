#include<bits/stdc++.h>
using namespace std;

class Solution {
    static bool basis(vector<int> a, vector<int> b){
        return a[1] < b[1];
    }
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), basis);
        int n = intervals.size();
        int nonOverlapping = 1, lastIndex = 0;
        for(int i=1; i<n; i++){
            if(intervals[lastIndex][1] <= intervals[i][0]){
                lastIndex = i;
                nonOverlapping++;
            }
        }
        return n - nonOverlapping;
    }
};