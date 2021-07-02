//Problem Link:- https://leetcode.com/problems/binary-subarrays-with-sum/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int res = 0,sm = 0;
        unordered_map<int,int> mp;
        mp[0] = 1;
        for(int i=0;i<nums.size();i++){
            sm += nums[i];
            if (mp.find(sm-goal) != mp.end()){
                res += mp[sm-goal];
            }
            mp[sm]++;
        }
        return res;
    }
};