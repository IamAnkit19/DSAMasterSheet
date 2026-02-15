#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int nthRoot(int n, int m) {
        // Code here
        int l = 1, h = m;
        while(l <= h){
            int mid = (l + h) / 2;
            int temp = 1;
            for(int i=0; i<n; i++){
                temp *= mid;
                if(temp > m){
                    break;
                }
            }
            if(temp == m){
                return mid;
            }
            else if(temp < m){
                l = mid + 1;
            }
            else{
                h = mid - 1;
            }
        }
        int temp = 1;
        for(int i=0; i<n; i++){
            temp *= h;
            if(temp > m){
                break;
            }
        }
        if(temp == m) return temp;
        return -1;
    }
};