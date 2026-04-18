#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> cost(n, vector<int>(n, 1e8));
        for(int i=0; i<edges.size(); i++){
            cost[edges[i][0]][edges[i][1]] = edges[i][2];
            cost[edges[i][1]][edges[i][0]] = edges[i][2];
        }
        for(int k=0; k<n; k++){
            for(int i=0; i<n; i++){
                for(int j=0; j<n; j++){
                    if(cost[i][k] != 1e8 && cost[k][j] != 1e8){
                        cost[i][j] = min(cost[i][j], cost[i][k]+cost[k][j]);
                    }
                }
            }
        }
        int ans = 1e8;
        int city = -1;
        for(int i=0; i<n; i++){
            int count = 0;
            for(int j=0; j<n; j++){
                if(i == j) continue;
                if(cost[i][j] <= distanceThreshold){
                    count++;
                }
            }
            if(count <= ans){
                ans = count;
                city = i;
            }
        }
        return city;
    }
};