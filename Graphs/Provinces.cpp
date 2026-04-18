#include<bits/stdc++.h>
using namespace std;

class Solution {
    void dfs(int start, vector<vector<int>> &adj, vector<bool> &visited){
        visited[start] = true;
        for(int i=0; i<adj[start].size(); i++){
            if(!visited[adj[start][i]]){
                dfs(adj[start][i], adj, visited);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<bool> visited(n, false);
        vector<vector<int>> adj(n);
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(isConnected[i][j]){
                    adj[i].push_back(j);
                }
            }
        }
        int count = 0;
        for(int i=0; i<n; i++){
            if(!visited[i]){
                dfs(i, adj, visited);
                count++;
            }
        }
        return count;
    }
};