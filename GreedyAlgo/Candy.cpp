#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
        // Optimized
        int n = ratings.size();
        int sum = 1, i = 1;
        while(i < n){
            if(ratings[i] == ratings[i-1]){
                sum++;
                i++;
                continue;
            }
            int peak = 1;
            while(i < n && ratings[i] > ratings[i-1]){
                peak++;
                sum += peak;
                i++;
            }
            int down = 1;
            while(i < n && ratings[i] < ratings[i-1]){
                sum += down;
                down++;
                i++;
            }
            if(down > peak){
                sum += (down - peak);
            }
        }
        return sum;

        // Brute Force
        // int n = ratings.size();
        // vector<int> left(n), right(n);
        // int ans = 0;
        // left[0] = 1, right[n-1] = 1;
        // for(int i=1; i<n; i++){
        //     if(ratings[i] > ratings[i-1]){
        //         left[i] = left[i-1] + 1;
        //     }
        //     else{
        //         left[i] = 1;
        //     }
        // }
        // for(int i=n-2; i>=0; i--){
        //     if(ratings[i] > ratings[i+1]){
        //         right[i] = right[i+1] + 1;
        //     }
        //     else{
        //         right[i] = 1;
        //     }
        // }
        // for(int i=0; i<n; i++){
        //     ans += max(left[i], right[i]);
        // }
        // return ans;
    }
};