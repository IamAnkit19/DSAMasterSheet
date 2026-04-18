#include<bits/stdc++.h>
using namespace std;

class Solution {
    void dfs(int node, vector<vector<int>> &adj, stack<int> &st, vector<bool> &vis){
        vis[node] = true;
        for(int i=0; i<adj[node].size(); i++){
            if(!vis[adj[node][i]]){
                dfs(adj[node][i], adj, st, vis);
            }
        }
        st.push(node);
    }
    void dfs3(int node, vector<bool> &vis, vector<vector<int>> &revAdj){
        vis[node] = true;
        for(int i=0; i<revAdj[node].size(); i++){
            if(!vis[revAdj[node][i]]){
                dfs3(revAdj[node][i], vis, revAdj);
            }
        }
    }
  public:
    int kosaraju(int V, vector<vector<int>> &edges) {
        // code here
        vector<vector<int>> adj(V);
        for(int i=0; i<edges.size(); i++){
            adj[edges[i][0]].push_back(edges[i][1]);
        }
        vector<bool> vis(V, false);
        stack<int> st;
        for(int i=0; i<V; i++){
            if(!vis[i]){
                dfs(i, adj, st, vis);
            }
        }
        vector<vector<int>> revAdj(V);
        for(int i=0; i<V; i++){
            vis[i] = false;
            for(int j=0; j<adj[i].size(); j++){
                revAdj[adj[i][j]].push_back(i);
            }
        }
        int scc = 0;
        while(!st.empty()){
            int node = st.top();
            st.pop();
            if(!vis[node]){
                scc++;
                dfs3(node, vis, revAdj);
            }
        }
        return scc;
    }
};