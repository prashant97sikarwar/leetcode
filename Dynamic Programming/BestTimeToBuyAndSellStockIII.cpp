//Problem Link:- https://leetcode.com/problems/best-time-to-buy-and-sell-stock-iii/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& nums) {
        int n = nums.size();
        vector<int> dpleft(n,0);
        vector<int> dpright(n,0);
        int mn = nums[0];
        for(int i=1;i<n;i++){
            if (nums[i] < mn){
                mn = nums[i];
            }
            dpleft[i] = max(nums[i]-mn,dpleft[i-1]);
        }
        
        int mx = nums[n-1];
        for(int i=n-2;i>=0;i--){
            if (nums[i] > mx){
                mx = nums[i];
            }
            dpright[i] = max(dpright[i+1],mx - nums[i]);
        }
        int res = 0;
        for(int i=0;i<n;i++){
            res = max(res,dpleft[i] + dpright[i]);
        }
        return res;
    }
};