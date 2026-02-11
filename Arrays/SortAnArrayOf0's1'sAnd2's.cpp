#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void sort012(vector<int>& arr) {
        // code here
        // First way
        // int n = arr.size();
        // int zerosCount = 0, onesCount = 0, twosCount = 0;
        // for(int i=0; i<n; i++){
        //     if(arr[i] == 0){
        //         zerosCount++;
        //     }
        //     else if(arr[i] == 1){
        //         onesCount++;
        //     }
        //     else{
        //         twosCount++;
        //     }
        // }
        // int idx = 0;
        // while(idx < zerosCount){
        //     arr[idx++] = 0;
        // }
        // while(idx - zerosCount < onesCount){
        //     arr[idx++] = 1;
        // }
        // while((idx - zerosCount - onesCount) < twosCount){
        //     arr[idx++] = 2;
        // }
        
        // Optimal way (One Pass)
        int n = arr.size();
        int low = 0, mid = 0, high = n-1;
        while(mid <= high){
            if(arr[mid] == 0){
                swap(arr[mid], arr[low]);
                low++;
                mid++;
            }
            else if(arr[mid] == 1){
                mid++;
            }
            else{
                swap(arr[mid], arr[high]);
                high--;
            }
        }
    }
};