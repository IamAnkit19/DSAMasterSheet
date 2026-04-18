#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> adj(n);
        for(int i=0; i<flights.size(); i++){
            adj[flights[i][0]].push_back({flights[i][1], flights[i][2]});
        }
        queue<pair<int, pair<int, int>>> q;
        q.push({0, {src, 0}});
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;
        while(!q.empty()){
            pair<int, pair<int, int>> p = q.front();
            q.pop();
            int stops = p.first, node = p.second.first, cost = p.second.second;
            if(stops > k) continue;
            for(int i=0; i<adj[node].size(); i++){
                int to = adj[node][i].first, cst = adj[node][i].second;
                if(cost + cst < dist[to] && stops <= k){
                    dist[to] = cost + cst;
                    q.push({stops+1, {to, cost + cst}});
                }
            }
        }
        if(dist[dst] == INT_MAX){
            return -1;
        }
        return dist[dst];
    }
};