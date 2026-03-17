#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    static bool basis(pair<int, int> a, pair<int, int> b){
        if(a.second == b.second){
            return a.first < b.first;
        }
        return a.second < b.second;
    }
    // Function to find the maximum number of meetings that can
    // be performed in a meeting room.
    int maxMeetings(vector<int>& start, vector<int>& end) {
        // Your code here
        vector<pair<int, int>> meetings;
        for(int i=0; i<end.size(); i++){
            meetings.push_back({start[i], end[i]});
        }
        sort(meetings.begin(), meetings.end(), basis);
        int totalMeetings = 1, lastMeeting = 0;
        for(int i=1; i<meetings.size(); i++){
            if(meetings[lastMeeting].second < meetings[i].first){
                totalMeetings++;
                lastMeeting = i;
            }   
        }
        return totalMeetings;
    }
};