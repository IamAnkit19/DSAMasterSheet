#include<bits/stdc++.h>
using namespace std;

class DisjointSet {
public:
    vector<int> rank, parent, size;
    DisjointSet(int n){
        rank.resize(n+1, 0);
        parent.resize(n+1);
        size.resize(n+1, 1);
        for(int i=0; i<=n; i++){
            parent[i] = i;
        }
    }
    int findUltimateParent(int node){
        if(node == parent[node]){
            return node;
        }
        // return findUltimateParent(parent[node]);
        return parent[node] = findUltimateParent(parent[node]); // Path compression
    }
    void unionByRank(int u, int v){
        int ulp_u = findUltimateParent(u);
        int ulp_v = findUltimateParent(v);
        if(ulp_u == ulp_v){
            return;
        }
        if(rank[ulp_u] < rank[ulp_v]){
            parent[ulp_u] = ulp_v;
        }
        else if(rank[ulp_v] < rank[ulp_v]){
            parent[ulp_v] = ulp_u;
        }
        else{
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
    void unionBySize(int u, int v){
        int ulp_u = findUltimateParent(u);
        int ulp_v = findUltimateParent(v);
        if(ulp_u == ulp_v){
            return;
        }
        if(size[ulp_u] < size[ulp_v]){
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
        else{
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};
class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        DisjointSet ds(n);
        int countExtra = 0;
        for(int i=0; i<connections.size(); i++){
            int u = connections[i][0];
            int v = connections[i][1];
            if(ds.findUltimateParent(u) == ds.findUltimateParent(v)){
                countExtra++;
            }
            else{
                ds.unionBySize(u, v);
            }
        }
        int countComponents = 0;
        for(int i=0; i<n; i++){
            if(ds.parent[i] == i){
                countComponents++;
            }
        }
        int ans = countComponents - 1;
        if(countExtra >= ans){
            return ans;
        }
        return -1;
    }
};