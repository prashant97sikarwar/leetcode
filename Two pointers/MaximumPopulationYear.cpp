//Problem Link:- https://leetcode.com/problems/maximum-population-year/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        sort(logs.begin(),logs.end());
        map<int,int> ump;
        for(int y=1950;y<=2050;y++){
            for(int i=0;i<logs.size();i++){
                if (y >= logs[i][0] && y <= logs[i][1]-1){
                    ump[y]++;
                }
            }
        }
        int mx = -1;
        int res = -1;
        for(auto x : ump){
            if (x.second > mx){
                res = x.first;
                mx = x.second;
            }
        }
        return res;
    }
};