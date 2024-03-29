//Problem link:- https://leetcode.com/problems/candy/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int candy(vector<int>& nums) {
        int n = nums.size();
        vector<int> left(n,1);
        vector<int> right(n,1);
        for(int i=1;i<n;i++){
            if (nums[i] > nums[i-1]){
                left[i] = left[i-1] + 1;
            }
        }
        for(int i=n-2;i>=0;i--){
            if (nums[i] > nums[i+1]){
                right[i] = 1 + right[i+1];
            }
        }
        int res = 0;
        for(int i=0;i<n;i++){
            res += max(left[i],right[i]);
        }
        return res;
    }
};