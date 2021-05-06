//Problem Link:- https://leetcode.com/problems/max-consecutive-ones/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int sz = -1,cnt = 0,n = nums.size(), left = 0;
        for(int i=0;i<n;i++){
            if (nums[i] == 0){
                cnt++;
            }
            while(left < n && cnt > 0){
                if (nums[left] == 0){
                    cnt--;
                }
                left++;
            }
            sz = max(sz,i-left+1);
        }
        return sz;
    }
};