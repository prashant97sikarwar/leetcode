//problem Link:- https://leetcode.com/problems/subarray-sum-equals-k/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int sm = 0;
        map<int,int> mp;
        mp[0] = 1;
        int res = 0;
        for(int i=0;i<nums.size();i++){
            sm += nums[i];
            if (mp.find(sm-k) != mp.end()){
                res += mp[sm-k];
            }
            mp[sm]++;
        }
        return res;
    }
};