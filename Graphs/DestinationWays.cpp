#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int, int>>> adj(n);
        for(int i=0; i<roads.size(); i++){
            adj[roads[i][0]].push_back({roads[i][1], roads[i][2]});
            adj[roads[i][1]].push_back({roads[i][0], roads[i][2]});
        }
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        vector<int> ways(n, 0);
        vector<long long> dist(n, LLONG_MAX);
        pq.push({0, 0});
        dist[0] = 0, ways[0] = 1;
        int mod = (int)(1e9 + 7);
        while(!pq.empty()){
            pair<long long, int> p = pq.top();
            pq.pop();
            long long d = p.first;
            int node = p.second;
            for(int i=0; i<adj[node].size(); i++){
                int adjNode = adj[node][i].first;
                long long adjWeight = adj[node][i].second;
                if(adjWeight + d < dist[adjNode]){
                    dist[adjNode] = adjWeight + d;
                    ways[adjNode] = ways[node];
                    pq.push({adjWeight+d, adjNode});
                }
                else if(adjWeight + d == dist[adjNode]){
                    ways[adjNode] = (ways[adjNode] + ways[node]) % mod;
                }
            }
        }
        return (ways[n-1] % mod);
    }
};