//Problem Link:- https://leetcode.com/problems/subarrays-with-k-different-integers/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int helper(vector<int>&nums,int k){
        int n = nums.size(),left = 0,res = 0;
        unordered_map<int,int> ump;
        for(int i=0;i<n;i++){
            ump[nums[i]]++;
            while (ump.size() > k && left < n){
                ump[nums[left]]--;
                if (ump[nums[left]] == 0){
                    ump.erase(nums[left]);
                }
                left++;
            }
            res += (i-left+1);
        }
        return res;
    }
    
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return helper(nums,k)-helper(nums,k-1);
    }
};