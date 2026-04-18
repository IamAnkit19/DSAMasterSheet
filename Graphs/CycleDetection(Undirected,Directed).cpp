#include<bits/stdc++.h>
using namespace std;

// Undirected
class Solution {
  public:
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        vector<bool> visited(V, false);
        vector<vector<int>> adj(V);
        for(int i=0; i<edges.size(); i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        for(int v=0; v<V; v++){
            if(!visited[v]){
                queue<pair<int, int>> q;
                q.push({v, -1});
                visited[v] = true;
                while(!q.empty()){
                    pair<int, int> p = q.front();
                    q.pop();
                    int vertex = p.first, parent = p.second;
                    for(int i=0; i<adj[vertex].size(); i++){
                        if(visited[adj[vertex][i]] && adj[vertex][i] != parent){
                            return true;
                        }
                        if(!visited[adj[vertex][i]]){
                            q.push({adj[vertex][i], vertex});
                            visited[adj[vertex][i]] = true;
                        }
                    }
                }
            }
        }
        return false;
    }
};

// Directed
class Solution {
    bool dfs(int v, vector<vector<int>> &adj, vector<bool> &visited, vector<bool> &recStack){
        visited[v] = true;
        recStack[v] = true;
        for(int i=0; i<adj[v].size(); i++){
            if(!visited[adj[v][i]] && dfs(adj[v][i], adj, visited, recStack)){
                return true;
            }
            else if(recStack[adj[v][i]]){
                return true;
            }
        }
        recStack[v] = false;
        return false;
    }
  public:
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        vector<bool> visited(V, false), recStack(V, false);
        vector<vector<int>> adj(V);
        for(int i=0; i<edges.size(); i++){
            adj[edges[i][0]].push_back(edges[i][1]);
        }
        for(int v=0; v<V; v++){
            if(!visited[v]){
                if(dfs(v, adj, visited, recStack)){
                    return true;
                }
            }
        }
        return false;
    }
};