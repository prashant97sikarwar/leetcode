//Problem Link:- https://leetcode.com/problems/check-if-all-the-integers-in-a-range-are-covered/

#include<bits/stdc++.h>
using namespace std;

class Solution {
    private:
    int dp[55];
public:
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        memset(dp,0,sizeof(dp));
        for(auto arr : ranges){
            int x = arr[0];
            int y = arr[1];
            dp[x] += 1;
            dp[y+1] -= 1;
        }
        for(int i=2;i<=54;i++){
            dp[i] += dp[i-1];
        }
        for(int i=left;i<=right;i++){
            if (dp[i] < 1){
                return false;
            }
        }
        return true;
    }
};