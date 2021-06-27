//Problem Link:- https://leetcode.com/problems/maximum-number-of-events-that-can-be-attended/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        sort(events.begin(), events.end(), [](const vector<int> &a, const vector<int> &b) {
            return (a[1] == b[1]) ? a[0] < b[0] : a[1] < b[1];
        });
        
        vector<bool> seen(100001, false);
        int count = 0;
        int lastFound = 0;
        for(int i = 0; i < events.size(); i++) {
            int end = events[i][1];
            int start = (i > 0 && events[i-1][0] == events[i][0])? lastFound : events[i][0];
            for(int j = start; j <= end; j++){
                if(!seen[j]) {
                    seen[j] = true;
                    lastFound = j;
                    count++;
                    break;
                }
            }
            
        }
        return count;
    }
};