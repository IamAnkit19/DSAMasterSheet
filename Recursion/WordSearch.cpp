#include<bits/stdc++.h>
using namespace std;

class Solution {
    bool solve(vector<vector<char>> &board, string &word, vector<vector<bool>> &visited, int i, int j, int m, int n, int idx){
        if(idx == word.length()){
            return true;
        }
        if(i < 0 || j < 0 || i >= m || j >= n){
            return false;
        }
        if(visited[i][j] || board[i][j] != word[idx]){
            return false;
        }
        visited[i][j] = true;
        bool found = solve(board, word, visited, i+1, j, m, n, idx+1) ||
            solve(board, word, visited, i-1, j, m, n, idx+1) ||
            solve(board, word, visited, i, j+1, m, n, idx+1) ||
            solve(board, word, visited, i, j-1, m, n, idx+1);
        visited[i][j] = false;
        return found;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(board[i][j] == word[0]){
                    vector<vector<bool>> visited(m, vector<bool>(n, false));
                    if(solve(board, word, visited, i, j, m, n, 0)){
                        return true;
                    }
                }
            }
        }
        return false;
    }
};