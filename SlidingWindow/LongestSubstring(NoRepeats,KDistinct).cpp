#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    // No Repeats
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        vector<int> freq(256, -1);
        int l = 0, r = 0;
        int maxLength = 0, currLength = 0;
        while(r < n){
            if(freq[s[r]] != -1){
                while(s[l] != s[r]){
                    freq[s[l]] = -1;
                    l++;
                }
                l++;
            }
            else{
                freq[s[r]] = 1;
            }
            maxLength = max(maxLength, r - l + 1);
            r++;
        }
        return maxLength;
    }
    // K Distinct
    int longestKSubstr(string &s, int k) {
        // code here
        int n = s.size();
        vector<int> freq(256, 0);
        int l = 0, r = 0, maxLength = 0, distinctCount = 0;
        while(r < n){
            if(!freq[s[r]]){
                freq[s[r]]++;
                distinctCount++;
            }
            else{
                freq[s[r]]++;
            }
            if(distinctCount > k){
                while(true){
                    freq[s[l]]--;
                    if(!freq[s[l]]){
                        distinctCount--;
                        l++;
                        break;
                    }
                    l++;
                }
            }
            maxLength = max(maxLength, r-l+1);
            r++;
        }
        return distinctCount == k ? maxLength : -1;
    }
};