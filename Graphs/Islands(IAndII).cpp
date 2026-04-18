#include<bits/stdc++.h>
using namespace std;

// I
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        queue<int> q;
        int count = 0;
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == '1' && !visited[i][j]){
                    queue<vector<int>> q;
                    visited[i][j] = true;
                    q.push({i, j});
                    while(!q.empty()){
                        vector<int> ele = q.front();
                        int x = ele[0], y = ele[1];
                        q.pop();
                        if(x>0 && grid[x-1][y] == '1' &&  !visited[x-1][y]){
                            visited[x-1][y] = true;
                            q.push({x-1, y});
                        }
                        if(y>0 && grid[x][y-1] == '1' &&  !visited[x][y-1]){
                            visited[x][y-1] = true;
                            q.push({x, y-1});
                        }
                        if(x<m-1 && grid[x+1][y] == '1' &&  !visited[x+1][y]){
                            visited[x+1][y] = true;
                            q.push({x+1, y});
                        }
                        if(y<n-1 && grid[x][y+1] == '1' &&  !visited[x][y+1]){
                            visited[x][y+1] = true;
                            q.push({x, y+1});
                        }
                    }
                    count++;
                }
            }
        }
        return count;
    }
};