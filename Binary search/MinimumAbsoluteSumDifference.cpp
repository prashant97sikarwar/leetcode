//Problem Link:- https://leetcode.com/problems/minimum-absolute-sum-difference/

/*You are given two positive integer arrays nums1 and nums2, both of length n.The absolute 
sum difference of arrays nums1 and nums2 is defined as the sum of |nums1[i] - nums2[i]| for 
each 0 <= i < n (0-indexed).You can replace at most one element of nums1 with any other 
element in nums1 to minimize the absolute sum difference.Return the minimum absolute sum 
difference after replacing at most one element in the array nums1. Since the answer may be 
large, return it modulo 109 + 7. */

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2) {
        int diff = 0;
        int n = nums1.size();
        int MOD = 1e9 + 7;
        vector<int> prefix(n,0);
        for(int i=0;i<n;i++){
            prefix[i] = abs(nums1[i] - nums2[i]);
            diff += abs(nums1[i] - nums2[i]);
            diff %= MOD;
        }
        sort(nums1.begin(),nums1.end());
        int res = INT_MAX;
        for(int i=0;i<n;i++){
            auto it1 = lower_bound(nums1.begin(),nums1.end(),nums2[i]);
            vector<int>::iterator it2 = it1;
            if (it1 > nums1.begin()){
                it2 = it1-1;
            }
            int f = abs(*(it1) - nums2[i]);
            int s = abs(*(it2) - nums2[i]);
            int d = min(f,s);
            int p = min(d,prefix[i]);
            res = min(res,(diff-prefix[i]+p)%MOD);
        }
        return res%MOD;
    }
};