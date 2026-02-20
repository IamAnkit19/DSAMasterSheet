#include<bits/stdc++.h>
using namespace std;

class Solution {
    bool isPossible(vector<int> &stations, double mid, int K){
        int requiredDistance = 0;
        for(int i=0; i<stations.size()-1; i++){
            double gap = stations[i+1] - stations[i];
            requiredDistance += (int)(gap/mid);
        }
        return requiredDistance <= K;
    }
  public:
    double minMaxDist(vector<int> &stations, int K) {
        // Code here
        double low = 0, high = 1e8;
        while(high-low > 1e-6){
            double mid = (low + high) / 2.0;
            if(isPossible(stations, mid, K)){
                high = mid;
            }
            else{
                low = mid;
            }
        }
        return low;
    }
};