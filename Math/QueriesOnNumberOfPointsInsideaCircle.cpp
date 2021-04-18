//Problem Link:- https://leetcode.com/problems/queries-on-number-of-points-inside-a-circle/

/* You are given an array points where points[i] = [xi, yi] is the coordinates of the ith point on 
a 2D plane. Multiple points can have the same coordinates.You are also given an array queries where 
queries[j] = [xj, yj, rj] describes a circle centered at (xj, yj) with a radius of rj.For each query
queries[j], compute the number of points inside the jth circle. Points on the border of the circle 
are considered inside.Return an array answer, where answer[j] is the answer to the jth query. */

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    bool helper(int x,int y,int r,int cx,int cy){
        int temp = (x-cx)*(x-cx) + (y-cy)*(y-cy);
        if (temp <= (r*r)){
            return true;
        }
        return false;
    }
    
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
        vector<int> result;
        for(auto q:queries){
            int x = q[0];
            int y = q[1];
            int r = q[2];
            int cnt = 0;
            for(int i=0;i<points.size();i++){
                int px = points[i][0];
                int py = points[i][1];
                if (helper(px,py,r,x,y)){
                    cnt++;
                }
            }
            result.push_back(cnt);
        }
        return result;
    }
};