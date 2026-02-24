#include<bits/stdc++.h>
using namespace std;

class Solution {
    bool isSafe(int node, vector<vector<int>> &adj, int col, vector<int> &color){
        for(auto it : adj[node]){
            if(color[it] != -1 && col == color[it]){
                return false;
            }
        }
        return true;
    }
    bool solve(int node, vector<vector<int>> &adj, int m, vector<int> &color){
        if(node == color.size()){
            return true;
        }
        for(int i=0; i<m; i++){
            if(isSafe(node, adj, i, color)){
                color[node] = i;
                if(solve(node+1, adj, m, color)){
                    return true;
                }
                color[node] = -1;
            }
        }
        return false;
    }
  public:
    bool graphColoring(int v, vector<vector<int>> &edges, int m) {
        // code here
        vector<int> color(v, -1);
        vector<vector<int>> adj(v);
        // Creating adjacency matrix
        for(int i=0; i<edges.size(); i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        return solve(0, adj, m, color);
    }
};