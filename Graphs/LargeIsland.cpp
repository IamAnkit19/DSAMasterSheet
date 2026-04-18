#include<bits/stdc++.h>
using namespace std;

class DisjointSet{
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
        if(parent[node] == node){
            return node;
        }
        return parent[node] = findUltimateParent(parent[node]);
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
        else if(rank[ulp_v] < rank[ulp_u]){
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
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        DisjointSet ds(n*n);
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 0){
                    continue;
                }
                int dirX[4] = {-1,0,1,0};
                int dirY[4] = {0,-1,0,1};
                for(int k=0; k<4; k++){
                    int ndx = i + dirX[k];
                    int ndy = j + dirY[k];
                    if(ndx >= 0 && ndx < n && ndy >= 0 && ndy < n && grid[ndx][ndy] == 1){
                        int node = i * n + j;
                        int adjNode = ndx * n + ndy;
                        ds.unionBySize(node, adjNode);
                    }
                }
            }
        }
        int ans = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(grid[i][j] == 0){
                    int dirX[4] = {-1,0,1,0};
                    int dirY[4] = {0,-1,0,1};
                    set<int> components;
                    for(int k=0; k<4; k++){
                        int ndx = i + dirX[k];
                        int ndy = j + dirY[k];
                        if(ndx >= 0 && ndx < n && ndy >= 0 && ndy < n && grid[ndx][ndy] == 1){
                            int node = ndx * n + ndy;
                            components.insert(ds.findUltimateParent(node));
                        }
                    }
                    int currSize = 0;
                    for(int c : components){
                        currSize += ds.size[c];
                    }
                    ans = max(ans, currSize+1);
                }
            }
        }
        for(int i=0; i<n*n; i++){
            ans = max(ans, ds.size[ds.findUltimateParent(i)]);
        }
        return ans;
    }
};