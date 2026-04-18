#include<bits/stdc++.h>
using namespace std;

class Solution {
    // DFS
    void dfs(int node, vector<vector<int>> &adj, vector<bool> &visited, stack<int> &st){
        visited[node] = true;
        for(int i=0; i<adj[node].size(); i++){
            if(!visited[adj[node][i]]){
                dfs(adj[node][i], adj, visited, st);
            }
        }
        st.push(node);
    }
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        // BFS WAY
        vector<vector<int>> adj(V);
        for(int i=0; i<edges.size(); i++){
            adj[edges[i][0]].push_back(edges[i][1]);
        }
        vector<int> indegree(V, 0);
        for(int i=0; i<V; i++){
            for(int j=0; j<adj[i].size(); j++){
                indegree[adj[i][j]]++;
            }
        }
        vector<int> ans;
        queue<int> q;
        for(int i=0; i<V; i++){
            if(!indegree[i]){
                q.push(i);
            }
        }
        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans.push_back(node);
            for(int i=0; i<adj[node].size(); i++){
                indegree[adj[node][i]]--;
                if(!indegree[adj[node][i]]){
                    q.push(adj[node][i]);
                }
            }
        }
        return ans;
        
        // DFS WAY
        // vector<vector<int>> adj(V);
        // for(int i=0; i<edges.size(); i++){
        //     adj[edges[i][0]].push_back(edges[i][1]);
        // }
        // vector<bool> visited(V, false);
        // stack<int> st;
        // for(int i=0; i<V; i++){
        //     if(!visited[i]){
        //         dfs(i, adj, visited, st);
        //     }
            
        // }
        // vector<int> ans;
        // while(!st.empty()){
        //     ans.push_back(st.top());
        //     st.pop();
        // }
        // return ans;
    }
};