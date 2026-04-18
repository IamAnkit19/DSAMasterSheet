#include<bits/stdc++.h>
using namespace std;

class Solution {
    void dfs(int x, int y, vector<vector<bool>> &visited, int m, int n, vector<vector<char>> &board){
        stack<pair<int, int>> st;
        st.push({x, y});
        visited[x][y] = true;
        int delX[4] = {-1, 0, 1, 0}, delY[4] = {0, -1, 0, 1};
        while(!st.empty()){
            pair<int, int> p = st.top();
            st.pop();
            x = p.first, y = p.second;
            for(int i=0; i<4; i++){
                int dx = x + delX[i], dy = y + delY[i];
                if(dx >=0 && dx < m && dy >=0 && dy < n && board[dx][dy] == 'O' && !visited[dx][dy]){
                    visited[dx][dy] = true;
                    st.push({dx, dy});
                }
            }
        }
    }
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size(), n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        // First row
        for(int j=0; j<n; j++){
            if(board[0][j] == 'O' && !visited[0][j]){
                dfs(0, j, visited, m, n, board);
            }
        }
        // Last row
        for(int j=0; j<n; j++){
            if(board[m-1][j] == 'O' && !visited[m-1][j]){
                dfs(m-1, j, visited, m, n, board);
            }
        }
        // First col
        for(int i=0; i<m; i++){
            if(board[i][0] == 'O' && !visited[i][0]){
                dfs(i, 0, visited, m, n, board);
            }
        }
        // Last col
        for(int i=0; i<m; i++){
            if(board[i][n-1] == 'O' && !visited[i][n-1]){
                dfs(i, n-1, visited, m, n, board);
            }
        }
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(board[i][j] == 'O' && !visited[i][j]){
                    board[i][j] = 'X';
                }
            }
        }
    }
};