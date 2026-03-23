#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int leftMax = 0, rightMax = 0, ans = 0;
        int n = height.size(), l = 0, r = n - 1;
        while(l < r){
            if(height[l] <= height[r]){
                if(leftMax > height[l]){
                    ans += (leftMax - height[l]);
                }
                else{
                    leftMax = height[l];
                }
                l++;
            }
            else{
                if(rightMax > height[r]){
                    ans += (rightMax - height[r]);
                }
                else{
                    rightMax = height[r];
                }
                r--;
            }
        }
        return ans;
    }
};