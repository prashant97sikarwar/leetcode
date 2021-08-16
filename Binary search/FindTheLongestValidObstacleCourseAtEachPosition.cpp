//Problem Link:- https://leetcode.com/problems/find-the-longest-valid-obstacle-course-at-each-position/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> longestObstacleCourseAtEachPosition(vector<int>& nums) {
        const int n = nums.size();
        vector<int> result(n);
        vector<int> seq;
        result[0] = 1;
        seq.push_back(nums[0]);
        for(int i=1;i<n;i++){
            if (nums[i] >= seq.back()){
                seq.push_back(nums[i]);
                result[i] = seq.size();
            }
            else{
                int idx = upper_bound(seq.begin(),seq.end(),nums[i]) - seq.begin();
                seq[idx] = nums[i];
                result[i] = idx+1;
            }
        }
        return result;
    }
};