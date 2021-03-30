//Problem Link:- https://leetcode.com/problems/total-hamming-distance/

/* The Hamming distance between two integers is the number of positions at which the 
corresponding bits are different.Now your job is to find the total Hamming distance between 
all pairs of the given numbers. */

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int totalHammingDistance(vector<int>& nums) {
        int ans = 0;
        for(int b=0;b<31;b++){
            int mask = (1 << b);
            int ones = 0;
            int zeros = 0;
            for(int i=0;i<nums.size();i++){
                if (nums[i] & (1 << b))
                    ones++;
                else
                    zeros++;
            }
            ans += (ones*zeros);
        }
        return ans;
    }
};