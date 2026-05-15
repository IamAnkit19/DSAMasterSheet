#include<bits/stdc++.h>
using namespace std;

class Solution{
    vector<int> primeNumbersTillN(int N){ 
        // Write your code here
        vector<int> primes(N+1, 1);
        vector<int> ans;
        for(int i=2; i*i<=N; i++){
            if(primes[i]){
                for(int j=i*i; j<=N; j+=i){
                    primes[j] = 0;
                }
            }
        }
        for(int i=2; i<=N; i++){
            if(primes[i]){
                ans.push_back(i);
            }
        }
        return ans;
    }
};