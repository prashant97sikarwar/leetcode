//Problem Link:- https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        const int n = points.size();
        sort(points.begin(),points.end());
        int minEnd = points[0][1];
        int cnt = 1;
        for(int i=1;i<n;i++){
            if (points[i][0] > minEnd){
                cnt++;
                minEnd = points[i][1];
            }
            else{
                minEnd = min(minEnd,points[i][1]);
            }
        }
        return cnt;
    }
};