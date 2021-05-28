//Problem Link:- https://leetcode.com/problems/distribute-candies/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int distributeCandies(vector<int>& nums) {
        set<int> s;
        for(int i=0;i<nums.size();i++){
            s.insert(nums[i]);
        }
        int sz = s.size();
        int n = nums.size();
        return min(n/2,sz);
    }
};