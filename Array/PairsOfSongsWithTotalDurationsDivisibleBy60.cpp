//Problem Link:- https://leetcode.com/problems/pairs-of-songs-with-total-durations-divisible-by-60/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        int n = time.size(),res = 0;
        vector<int> vis(60,0);
        for(int i=0;i<n;i++){
            int md = time[i]%60;
            if (md == 0){
                if (vis[0] > 0){
                    res += vis[0];
                }
                vis[0]++;
            }
            else{
                int req = 60 - md;
                if (vis[req] > 0){
                    res += vis[req];
                }
                vis[md]++;
            }
        }
        return res;
    }
};