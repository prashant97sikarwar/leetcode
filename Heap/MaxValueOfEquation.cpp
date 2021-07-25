//Problem Link:- https://leetcode.com/problems/max-value-of-equation/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMaxValueOfEquation(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,int>> pq;
        int n = points.size(), res = INT_MIN;
        pq.push({points[0][1] - points[0][0], points[0][0]});
        for(int i=1;i<n;i++){
            int sm = points[i][1] + points[i][0];
            while (!pq.empty() && points[i][0] - pq.top().second > k){
                pq.pop();
            }
            if (!pq.empty()){
                res = max(res,sm + pq.top().first);
            }
            pq.push({points[i][1] - points[i][0],points[i][0]});
        }
        return res;
    }
};