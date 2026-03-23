#include<bits/stdc++.h>
using namespace std;

class Solution {
    int maxHistogram(vector<int> &matrix){
        int n = matrix.size();
        int maxArea = 0;
        stack<int> st;
        for(int i=0; i<n; i++){
            while(!st.empty() && matrix[st.top()] > matrix[i]){
                int idx = st.top();
                st.pop();
                int nse = i, pse = st.empty() ? -1 : st.top();
                maxArea = max(maxArea, matrix[idx]*(nse-pse-1));
            }
            st.push(i);
        }
        while(!st.empty()){
            int idx = st.top();
            st.pop();
            int nse = n, pse = st.empty() ? -1 : st.top();
            maxArea = max(maxArea, matrix[idx]*(nse-pse-1));
        }
        return maxArea;
    }
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> prefixSum(m, vector<int>(n, 0));
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(matrix[i][j] == '0'){
                    prefixSum[i][j] = 0;
                }
                else{
                    prefixSum[i][j] = (i > 0 ? prefixSum[i-1][j] + 1 : 1);
                }
            }
        }
        int maxArea = 0;
        for(int i=0; i<m; i++){
            maxArea = max(maxArea, maxHistogram(prefixSum[i]));
        }
        return maxArea;
    }
};