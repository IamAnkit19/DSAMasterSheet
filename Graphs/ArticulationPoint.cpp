#include<bits/stdc++.h>
using namespace std;

// User function Template for C++

class Solution {
    int timer = 0;
    void dfs(int node, int parent, vector<bool> &vis, vector<int> &tin, 
        vector<int> &low, vector<bool> &mark, vector<int> adj[]){
        vis[node] = true;
        tin[node] = low[node] = timer;
        timer++;
        int child = 0;
        for(int i=0; i<adj[node].size(); i++){
            if(adj[node][i] == parent){
                continue;
            }
            if(!vis[adj[node][i]]){
                dfs(adj[node][i], node, vis, tin, low, mark, adj);
                low[node] = min(low[node], low[adj[node][i]]);
                if(low[adj[node][i]] >= tin[node] && parent != -1){
                    mark[node] = true;
                }
                child++;
            }
            else{
                low[node] = min(low[node], tin[adj[node][i]]);
            }
        }
        if(child > 1 && parent == -1){
            mark[node] = true;
        }
    }
  public:
    vector<int> articulationPoints(int V, vector<int> adj[]) {
        // Code here
        vector<bool> vis(V, false), mark(V, false);
        vector<int> tin(V, 0), low(V, 0);
        for(int i=0; i<V; i++){
            if(!vis[i]){
                dfs(i, -1, vis, tin, low, mark, adj);
            }
        }
        vector<int> ans;
        for(int i=0; i<V; i++){
            if(mark[i]){
                ans.push_back(i);
            }
        }
        if(!ans.size()){
            return {-1};
        }
        return ans;
    }
};