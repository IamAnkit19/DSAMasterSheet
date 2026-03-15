#include<bits/stdc++.h>
using namespace std;

class Solution {
    int countOnes(int num){
        int count = 0;
        while(num){
            count += (num & 1);
            num = num >> 1;
        }
        return count;
    }
public:
    int minBitFlips(int start, int goal) {
        int x = start ^ goal;
        return countOnes(x);
    }
};