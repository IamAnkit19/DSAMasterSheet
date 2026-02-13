#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    long subarrayXor(vector<int> &arr, int k) {
        // code here
        long long xr = 0;
        map<long long, int> map;
        map[xr]++;
        long long count = 0;
        for(int i=0; i<arr.size(); i++){
            xr ^= arr[i];
            long long x = xr ^ k;
            count += map[x];
            map[xr]++;
        }
        return count;
    }
};