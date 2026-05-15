#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        string ans = "";
        int n = s.length();
        int i = 0;
        while(i < n){
            while(i < n && s[i] == ' '){
                i++;
            }
            string temp = "";
            while(i < n && s[i] != ' '){
                temp += s[i];
                i++;
            }
            if(temp != ""){
                if(ans == ""){
                    ans = temp;
                }
                else{
                    ans = temp + " " + ans;
                }
            }
            i++;
        }
        return ans;
    }
};