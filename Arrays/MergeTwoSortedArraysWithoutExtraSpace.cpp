#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void mergeArrays(vector<int>& a, vector<int>& b) {
        // code here
        int m = a.size(), n = b.size();
        int left = m - 1;
        int right = 0;
        while(left >= 0 && right < n){
            if(a[left] > b[right]){
                swap(a[left], b[right]);
            }
            else{
                break;
            }
            left--;
            right++;
        }
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
    }
};