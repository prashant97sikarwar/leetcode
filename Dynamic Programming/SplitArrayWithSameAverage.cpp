//Problem Link:- https://leetcode.com/problems/split-array-with-same-average/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:       
    bool splitArraySameAverage(vector<int>& nums){
        int n = nums.size(), sum = accumulate(nums.begin(), nums.end(), 0);
        
        vector<int> dp(sum + 1);
        dp[0] = 1;
        for(int num: nums) {
            for(int s = sum; s >= num; s--) {
                if(dp[s - num])
                    dp[s] |= (dp[s - num] << 1);
            }
        }
        
        for(int len = 1; len < n; len++) {
            if((sum*len) % n == 0){
                int s = sum*len/n;
                if(dp[s] && (dp[s] & (1 << len)))
                   return true;                    
                
            }
        }
        return false;
    }
};