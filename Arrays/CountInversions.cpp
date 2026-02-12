#include<bits/stdc++.h>
using namespace std;

// Interview Note: I am altering the data(array). If you don't want me to alter the data, then we can create a copy of the array then perform these operations.
class Solution {
    int merge(vector<int> &arr, int l, int mid, int h){
        int i = l, j = mid + 1;
        vector<int> temp;
        int count = 0;
        while(i <= mid && j <= h){
            if(arr[i] <= arr[j]){
                temp.push_back(arr[i]);
                i++;
            }
            else{
                temp.push_back(arr[j]);
                count += (mid - i + 1);
                j++;
            }
        }
        while(i <= mid){
            temp.push_back(arr[i]);
            i++;
        }
        while(j <= h){
            temp.push_back(arr[j]);
            j++;
        }
        for(i=l; i<=h; i++){
            arr[i] = temp[i-l];
        }
        return count;
    }
    int mergeSort(vector<int> &arr, int l, int h){
        int count = 0;
        if(l >= h){
            return count;
        }
        int mid = (l + h) / 2;
        count += mergeSort(arr, l, mid);
        count += mergeSort(arr, mid+1, h);
        count += merge(arr, l, mid, h);
        return count;
    }
  public:
    int inversionCount(vector<int> &arr) {
        // Code Here
        int n = arr.size();
        return mergeSort(arr, 0, n-1);
    }
};