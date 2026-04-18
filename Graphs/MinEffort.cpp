#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        priority_queue<pair<int,pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        dist[0][0] = 0;
        pq.push({0,{0,0}});
        int dirX[] = {-1, 0, 1, 0}, dirY[] = {0, -1, 0, 1};
        while(!pq.empty()){
            pair<int, pair<int, int>> p = pq.top();
            pq.pop();
            int d = p.first, x = p.second.first, y = p.second.second;
            if(x == m-1 && y == n-1){
                return d;
            }
            for(int i=0; i<4; i++){
                int dx = x + dirX[i], dy = y + dirY[i];
                if(dx >=0 && dx < m && dy >= 0 && dy < n){
                    int newEffort = max(abs(heights[x][y]-heights[dx][dy]), d);
                    if(newEffort < dist[dx][dy]){
                        dist[dx][dy] = newEffort;
                        pq.push({newEffort, {dx, dy}});
                    }
                }
            }
        }
        return 0;
    }
};