#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    // I
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;
        stack<int> st;
        unordered_map<int, int> map;
        for(int i=0; i<nums2.size(); i++){
            if(st.empty() || st.top() > nums2[i]){
                st.push(nums2[i]);
            }
            else{
                while(!st.empty() && st.top() < nums2[i]){
                    map[st.top()] = nums2[i];
                    st.pop();
                }
                st.push(nums2[i]);
            }
        }
        while(!st.empty()){
            map[st.top()] = -1;
            st.pop();
        }
        for(int i=0; i<nums1.size(); i++){
            ans.push_back(map[nums1[i]]);
        }
        return ans;
    }
    // II
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, -1);
        stack<int> st;
        for(int i=0; i<2*n; i++){
            int num = nums[i%n];
            if(st.empty() || nums[st.top()] > num){
                st.push(i%n);
            }
            else{
                while(!st.empty() && nums[st.top()] < num){
                    ans[st.top()] = num;
                    st.pop();
                }
                st.push(i%n);
            }
        }
        return ans;
    }
};