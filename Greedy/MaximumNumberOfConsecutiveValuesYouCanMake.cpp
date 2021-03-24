//Problem Link:- https://leetcode.com/problems/maximum-number-of-consecutive-values-you-can-make/

/* You are given an integer array coins of length n which represents the n coins that you own. 
The value of the ith coin is coins[i]. You can make some value x if you can choose some of 
your n coins such that their values sum up to x.Return the maximum number of consecutive 
integer values that you can make with your coins starting from and including 0.Note that you 
may have multiple coins of the same value. */

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int getMaximumConsecutive(vector<int>& coins) {
        int n = coins.size();
        map<int,int> mp;
        for(int i=0;i<n;i++){
            mp[coins[i]]++;
        }
        int ans = 0;
        for(auto coin : mp){
            int x = coin.first * coin.second;
            if (ans+1 >= coin.first){
                ans += x;
            }
            else{
                break;
            }
        }
        return ans+1;
    }
};