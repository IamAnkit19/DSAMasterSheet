#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<vector<int>> nearest(vector<vector<int>>& grid) {
        // code here
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> ans(m, vector<int>(n, 0));
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        queue<pair<pair<int, int>, int>> q;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 1){
                    q.push({{i, j}, 0});
                    visited[i][j] = true;
                }
            }
        }
        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, -1, 0, 1};
        while(!q.empty()){
            pair<pair<int, int>, int> p = q.front();
            q.pop();
            int x = p.first.first, y = p.first.second, dist = p.second;
            ans[x][y] = dist;
            for(int i=0; i<4; i++){
                int dx = x + delRow[i];
                int dy = y + delCol[i];
                if(dx >= 0 && dx < m && dy >= 0 && dy < n && !visited[dx][dy]){
                    visited[dx][dy] = true;
                    q.push({{dx, dy}, dist+1});
                }
            }
        }
        return ans;
    }
};