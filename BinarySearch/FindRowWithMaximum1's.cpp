#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int rowWithMax1s(vector<vector<int>> &matrix, int n, int m) {
        // Write Your Code Here
        int maxOnes = 0, idx = -1;
        for(int i=0; i<n; i++){
            int low = 0, high = m - 1;
            while(low <= high){
                int mid = (low + high) / 2;
                if(matrix[i][mid] == 1){
                    high = mid - 1;
                }
                else{
                    low = mid + 1;
                }
            }
            int count = m - low;
            if(count > maxOnes){
                maxOnes = count;
                idx = i;
            }
        }
        return idx;
    }
};