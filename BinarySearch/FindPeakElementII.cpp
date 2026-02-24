#include<bits/stdc++.h>
using namespace std;

class Solution {
    int maxEle(vector<vector<int>> &mat, int mid){
        int maxEl = -1, idx = -1;
        for(int i=0; i<mat.size(); i++){
            if(mat[i][mid] > maxEl){
                maxEl = mat[i][mid];
                idx = i;
            }
        }
        return idx;
    }
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        int l = 0, h = n - 1;
        while(l <= h){
            int mid = (l + h) / 2;
            int x = maxEle(mat, mid);
            int left = mid-1 >= 0 ? mat[x][mid-1] : -1;
            int right = mid+1 < n ? mat[x][mid+1] : -1;
            if(mat[x][mid] > left && mat[x][mid] > right){
                return {x, mid};
            }
            else if(mat[x][mid] < left){
                h = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }
        return {-1, -1};
    }
};