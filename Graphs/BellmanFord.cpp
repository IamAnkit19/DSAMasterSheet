#include<bits/stdc++.h>
using namespace std;

// User function Template for C++

class Solution {
  public:
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        // Code here
        vector<int> dist(V, 1e8);
        dist[src] = 0;
        for(int i=0; i<V-1; i++){
            for(int i=0; i<edges.size(); i++){
                int u = edges[i][0];
                int v = edges[i][1];
                int wt = edges[i][2];
                if(dist[u] != 1e8 && dist[u]+wt < dist[v]){
                    dist[v] = dist[u] + wt;
                }
            }
        }
        
        // Nth relaxation to check negative cycle
        for(int i=0; i<edges.size(); i++){
            int u = edges[i][0];
            int v = edges[i][1];
            int wt = edges[i][2];
            if(dist[u] != 1e8 && dist[u]+wt < dist[v]){
                return {-1};
            }
        }
    
        return dist;
    }
};