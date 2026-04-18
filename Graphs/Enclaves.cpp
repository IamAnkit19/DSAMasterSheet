#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        int count = 0;
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(!visited[i][j] && grid[i][j] == 1){
                    queue<pair<int, int>> q;
                    q.push({i, j});
                    visited[i][j] = true;
                    bool isNoPath = true;
                    int ones = 0;
                    while(!q.empty()){
                        pair<int, int> p = q.front();
                        q.pop();
                        int x = p.first, y = p.second;
                        ones++;
                        if((x == 0) || (y == 0) || (x == m-1) || (y == n-1)){
                            isNoPath = false;
                        }
                        if(x > 0 && !visited[x-1][y] && grid[x-1][y] == 1){
                            q.push({x-1, y});
                            visited[x-1][y] = true;
                        }
                        if(y > 0 && !visited[x][y-1] && grid[x][y-1] == 1){
                            q.push({x, y-1});
                            visited[x][y-1] = true;
                        }
                        if(x < m-1 && !visited[x+1][y] && grid[x+1][y] == 1){
                            q.push({x+1, y});
                            visited[x+1][y] = true;
                        }
                        if(y < n-1 && !visited[x][y+1] && grid[x][y+1] == 1){
                            q.push({x, y+1});
                            visited[x][y+1] = true;
                        }
                    }
                    if(isNoPath){
                        count += ones;
                    }
                }
            }
        }
        return count;
    }
};