#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        long long n = grid.size();
        long long totalSum = ((n*n)*((n*n)+1)) / 2;
        long long totalSquareSum = ((n*n) * ((n*n)+1) * (2*(n*n)+1)) / 6;
        long long sum = 0, squareSum = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                sum += grid[i][j];
                squareSum += (1LL * grid[i][j] * grid[i][j]);
            }
        }
        long long val1 = sum - totalSum;
        long long val2 = squareSum - totalSquareSum;
        val2 = val2 / val1;
        long long x = (val1 + val2) / 2;
        long long y = x - val1;
        return {(int)x, (int)y};
    }
};