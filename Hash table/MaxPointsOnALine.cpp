//Problem Link:- https://leetcode.com/problems/max-points-on-a-line/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    float slope(int x1, int x2,int y1,int y2){
        float ans;
        if ((x2 - x1) == 0){
            ans = 1000001;
            return ans;
        }
        float m = (float)(y2 - y1) / (x2 - x1);
        return m;
    }
    
    float intercept(int x1,int y1,float m){
        return -m*x1 + y1;
    }
    
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();
        if (n <= 2){
            return n;
        }
        map<pair<float,float>,set<pair<int,int>>> ump;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                int x1 = points[i][0];
                int x2 = points[j][0];
                int y1 = points[i][1];
                int y2 = points[j][1];
                float m = slope(x1,x2,y1,y2);
                float c = intercept(x1,y1,m);
                ump[{m,c}].insert({x1,y1});
                ump[{m,c}].insert({x2,y2});
            }
        }
        int mx = -1;
        for(auto it = ump.begin();it != ump.end();it++){
            auto lst = it->second;
            int sz = lst.size();
            if (sz > mx){
                mx = sz;
            }
        }
        return mx;
    }
};