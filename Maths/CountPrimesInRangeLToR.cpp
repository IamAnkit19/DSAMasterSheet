#include<bits/stdc++.h>
using namespace std;

// User function Template for C++
class Solution {
  public:
    int countPrimes(int L, int R) {
        // code here
        vector<int> primes(R+1, 1);
        primes[0] = primes[1] = 0;
        for(int i=2; i*i<=R; i++){
            if(primes[i]){
                for(int j=i*i; j<=R; j+=i){
                    primes[j] = 0;
                }
            }
        }
        int count = 0;
        for(int i=L; i<=R; i++){
            if(primes[i]){
                count++;
            }
        }
        return count;
    }
};