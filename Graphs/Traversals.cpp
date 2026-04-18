#include<bits/stdc++.h>
using namespace std;

// DFS
class Solution {
    void helper(int start, vector<vector<int>> &adj, vector<bool> &visited, vector<int> &ans){
        visited[start] = true;
        ans.push_back(start);
        for(int i=0; i<adj[start].size(); i++){
            if(!visited[adj[start][i]]){
                helper(adj[start][i], adj, visited, ans);
            }
        }
    }
  public:
    vector<int> dfs(vector<vector<int>>& adj) {
        // Code here
        int n = adj.size();
        vector<bool> visited(n, false);
        vector<int> ans;
        helper(0, adj, visited, ans);
        return ans;
    }
};

// BFS
class Solution {
    void helper(int start, vector<vector<int>> &adj, vector<bool> &visited, vector<int> &ans){
        queue<int> q;
        visited[start] = true;
        q.push(start);
        while(!q.empty()){
            int ele = q.front();
            q.pop();
            ans.push_back(ele);
            for(int i=0; i<adj[ele].size(); i++){
                if(!visited[adj[ele][i]]){
                    visited[adj[ele][i]] = true;
                    q.push(adj[ele][i]);
                }
            }
        }
    }
  public:
    vector<int> bfs(vector<vector<int>> &adj) {
        // code here
        int n = adj.size();
        vector<bool> visited(n, false);
        vector<int> ans;
        helper(0, adj, visited, ans);
        return ans;
    }
};