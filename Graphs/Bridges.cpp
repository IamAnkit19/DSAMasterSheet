#include<bits/stdc++.h>
using namespace std;

class Solution {
    int timer = 1;
    void dfs(int node, int parent, vector<vector<int>> &adj, vector<bool> &vis, vector<int> &tin, vector<int> &low, vector<vector<int>> &bridges){
        vis[node] = true;
        tin[node] = low[node] = timer;
        timer++;
        for(int i=0; i<adj[node].size(); i++){
            if(adj[node][i] == parent){
                continue;
            }
            if(!vis[adj[node][i]]){
                dfs(adj[node][i], node, adj, vis, tin, low, bridges);
                low[node] = min(low[node], low[adj[node][i]]);
                if(low[adj[node][i]] > tin[node]){
                    bridges.push_back({node, adj[node][i]});
                }
            }
            else{
                low[node] = min(low[node], low[adj[node][i]]);
            }
        }
    }
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj(n);
        for(int i=0; i<connections.size(); i++){
            adj[connections[i][0]].push_back(connections[i][1]);
            adj[connections[i][1]].push_back(connections[i][0]);
        }
        vector<bool> vis(n, false);
        vector<int> tin(n), low(n);
        vector<vector<int>> bridges;
        dfs(0, -1, adj, vis, tin, low, bridges);
        return bridges;
    }
};