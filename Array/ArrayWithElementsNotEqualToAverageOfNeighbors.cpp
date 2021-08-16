//Problem Link:= https://leetcode.com/problems/array-with-elements-not-equal-to-average-of-neighbors/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        const int n = nums.size();
        vector<int> result(n,-1);
        sort(nums.begin(),nums.end());
        int idx = n-1;
        for(int i=1;i<n;i+=2){
            if (result[i] == -1){
                result[i] = nums[idx--];   
            }
        }
        idx = 0;
        for(int i=0;i<n;i+=2){
            if (result[i] == -1){
                result[i] = nums[idx++];
            }
        }
        return result;
    }
};