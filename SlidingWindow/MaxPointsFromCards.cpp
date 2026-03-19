#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int totalSum = 0;
        for(int i=0; i<n; i++){
            totalSum += cardPoints[i];
        }
        int windowSize = n - k;
        int windowSum = 0;
        for(int i=0; i<windowSize; i++){
            windowSum += cardPoints[i];
        }
        int ans = windowSum;
        for(int i=windowSize; i<n; i++){
            windowSum -= cardPoints[i-windowSize];
            windowSum += cardPoints[i];
            ans = min(ans, windowSum);
        }
        return totalSum - ans;
    }
};