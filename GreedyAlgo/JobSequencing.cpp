#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
        // code here
        // Not Optimezed(Gives TLE). But for now keep it as it is.
        vector<pair<int, int>> jobs;
        int maxTime = 0, n = deadline.size();
        for(int i=0; i<n; i++){
            maxTime = max(maxTime, deadline[i]);
            pair<int, int> job;
            job.first = profit[i];
            job.second = deadline[i];
            jobs.push_back(job);
        }
        sort(jobs.begin(), jobs.end(), greater<pair<int, int>>());
        int maxJobs = 0, maxProfit = 0;
        vector<int> slot(maxTime+1, -1);
        for(pair<int, int> &p : jobs){
            for(int i=p.second; i>0; i--){
                if(slot[i] == -1){
                    slot[i] = p.first;
                    maxJobs++;
                    maxProfit += p.first;
                    break;
                }
            }
        }
        return {maxJobs, maxProfit};
    }
};