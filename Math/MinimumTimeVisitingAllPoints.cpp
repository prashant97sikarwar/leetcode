//Problem Link:- https://leetcode.com/problems/minimum-time-visiting-all-points/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minTimeToVisitAllPoints(vector<vector<int>>& points) {
        int n = points.size();
        int xs = points[0][0], ys = points[0][1];
        int res = 0;
        for(int i=0;i<n;i++){
            int xi = points[i][0];
            int yi = points[i][1];
            
            int dx = abs(xi - xs);
            int dy = abs(yi - ys);
            
            res += min(dx,dy);
            res += max(dx,dy) - min(dx,dy);
            
            xs = xi;
            ys = yi;
        }
        return res;
    }
};