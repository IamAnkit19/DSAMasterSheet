#include<bits/stdc++.h>
using namespace std;

class Solution {
    bool isPossible(vector<int> &stalls, int mid, int k){
        int countCows = 1, last = stalls[0];
        for(int i=1; i<stalls.size(); i++){
            if(stalls[i] - last >= mid){
                countCows++;
                last = stalls[i];
            }
            if(countCows >= k) return true;
        }
        return false;
    }
  public:
    int aggressiveCows(vector<int> &stalls, int k) {
        // code here
        int n = stalls.size();
        sort(stalls.begin(), stalls.end());
        int l = 1, h = stalls[n-1] - stalls[0];
        while(l <= h){
            int mid = (l + h) / 2;
            if(isPossible(stalls, mid, k)){
                l = mid + 1;
            }
            else{
                h = mid - 1;
            }
        }
        return h;
    }
};