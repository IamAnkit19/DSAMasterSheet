#include<bits/stdc++.h>
using namespace std;

// I
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int l = 0, h = matrix.size()-1;
        while(l <= h){
            int mid = (l + h) / 2;
            if(matrix[mid][0] <= target && matrix[mid][(matrix[mid].size()-1)] >= target){
                int left = 0, right = matrix[mid].size()-1;
                while(left <= right){
                    int middle = (left + right) / 2;
                    if(matrix[mid][middle] == target){
                        return true;
                    }
                    else if(matrix[mid][middle] < target){
                        left = middle + 1;
                    }
                    else{
                        right = middle - 1;
                    }
                }
                return false;
            }
            else if(matrix[mid][0] > target){
                h = mid - 1;
            }
            else{
                l = mid + 1;
            }
        }
        return false;
    }
};

// II
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size(), m = matrix[0].size();
        int row = 0, col = m - 1;
        while(row < n && col >= 0){
            if(matrix[row][col] == target){
                return true;
            }
            else if(matrix[row][col] < target){
                row++;
            }
            else{
                col--;
            }
        }
        return false;
    }
};