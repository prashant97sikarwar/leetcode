//Problem Link:- https://leetcode.com/problems/k-closest-points-to-origin/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<double,int>,vector<pair<double,int>>,greater<pair<double,int>>> pq;
        for(int i=0;i<points.size();i++){
            int x = points[i][0];
            int y = points[i][1];
            int dist = x*x + y*y;
            double result = sqrt(dist);
            pq.push({result,i});
        }
        vector<vector<int>> result;
        for(int i=0;i<k;i++){
            int idx = pq.top().second;
            pq.pop();
            result.push_back(points[idx]);
        }
        return result;
    }
};