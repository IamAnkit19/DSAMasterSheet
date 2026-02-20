#include<bits/stdc++.h>
using namespace std;

class Solution {
    // Recursion
    double solve(double x, long long n){
        if(n <= 0){
            return 1.0;
        }
        // return x * solve(x, n-1); # Stack Overflow
        double half = solve(x, n/2);
        if(n % 2 == 0){
            return half * half;
        }
        else{
            return half * half * x;
        }
    }
public:
    double myPow(double x, int n) {
        // Recursion
        long long N = n;
        if(N < 0){
            N = -N;
            return 1 / solve(x, N);
        }
        return solve(x, N);

        // long long N = n; // convert to long long to avoid overflow
        // if (N < 0) {
        //     x = 1 / x;
        //     N = -N;
        // }
        // double result = 1.0;
        // while (N > 0) {
        //     if (N % 2 == 1) {
        //         result *= x;
        //     }
        //     x *= x;
        //     N /= 2;
        // }
        // return result;

        // double ans = 1.0;
        // if(x == 1){
        //     return 1.0;
        // }
        // if(n >= 0){
        //     for(int i=0; i<n; i++){
        //         ans *= x;
        //     }
        //     return ans;
        // }
        // else{
        //     for(int i=0; i>n; i--){
        //         ans *= x;
        //     }
        //     return 1 / ans;
        // }
    }
};