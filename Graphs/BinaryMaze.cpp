#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if(grid[0][0] == 1 || grid[n-1][n-1] == 1){
            return -1;
        }
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        queue<pair<pair<int, int>, int>> q;
        q.push({{0,0},1});
        visited[0][0] = true;
        int delX[] = {-1,-1,0,1,1,1,0,-1}, delY[] = {0,-1,-1,-1,0,1,1,1};
        while(!q.empty()){
            pair<pair<int, int>, int> p = q.front();
            q.pop();
            int x = p.first.first, y = p.first.second, d = p.second;
            if(x == n-1 && y == n-1){
                return d;
            }
            for(int i=0; i<8; i++){
                int dx = x + delX[i], dy = y + delY[i];
                if(dx >= 0 && dx < n && dy >= 0 && dy < n && !visited[dx][dy] && grid[dx][dy] == 0){
                    visited[dx][dy] = true;
                    q.push({{dx, dy}, d+1});
                }
            }
        }
        return -1;
    }
};