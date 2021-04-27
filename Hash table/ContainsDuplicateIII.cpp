//Problem Link:- https://leetcode.com/problems/contains-duplicate-iii/

/*Given an integer array nums and two integers k and t, return true if there are two distinct 
indices i and j in the array such that abs(nums[i] - nums[j]) <= t and abs(i - j) <= k.*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        long long n = nums.size();
        multiset<long long> mp;
        for(int i=0;i<n;i++){
            long long x = (1LL)*nums[i] - (long long)t;
            long long y = (1LL)*nums[i] + (long long)t;
            auto it = mp.lower_bound(x);
            if (it != mp.end() && *it <= y){
                return true;
            }
            mp.insert(nums[i]);
            if (mp.size() > k){
                auto it = mp.find(nums[i-k]);
                mp.erase(it);
            }
        }
        return false;
    }
};