#include<bits/stdc++.h>
using namespace std;

class Solution {
    int computeXOR(int x){
        if(x % 4 == 1){
            return 1;
        }
        else if(x % 4 == 2){
            return x + 1;
        }
        else if(x % 4 == 3){
            return 0;
        }
        else{
            return x;
        }
    }
  public:
    int findXOR(int l, int r) {
        // complete the function here
        // Brute Force
        // int ans = 0;
        // for(int i=l; i<=r; i++){
        //     ans ^= i;
        // }
        // return ans;
        
        // Optimal Approach
        int prev = computeXOR(l-1);
        int curr = computeXOR(r);
        return prev ^ curr;
    }
};