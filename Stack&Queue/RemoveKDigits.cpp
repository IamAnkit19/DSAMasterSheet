#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.length();
        stack<char> st;
        string ans = "";
        for(int i=0; i<n; i++){
            while(!st.empty() && k && st.top() > num[i]){
                st.pop();
                k--;
            }
            st.push(num[i]);
        }
        while(k){
            st.pop();
            k--;
        }
        if(st.empty()){
            return "0";
        }
        while(!st.empty()){
            ans += st.top();
            st.pop();
        }
        while(ans.size() && ans.back() == '0'){
            ans.pop_back();
        }
        reverse(ans.begin(), ans.end());
        return ans.size() ? ans : "0";
    }
};