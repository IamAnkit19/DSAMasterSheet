#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int orgColor = image[sr][sc];
        if(orgColor == color){
            return image;
        }
        int m = image.size();
        int n = image[0].size();
        queue<pair<int, int>> q;
        q.push({sr, sc});
        while(!q.empty()){
            pair<int, int> p = q.front();
            q.pop();
            int x = p.first, y = p.second;
            image[x][y] = color;
            if(x > 0 && image[x-1][y] == orgColor){
                q.push({x-1, y});
            }
            if(y > 0 && image[x][y-1] == orgColor){
                q.push({x, y-1});
            }
            if(x < m-1 && image[x+1][y] == orgColor){
                q.push({x+1, y});
            }
            if(y < n-1 && image[x][y+1] == orgColor){
                q.push({x, y+1});
            }
        }
        return image;
    }
};