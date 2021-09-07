//Problem Link:- https://leetcode.com/problems/count-special-quadruplets/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countQuadruplets(vector<int>& nums) {
        const int len = nums.size();
        
        unordered_map<int,int> mp;
        mp[nums[len-1] - nums[len-2]] = 1;
        
        int totalQuad = 0;
        
        for(int i=len-3;i>=1;i--){
            for(int j=i-1;j>=0;j--){
                totalQuad += mp[nums[i] + nums[j]];
            }
            
            for(int j=len-1;j>=i;j--){
                mp[nums[j] - nums[i]]++;
            }
        }
        return totalQuad;
        
    }
};