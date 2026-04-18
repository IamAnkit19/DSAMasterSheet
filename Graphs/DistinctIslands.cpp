#include<bits/stdc++.h>
using namespace std;

// User function Template for C++
class Solution {
    void bfs(vector<vector<int>> &grid, vector<vector<bool>> &visited, int x, int y, 
        vector<pair<int, int>> &temp){
        int m = grid.size(), n = grid[0].size();
        queue<pair<int, int>> q;
        q.push({x, y});
        visited[x][y] = true;
        int delX[4] = {-1, 0, 1, 0}, delY[4] = {0, -1, 0, 1};
        while(!q.empty()){
            pair<int, int> p = q.front();
            q.pop();
            int dx = p.first, dy = p.second;
            temp.push_back({x-dx, y-dy});
            for(int i=0; i<4; i++){
                int ndx = dx + delX[i], ndy = dy + delY[i];
                if(ndx >= 0 && ndx < m && ndy >= 0 && ndy < n && grid[ndx][ndy] == 1 && 
                    !visited[ndx][ndy]){
                    visited[ndx][ndy] = true;
                    q.push({ndx, ndy});
                }
            }
        }
    }
  public:
    int countDistinctIslands(vector<vector<int>>& grid) {
        // code here
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        set<vector<pair<int, int>>> s;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 1 && !visited[i][j]){
                    vector<pair<int, int>> temp;
                    bfs(grid, visited, i, j, temp);
                    s.insert(temp);
                }
            }
        }
        return s.size();
    }
};