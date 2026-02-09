#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> rotateArray(vector<int>arr, int k) {
        // Write your code here.
        int length = arr.size();
        k %= length;
        for(int i=0; i<k; i++){
            int first = arr[0];
            for(int i=1; i<length; i++){
                arr[i-1] = arr[i];
            }
            arr[length-1] = first;
        }
        return arr;
    }
};