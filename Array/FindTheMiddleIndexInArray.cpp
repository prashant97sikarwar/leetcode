//Problem Link:- https://leetcode.com/problems/find-the-middle-index-in-array/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        const int len = nums.size();
        vector<int> left(len,0);
        vector<int> right(len,0);
        
        left[0] = nums[0];
        right[len-1] = nums[len-1];
        
        for(int i=1;i<len;i++){
            left[i] = nums[i] + left[i-1];
        }
        for(int i=len-2;i>=0;i--){
            right[i] = nums[i] + right[i+1];
        }
        
        for(int i=0;i<len;i++){
            if (left[i] == right[i]){
                return i;
            }
        }
        return -1;
    }
};