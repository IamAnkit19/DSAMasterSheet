#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    /*Complete the functions below*/
    int find(int par[], int x) {
        // add code here
        if(par[x] == x){
            return x;
        }
        return par[x] = find(par, par[x]);
    }

    void unionSet(int par[], int x, int z) {
        // add code here.
        int xrep = find(par, x), zrep = find(par, z);
        par[xrep] = zrep;
    }
};

class DisjointSet {
    vector<int> rank, parent, size;
public:
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