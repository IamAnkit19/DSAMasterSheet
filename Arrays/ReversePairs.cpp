#include<bits/stdc++.h>
using namespace std;

// Interview Note: I am altering the data(array). If you don't want me to alter the data, then we can create a copy of the array then perform these operations.
class Solution {
    int count = 0;
    void merge(vector<int> &nums, int low, int mid, int high){
        vector<int> temp;
        int i = low, j = mid+1;
        while(i <= mid && j <= high){
            if(nums[i] <= nums[j]){
                temp.push_back(nums[i]);
                i++;
            }
            else{
                temp.push_back(nums[j]);
                j++;
            }
        }
        while(i <= mid){
            temp.push_back(nums[i]);
            i++;
        }
        while(j <= high){
            temp.push_back(nums[j]);
            j++;
        }
        for(int k=low; k<=high; k++){
            nums[k] = temp[k - low];
        }
    }
    void countPairs(vector<int> &nums, int low, int mid, int high){
        int right = mid + 1;
        for(int i=low; i<=mid; i++){
            while(right <= high && nums[i] > (2LL * nums[right])) right++;
            count += (right - (mid + 1));
        }
    }
    void mergeSort(vector<int> &nums, int low, int high){
        if(low >= high) return;
        int mid = (low + high) / 2;
        mergeSort(nums, low, mid);
        mergeSort(nums, mid+1, high);
        countPairs(nums, low, mid, high);
        merge(nums, low, mid, high);
    }
public:
    int reversePairs(vector<int>& nums) {
        // Optimal
        int n = nums.size();
        mergeSort(nums, 0, n-1);
        return count;
        // Brute Force
        // int n = nums.size();
        // int count = 0;
        // for(int i=0; i<n; i++){
        //     for(int j=i+1; j<n; j++){
        //         if(nums[i] > (2LL * nums[j])){
        //             count++;
        //         }
        //     }
        // }
        // return count;
    }
};