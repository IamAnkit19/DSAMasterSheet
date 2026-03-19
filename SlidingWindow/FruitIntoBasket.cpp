#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int totalFruit(vector<int>& fruits) {
        int n = fruits.size();
        int l = 0, r = 0, maxFruits = 0, trees = 0, firstTree = -1, secondTree = -1, first = 0, second = 0;
        while(r < n){
            if(fruits[r] == firstTree){
                first++;
            }
            else if(fruits[r] == secondTree){
                second++;
            }
            else{
                while(first && second){
                    if(fruits[l] == firstTree){
                        first--;
                    }
                    else{
                        second--;
                    }
                    l++;
                }
                if(!first){
                    firstTree = fruits[r];
                    first++;
                }
                else{
                    secondTree = fruits[r];
                    second++;
                }
            }
            maxFruits = max(maxFruits, r - l + 1);
            r++;
        }
        return maxFruits;
    }
};