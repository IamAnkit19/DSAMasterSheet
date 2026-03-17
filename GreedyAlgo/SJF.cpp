#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    long long solve(vector<int>& bt) {
        // code here
        sort(bt.begin(), bt.end());
        int waitingTime = 0, n = bt.size(), sum = 0;
        for(int i=1; i<n; i++){
            waitingTime += bt[i-1];
            sum += waitingTime;
        }
        return sum / n;
    }
};