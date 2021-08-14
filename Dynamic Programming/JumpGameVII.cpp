//Problem Link:- https://leetcode.com/problems/jump-game-vii/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        const int n = s.length();
        queue<int> pq;
        pq.push(0);
        if (s[n-1] != '0'){
            return false;
        }
        vector<int> dp(n,0);
        dp[0] = 1;
        for(int i=1;i<n;i++){
            if (s[i] == '1'){
                continue;
            }
            int diff = 0;
            while (!pq.empty()){
                diff = i - pq.front();
                if (diff <= maxJump){
                    break;
                }
                pq.pop();
            }
            if (!pq.empty() && diff >= minJump){
                dp[i] = 1;
                pq.push(i);
            }
        }
        return dp[n-1];
    }
};