//Problem Link:- https://leetcode.com/problems/minimum-increment-to-make-array-unique/

#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        const int n = nums.size();
        sort(nums.begin(),nums.end());
        long long result = 0, prev = nums[0];
        long long total = accumulate(nums.begin(),nums.end(),1LL*0);
        long long sm = prev;
        for(int i=1;i<n;i++){
            if (nums[i] <= prev){
                prev = 1 + prev;
                sm += prev;
            }
            else{
                prev = nums[i];
                sm +=  nums[i];
            }
        }
        result = sm - total;
        return (int)result;
    }
};