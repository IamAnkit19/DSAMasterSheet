#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int fivesCount = 0, tensCount = 0, twentysCount = 0;
        for(int i=0; i<bills.size(); i++){
            if(bills[i] == 5){
                fivesCount++;
            }
            else if(bills[i] == 10){
                if(fivesCount){
                    fivesCount--;
                    tensCount++;
                }
                else{
                    return false;
                }
            }
            else{
                if(tensCount && fivesCount){
                    tensCount--;
                    fivesCount--;
                    twentysCount++;
                }
                else if(fivesCount >= 3){
                    fivesCount -= 3;
                    twentysCount++;
                }
                else{
                    return false;
                }
            }
        }
        return true;
    }
};