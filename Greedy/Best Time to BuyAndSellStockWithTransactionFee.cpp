//Problem Link:- https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& nums, int fee) {
        int oss = 0;
        int obs = -nums[0];
        for(int i=1;i<nums.size();i++){
            if (oss - nums[i] > obs){
                obs = oss - nums[i];
            }
            if (obs + nums[i] - fee > oss){
                oss = obs + nums[i] - fee;
            }
        }
        return oss;
    }
};