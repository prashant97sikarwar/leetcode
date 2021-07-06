//Problem Link:- https://leetcode.com/problems/maximize-score-after-n-operations/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> dp;
    
    int setBit(int x, int i) {
        return x | (1 << i);
    } 
    
    int getBit(int x, int i) {
        return (x >> i) & 1;
    }
    
    int gcd(int a, int b) {
        if (b == 0) return a;
        return gcd(b, a % b);
    }
    
    void trace(int cnt, vector<int> & nums, int mask) {
        if (dp[mask]) return;
        for(int i = 0; i < nums.size(); i++)
            for(int j = i+1; j < nums.size(); j++)
                if (!getBit(mask, i) && !getBit(mask, j)) {
                    int newMask = setBit(setBit(mask, i), j);
                    trace(cnt+1, nums, newMask);
                    dp[mask] = max(dp[mask], dp[newMask] + cnt * gcd(nums[i], nums[j]));            
                } 
    }
    
    int maxScore(vector<int>& nums) {
        dp.assign(20000, 0);
        trace(1, nums, 0);
        return dp[0];
    }
};