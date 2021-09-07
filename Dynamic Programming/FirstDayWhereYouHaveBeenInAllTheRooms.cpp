//Problem link:- https://leetcode.com/problems/first-day-where-you-have-been-in-all-the-rooms/

#include<bits/stdc++.h>
using namespace std;

class Solution {
    private:
    long long dp[100007];
    const long long mod = 1e9 + 7;
public:
    int firstDayBeenInAllRooms(vector<int>& nextVisit) {
        const int len = nextVisit.size();
        
        for(int i=1;i<len;i++){
            dp[i] = (2*1LL + 2*dp[i-1]%mod - dp[nextVisit[i-1]] + mod)%mod;
            dp[i] %= mod;
        }
        return dp[len-1]%mod;
    }
};