#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> rotateMatrix(vector<vector<int>> &matrix)
    {
        // Write your code here.
        int n = matrix.size();
        // Reverse rows
        for(int i=0; i<n; i++){
            int l = 0, r = n - 1;
            while(l < r){
                int temp = matrix[i][l];
                matrix[i][l] = matrix[i][r];
                matrix[i][r] = temp;
                l++;
                r--;
            }
        }
        // Transpose
        for(int i=0; i<n; i++){
            for(int j=i; j<n; j++){
                if(i == j){
                    continue;
                }
                int temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp;
            }
        }
        return matrix;
    }
};