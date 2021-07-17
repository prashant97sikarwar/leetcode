//Problem Link:- https://leetcode.com/problems/non-overlapping-intervals/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    static bool cmp(vector<int>&a,vector<int>&b){
        if (a[0] == b[0]){
            return a[1] < b[1];
        }
        return a[0] < b[0];
    }
    
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size(), res = 0;
        sort(intervals.begin(),intervals.end(),cmp);
        int high = intervals[0][1];
        for(int i=1;i<n;i++){
            if (intervals[i][0] >= high){
                high = intervals[i][1];
            }
            else{
                res++;
                high = min(high,intervals[i][1]);
            }
        }
        return res;
    }
};