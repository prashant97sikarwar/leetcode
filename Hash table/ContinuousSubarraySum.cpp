//Problem link:- https://leetcode.com/problems/continuous-subarray-sum/

/*Given an integer array nums and an integer k, return true if nums has a continuous subarray 
of size at least two whose elements sum up to a multiple of k, or false otherwise. */

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        mp[0] = -1;
        int sm = 0;
        for(int i=0;i<nums.size();i++){
            sm += nums[i];
            sm %= k;
            if (mp.count(sm)){
                if (i-mp[sm] >= 2)
                    return true;
            }
            else{
                mp[sm] = i;
            }
        }
        return false;
    }
};