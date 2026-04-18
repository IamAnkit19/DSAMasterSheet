#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1);
        for(int i=0; i<n; i++){
            if(color[i] == -1){
                color[i] = 0;
                queue<int> q;
                q.push(i);
                while(!q.empty()){
                    int node = q.front();
                    q.pop();
                    for(int j=0; j<graph[node].size(); j++){
                        if(color[graph[node][j]] == -1){
                            color[node] == 0 ? color[graph[node][j]] = 1 : color[graph[node][j]] = 0;
                            q.push(graph[node][j]);
                        }
                        else if(color[graph[node][j]] == color[node]){
                            return false;
                        }
                    }
                }
            }
        }
        return true;
    }
};