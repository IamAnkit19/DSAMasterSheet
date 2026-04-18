#include<bits/stdc++.h>
using namespace std;

// User function Template for C++
class Solution {
  public:
    int minimumMultiplications(vector<int>& arr, int start, int end) {
        // code here
        const int MOD = 100000;
        if(end > MOD){
            return -1;
        }
        queue<int> q;
        vector<int> dist(MOD, INT_MAX);
        dist[start] = 0;
        q.push(start);
        while(!q.empty()){
            int num = q.front();
            q.pop();
            int steps = dist[num];
            if(num == end){
                return steps;
            }
            for(int i=0; i<arr.size(); i++){
                int n = (num * arr[i]) % MOD;
                if(steps+1 < dist[n]){
                    dist[n] = steps + 1;
                    q.push(n);
                }
            }
        }
        return -1;
    }
};