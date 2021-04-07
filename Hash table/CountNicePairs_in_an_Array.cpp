//Problem Link:- https://leetcode.com/problems/count-nice-pairs-in-an-array/

/*You are given an array nums that consists of non-negative integers. Let us define rev(x) as 
the reverse of the non-negative integer xA pair of indices (i, j) is nice if it satisfies all 
of the following conditions:
1.0 <= i < j < nums.length
2.nums[i] + rev(nums[j]) == nums[j] + rev(nums[i])
Return the number of nice pairs of indices. Since that number can be too large, return it 
modulo 109 + 7. */

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int reverse(int num){
        int rev = 0;
        while (num > 0){
            int rem = num % 10;
            rev = 10*rev + rem;
            num /= 10;
        }
        return rev;
    }
    unordered_map<int,int> ump;
    int countNicePairs(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            int check = nums[i] - reverse(nums[i]);
            ump[check]++;
        }
        int res = 0;
        int MOD = 1e9 + 7;
        for(auto cur : ump){
            long long fr = cur.second % MOD;
            long long sec = (cur.second-1) % MOD;
            res += ((fr*sec)/2)%MOD;
            res %= MOD;
        }
        return res % MOD;
    }
};