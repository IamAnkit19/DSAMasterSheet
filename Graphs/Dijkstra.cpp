#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Code here
        // Using Priority Queue
        // vector<vector<pair<int, int>>> adj(V);
        // for(int i=0; i<edges.size(); i++){
        //     adj[edges[i][0]].push_back({edges[i][1], edges[i][2]});
        //     adj[edges[i][1]].push_back({edges[i][0], edges[i][2]});
        // }
        // // priority_queue<pair<int, int>> pq; // Max heap(It won't be used here)
        // priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // Min heap
        // vector<int> dist(V, INT_MAX);
        // dist[src] = 0;
        // pq.push({dist[src], src});
        // while(!pq.empty()){
        //     pair<int, int> p = pq.top();
        //     pq.pop();
        //     int d = p.first, node = p.second;
        //     if(d > dist[node]) continue;
        //     for(int i=0; i<adj[node].size(); i++){
        //         if(dist[adj[node][i].first] > d+adj[node][i].second){
        //             dist[adj[node][i].first] = d+adj[node][i].second;
        //             pq.push({d+adj[node][i].second, adj[node][i].first});
        //         }
        //     }
        // }
        // return dist;
        
        // Using set
        vector<vector<pair<int, int>>> adj(V);
        for(int i=0; i<edges.size(); i++){
            adj[edges[i][0]].push_back({edges[i][1], edges[i][2]});
            adj[edges[i][1]].push_back({edges[i][0], edges[i][2]});
        }
        set<pair<int, int>> s;
        vector<int> dist(V, INT_MAX);
        dist[src] = 0;
        s.insert({dist[src], src});
        while(!s.empty()){
            pair<int, int> p = *(s.begin());
            s.erase(p);
            int d = p.first, node = p.second;
            if(d > dist[node]) continue;
            for(int i=0; i<adj[node].size(); i++){
                if(dist[adj[node][i].first] > d+adj[node][i].second){
                    dist[adj[node][i].first] = d+adj[node][i].second;
                    s.insert({d+adj[node][i].second, adj[node][i].first});
                }
            }
        }
        return dist;
    }
};