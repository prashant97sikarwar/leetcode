//Problem Link:- https://leetcode.com/problems/minimum-elements-to-add-to-form-a-given-sum/

/* You are given an integer array nums and two integers limit and goal. The array nums has an 
interesting property that abs(nums[i]) <= limit.Return the minimum number of elements you need to 
add to make the sum of the array equal to goal. The array must maintain its property that 
abs(nums[i]) <= limit. */ 

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minElements(vector<int>& nums, int limit, int goal) {
        long long int sm = 0;
        for(int i=0;i<nums.size();i++){
            sm += nums[i];
        }
        long long int diff = abs(goal - sm);
        if (diff == 0)
            return 0;
        return (diff % limit == 0) ? (diff / limit) : (diff / limit) + 1;
        
    }
};