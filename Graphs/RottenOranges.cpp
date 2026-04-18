#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        queue<pair<pair<int, int>, int>> q;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 2){
                    q.push({{i, j}, 0});
                }
            }
        }
        int ans = 0;
        while(!q.empty()){
            pair<pair<int, int>, int> p = q.front();
            q.pop();
            int x = p.first.first, y = p.first.second, time = p.second;
            ans = max(ans, time);
            if(x > 0 && !visited[x-1][y] && grid[x-1][y] == 1){
                visited[x-1][y] = true;
                q.push({{x-1, y}, time+1});
            }
            if(y > 0 && !visited[x][y-1] && grid[x][y-1] == 1){
                visited[x][y-1] = true;
                q.push({{x, y-1}, time+1});
            }
            if(x < m-1 && !visited[x+1][y] && grid[x+1][y] == 1){
                visited[x+1][y] = true;
                q.push({{x+1, y}, time+1});
            }
            if(y < n-1 && !visited[x][y+1] && grid[x][y+1] == 1){
                visited[x][y+1] = true;
                q.push({{x, y+1}, time+1});
            }
        }
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 1 && !visited[i][j]){
                    return -1;
                }
            }
        }
        return ans;
    }
};