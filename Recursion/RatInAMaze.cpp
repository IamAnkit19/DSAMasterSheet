#include<bits/stdc++.h>
using namespace std;

class Solution {
    void solve(vector<vector<int>> &maze, string currPath, vector<vector<bool>> &visited, 
        vector<string> &ans, int i, int j, int n){
        if(i == n-1 && j == n-1){
            ans.push_back(currPath);
            return;
        }
        visited[i][j] = true;
        // Down
        if(i+1 < n && !visited[i+1][j] && maze[i+1][j] == 1){
            solve(maze, currPath+'D', visited, ans, i+1, j, n);
        }
        // Left
        if(j-1 >= 0 && !visited[i][j-1] && maze[i][j-1] == 1){
            solve(maze, currPath+'L', visited, ans, i, j-1, n);
        }
        // Right
        if(j+1 < n && !visited[i][j+1] && maze[i][j+1] == 1){
            solve(maze, currPath+'R', visited, ans, i, j+1, n);
        }
        // Up
        if(i-1 >= 0 && !visited[i-1][j] && maze[i-1][j] == 1){
            solve(maze, currPath+'U', visited, ans, i-1, j, n);
        }
        visited[i][j] = false;
    }
  public:
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        // code here
        int n = maze.size();
        vector<string> ans;
        vector<vector<bool>> visited(n, vector<bool>(n, false));
        if(maze[0][0] == 0 || maze[n-1][n-1] == 0) return ans;
        solve(maze, "", visited, ans, 0, 0, n);
        return ans;
    }
};