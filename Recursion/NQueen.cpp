#include<bits/stdc++.h>
using namespace std;

class Solution {
    bool isSafe(vector<string> &board, int row, int col, int n, vector<vector<string>> &ans){
        // Horizontal
        for(int j=0; j<n; j++){
            if(board[row][j] == 'Q'){
                return false;
            }
        }
        // Vertical
        for(int i=0; i<n; i++){
            if(board[i][col] == 'Q'){
                return false;
            }
        }
        // Left Diagonal
        for(int i=row, j=col; i>=0 && j>=0; i--,j--){
            if(board[i][j] == 'Q'){
                return false;
            }
        }
        // Right Diagonal
        for(int i=row, j=col; i>=0 && j<n; i--,j++){
            if(board[i][j] == 'Q'){
                return false;
            }
        }
        return true;
    }
    void nQueens(vector<string> &board, int row, int n, vector<vector<string>> &ans){
        if(row >= n){
            ans.push_back({board});
            return;
        }
        for(int j=0; j<n; j++){
            if(isSafe(board, row, j, n, ans)){
                board[row][j] = 'Q';
                nQueens(board, row+1, n, ans);
                board[row][j] = '.';
            }
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n, string(n, '.'));
        nQueens(board, 0, n, ans);
        return ans;
    }
};