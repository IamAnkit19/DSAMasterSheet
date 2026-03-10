#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    // bool solve(vector<vector<char>>& board) {
    //     for (int row = 0; row < 9; row++) {
    //         for (int col = 0; col < 9; col++) {
    //             if (board[row][col] == '.') {  // Empty cell
    //                 for (char c = '1'; c <= '9'; c++) {
    //                     if (isValid(board, row, col, c)) {
    //                         board[row][col] = c;  // Place digit
    //                         if (solve(board)) return true;  // Recurse
    //                         board[row][col] = '.';  // Backtrack
    //                     }
    //                 }
    //                 return false; // No valid number found
    //             }
    //         }
    //     }
    //     return true; // Solved
    // }
    // bool isValid(vector<vector<char>>& board, int row, int col, char c) {
    //     for (int i = 0; i < 9; i++) {
    //         // Check row
    //         if (board[row][i] == c) return false;
    //         // Check col
    //         if (board[i][col] == c) return false;
    //         // Check 3x3 sub-box
    //         int boxRow = 3 * (row / 3) + i / 3;
    //         int boxCol = 3 * (col / 3) + i % 3;
    //         if (board[boxRow][boxCol] == c) return false;
    //     }
    //     return true;
    // }

    bool isSafe(vector<vector<char>> &board, int row, int col, char digit){
        // Horizontal
        for(int j=0; j<9; j++){
            if(board[row][j] == digit){
                return false;
            }
        }
        // Vertical
        for(int i=0; i<9; i++){
            if(board[i][col] == digit){
                return false;
            }
        }
        // Grid
        int sr = (row / 3) * 3;
        int sc = (col / 3) * 3;
        for(int i=sr; i<=sr+2; i++){
            for(int j=sc; j<=sc+2; j++){
                if(board[i][j] == digit){
                    return false;
                }
            }
        }
        return true;
    }

    bool solve(vector<vector<char>> &board, int row, int col){
        if(row == 9){
            return true;
        }
        int nextRow = row, nextCol = col+1;
        if(nextCol == 9){
            nextRow++;
            nextCol = 0;
        }
        if(board[row][col] != '.'){
            return solve(board, nextRow, nextCol);
        }
        for(char i='1'; i<='9'; i++){
            if(isSafe(board, row, col, i)){
                board[row][col] = i;
                if(solve(board, nextRow, nextCol)){
                    return true;
                }
                board[row][col] = '.';
            }
        }
        return false;
    }
    
    void solveSudoku(vector<vector<char>>& board) {
        solve(board, 0, 0);
    }
};