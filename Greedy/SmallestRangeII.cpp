//Problem Link:- https://leetcode.com/problems/smallest-range-ii/

/*Given an array A of integers, for each integer A[i] we need to choose either x = -K or x = K, 
and add x to A[i] (only once).After this process, we have some array B.Return the smallest 
possible difference between the maximum value of B and the minimum value of B.*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int smallestRangeII(vector<int>& nums, int k) {
        int n = nums.size();
        if (n==1){
            return 0;
        }
        sort(nums.begin(),nums.end());
        if (k == 0){
            return (nums[n-1] - nums[0]);
        }
        int res = INT_MAX;
        for(int i=0;i<n-1;i++){
            int mx = max(nums[i] + k,nums[n-1]-k);
            int mn = min(nums[0]+k,nums[i+1]-k);
            res = min(res,mx - mn);
        }
        res = min(res,nums[n-1]-nums[0]);
        return res;
    }
};