#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int floorSqrt(int n) {
        // code here
        int l = 1, h = n;
        while(l <= h){
            int mid = (l + h) / 2;
            if(mid * mid == n){
                return mid;
            }
            if(mid*mid < n){
                l = mid + 1;
            }
            else{
                h = mid - 1;
            }
        }
        return h;
    }
};