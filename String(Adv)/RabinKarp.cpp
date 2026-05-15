#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> search(string &pat, string &txt) {
        // code here
        // Not Optimized
        // int m = pat.size(), n = txt.size();
        // vector<int> ans;
        // for(int i=0; i<n; i++){
        //     if(txt[i] == pat[0]){
        //         int idx = i;
        //         while(idx < n && idx-i < m){
        //             if(txt[idx] != pat[idx-i]){
        //                 break;
        //             }
        //             idx++;
        //         }
        //         if(idx-i == m){
        //             ans.push_back(i);
        //         }
        //     }
        // }
        // return ans;
        
        // Optimized
        long long d = 31, q = 1000000007, m = pat.length(), n = txt.length(), p = 0, t = 0, h = 1;
        vector<int> ans;
        for(int i=0; i<m-1; i++){
            h = (h * d) % q;
        }
        for(int i=0; i<m; i++){
            p = (d * p + pat[i]) % q;
            t = (d * t + txt[i]) % q;
        }
        for(int i=0; i<=n-m; i++){
            if(p == t){
                // bool match = true;
                // for(int j=0; j<m; j++){
                //     if(pat[j] != txt[i+j]){
                //         match = false;
                //         break;
                //     }
                // }
                // if(match){
                // }
                ans.push_back(i);
            }
            if(i < n-m){
                t = (d * (t - txt[i] * h) + txt[i+m]) % q;
                if(t < 0){
                    t += q;
                }
            }
        }
        return ans;
    }
};